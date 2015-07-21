#include "gpio.hpp"

#define MAX_LEN 300
int gpio_admin(char * subcommand, int pin, char* pull){

	char command[MAX_LEN];
	
	snprintf(command, MAX_LEN, "gpio-admin %s %d\n", subcommand, pin);//, pull == NULL ? "" : pull);
	FILE* f = popen(command, "r");
	
	return pclose(f);
}

/*Class GPIO*/

GPIO::GPIO(){
	pins = new PinBank();
	pi_revision = revision();
}

GPIO::~GPIO(){
	delete pins;
}

/*Class PinBank*/

PinBank::PinBank(){
	pi_revision = revision();
	if(pi_revision != 0){
		std::map<int, int> _pi_header_1_pins;

		_pi_header_1_pins[3] = by_revision(0, 2), 
		_pi_header_1_pins[5] = by_revision(1, 3), 
		_pi_header_1_pins[7] = 4; 
		_pi_header_1_pins[8] = 14; 
		_pi_header_1_pins[10] = 15; 
		_pi_header_1_pins[11] = 17; 
		_pi_header_1_pins[12] = 18; 
		_pi_header_1_pins[13] = by_revision(21, 27); 
		_pi_header_1_pins[15] = 22; 
		_pi_header_1_pins[16] = 23; 
		_pi_header_1_pins[18] = 24; 
		_pi_header_1_pins[19] = 10; 
		_pi_header_1_pins[21] = 9; 
		_pi_header_1_pins[22] = 25; 
		_pi_header_1_pins[23] = 11; 
		_pi_header_1_pins[24] = 8;
		_pi_header_1_pins[26] = 7;

		_pi_gpio_pins = (int*) malloc(sizeof(int) * 8);
		
		//int filter_pins[] = {11, 12, 13, 15, 16, 18, 22, 7};
		int filter_pins[] = {11, 13, 15, 19, 21, 23};
		for (unsigned int i = 0; i < sizeof(filter_pins)/sizeof(filter_pins[0]); i++)
		{
			_pi_gpio_pins[i] = _pi_header_1_pins[filter_pins[i]];
		}

		count = sizeof(filter_pins)/sizeof(filter_pins[0]);

	}else{
		perror("Warning. You are not using a Raspberry Pi!");
	}
}

Pin PinBank::at(int index){
	return this->pin(index);
}

Pin PinBank::pin(int index){
	Pin p = Pin(this, index, this->index_to_soc(index));
	return p;
}

bool PinBank::has_len(){
	return count > 0;
}

int PinBank::length(){
	return count;
}

int PinBank::index_to_soc(int index){
	return _pi_gpio_pins[index];
}

int PinBank::by_revision(int v1, int v2){
 	return pi_revision == 1 ? v1 : v2;
}

/*Pin class definitions*/

Pin::Pin(PinBank *bank, int index, int soc_pin_number,char* direction, int interrupt, int pull){

    this->bank = bank;
    this->index = index;
    this->soc_pin_number = soc_pin_number;
    strncpy(this->direction, direction, 3);
	/*this->interrupt = interrupt;
	this->pull = pull;*/
}

int Pin::open(){
 	gpio_admin("export", this->soc_pin_number, this->pull);
 	if(NULL == (this->file = fopen(this->pin_path("value"), "r+"))){
 		quick2wire_errno = PIN_ERR;
 		return 1;
	}
	
 	return this->write("direction", this->direction);

	/*if self._direction == In:
        self._write("edge", self._interrupt if self._interrupt is not None else "none")
    */
}

int Pin::close(){
	if(!this->closed()){
		if(strcmp(this->direction, OUT) == 0){
			this->setValue(0);
		}
		fclose(this->file);
		this->file = NULL;
		this->write("direction", IN);
		this->write("edge", "none");
		return gpio_admin("unexport", this->soc_pin_number);
	}
	return 0;
}

bool Pin::closed(){
	/*
		Returns true if the pin is closed
	*/
	if(this->file == NULL)
		return true;
	
	if(fseek(this->file, 0, SEEK_CUR) == -1){
		if(errno == EBADF){
			return true;
		}
	}

	return false;
}


int Pin::get_soc_pin_number(){
 	return this->soc_pin_number;
}


int Pin::getValue(){
	return this->get();
}

void Pin::setValue(int value){
	this->set(value);
}

int Pin::getIndex(){
	return this->index;
}

void Pin::setIndex(int value){
	this->index = value;
}

PinBank* Pin::getBank(){
	return this->bank;
}

void Pin::setBank(PinBank *value){
	this->bank = value;
}

char *Pin::getDirection(){
	return this->direction;
}

void Pin::setDirection(char* direction){

	this->write("direction", direction);
	strncpy(this->direction, direction, 3);
	return;
}


int Pin::get(){
 	/*
 	The current value of the pin: 1 if the pin is high or 0 if the pin is low.
        
    The value can only be set if the pin's direction is Out.
        
    Raises: 
    IOError -- could not read or write the pin's value.
    */

    if(this->closed()){
    	perror("The pin is closed");
    	return -1;
    }
    
    fseek(this->file, 0, SEEK_SET);
    
    char buff[10];
    if(NULL == fgets(buff, 10, this->file)){
    	return -1;
    }
    return atoi(buff);
}

int Pin::set(int value){
	
	if(this->closed()){
		perror("The device is closed");
		return -1;
	}
	if(strcmp(OUT, "out") != 0){
		perror("The direction is not \"out\"");
		return -2;
	}
	
	fseek(this->file, 0, SEEK_SET);
	
	char buff[3];
	snprintf(buff, 3, "%d", value);
	fputs(buff, this->file);
	fflush(this->file);
	
	return value;
}

int Pin::write(char*filename, char* value){
	/*
	Writes value in the file pointed by filename.
	The pin path is appended to filename.
	*/
	FILE *f = fopen(this->pin_path(filename), "w+");
	
	if(f == NULL){
		perror("Could not open the pin device");
		return 1;
	}

 	if(EOF == fputs(value, f)){
 		perror("Error during writing to pin device");
 		return 1;
 	}
 	
 	if(EOF == fclose(f)){
 		perror("Error during device closing");
 	}

	return 0;
}

// /*Private methods*/

char* Pin::pin_path(char *filename){
 	
 	char *path = (char*)malloc(MAX_LEN * sizeof(char));

 	if(path == NULL){
 		perror("Error in memory allocation");
 		return NULL;
 	}

 	snprintf(path, MAX_LEN, "/sys/class/gpio/gpio%d/%s", this->soc_pin_number, filename);
 	return path;
}

char *Pin::to_string(){
	return NULL;
}
