#include <stdlib.h>
#include <stdio.h>

#define OUT "out"
#define IN "in"

int gpio_admin(char * subcommand, int pin, char* pull=NULL);

class PinAPI{
public:
	PinAPI(int _bank, int _index);
	int init(int bank, int index);
	int enter();
	int exit();

	int getBank();
	void setBank(int value);
	int getIndex();
	void setIndex(int value);
	

private:
	int index;
	int bank;
};

class Pin : public PinAPI{

public:
	Pin();
	int init(int bank, int index, int soc_pin_number,char* direction=IN, int interrupt=0, int pull=0);
	int get_soc_pin_number();
	int open();
	int close();
	int get();
	int set(int value);
	int getValue();
	void setValue(int value);
	char* getDirection();
	void setDirection(char* direction);
	bool closed();
	/*interrupt, pull, fileno*/
private:
	bool check_open();
    void write(char* filename, char* value);
    char * pin_path(char *filename);
    char* to_string();
    FILE *file = NULL;
	int trigger;
	char* direction;
	int soc_pin_number;
	char * pull;
};