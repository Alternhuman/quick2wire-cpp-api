#include <gpio.hpp>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LEN 300
int gpio_admin(char * subcommand, int pin, char* pull){

	//int len = strlen(subcommand) + strlen(itoa(pin)) + 1;
	char command[MAX_LEN], buff[MAX_LEN];
	
	snprintf(command, MAX_LEN, "gpio-admin %s %d %s", subcommand, pin, pull == NULL ? "" : pull);

	FILE* f = popen(command, "r");

	return pclose(f);
}

int PinAPI::init(int bank, int index){
	bank = bank;
	index = index;
}

int PinAPI::getBank(){
	return this->bank;
}

void PinAPI::setBank(int value){
	this->bank = value;
}

int PinAPI::getIndex(){
	return this->index;
}

void PinAPI::setIndex(int value){
	this->index = value;
}


/*Pin class definitions*/

int Pin::init(int bank, int index, int soc_pin_number,char* direction, int interrupt, int pull){
	/*
	Creates a pin
	 Parameters:
    user_pin_number -- the identity of the pin used to create the derived class.
    soc_pin_number  -- the pin on the header to control, identified by the SoC pin number.
    direction       -- (optional) the direction of the pin, either In or Out.
    interrupt       -- (optional)
    pull            -- (optional)
    
    Raises:
    IOError        -- could not export the pin (if direction is given)
    
	*/

	PinAPI::init(bank, index);
	soc_pin_number = soc_pin_number;
	direction = direction;
	interrupt = interrupt;
	pull = pull;
}

int Pin::get_soc_pin_number(){
	return this->soc_pin_number;
}

int Pin::open(){
	gpio_admin("export", this->soc_pin_number, this->pull);
	if(NULL == (this->file = fopen(this->pin_path("value"), "r+"))){
		return 1;
	}
	
	this->write("direction", this->direction);

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
		gpio_admin("unexport", this->soc_pin_number);
	}
}

int Pin::getValue(){
	return this->get();
}

void Pin::setValue(int value){
	this->set(value);
}

int Pin::get(){
	/*"""The current value of the pin: 1 if the pin is high or 0 if the pin is low.
        
        The value can only be set if the pin's direction is Out.
        
        Raises: 
        IOError -- could not read or write the pin's value.
        """*/

    if(this->closed()){
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
		return -1;
	}
	if(strcmp(OUT, "out") != 0){
		return -2;
	}
	fseek(this->file, 0, SEEK_SET);
	char buff[20];
	snprintf(buff, 20, "%d", value);
	fputs(buff, this->file);
	fflush(this->file);
}

bool Pin::closed(){
	
	if(fseek(this->file, 0, SEEK_CUR) == -1){
		if(errno == EBADF){
			return true;
		}
	}

	return this->file == NULL;
	/*"""Returns if this pin is closed"""
        return self._file is None or self._file.closed
    */
}

/*Private methods*/

char* Pin::pin_path(char *filename){
	char *path = (char*)malloc(MAX_LEN * sizeof(char));

	snprintf(path, MAX_LEN, "/sys/devices/soc/3f200000.gpio/gpio/gpio%d/%s", this->soc_pin_number, filename);
	return path;
}

void Pin::write(char*filename, char* value){
	FILE *f = fopen(filename, "w+");
	fputs(value, f);
	fclose(f);
}

char *Pin::getDirection(){
	return this->direction;
}

void Pin::setDirection(char* direction){
	this->write("direction", direction);
	strncpy(this->direction, direction, 3);
}