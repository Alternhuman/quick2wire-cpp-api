#ifndef _GPIO_HPP
#define _GPIO_HPP

#include <stdlib.h>
#include <stdio.h>
#include <exception>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#include <map>

#include "board_revision.hpp"

#define OUT "out"
#define IN "in"


int gpio_admin(char * subcommand, int pin, char* pull=NULL);

class PinBank;
class Pin;
class GPIO;

class GPIO{
public:
	GPIO();
	PinBank *pins;
	int pi_revision;
};


class PinBank{
public:
	PinBank();
	Pin at(int index);
	Pin pin(int index);
	//Pin init(int index);
	bool has_len();
	int length();

private:
	int index_to_soc(int index);	
	int by_revision(int v1, int v2);

	int count;
	int pi_revision;
	int *_pi_gpio_pins;
};

class Pin{

public:
	Pin(PinBank *bank, int index, int soc_pin_number,char* direction=IN, int interrupt=0, int pull=0);
	int open();
	int close();
	bool closed();

	int get_soc_pin_number();
	
	int getValue();
	void setValue(int value);
	
	int getIndex();
	void setIndex(int value);

	PinBank* getBank();
	void setBank(PinBank *);
	
	char* getDirection();
	void setDirection(char* direction);

	//int enter();
	//int exit();
	
	/*interrupt, pull, fileno*/
private:
	int get();
	int set(int value);
    int write(char* filename, char* value);
    char * pin_path(char *filename);
    char* to_string();
    
    FILE *file = NULL;
	int trigger;
	char direction[3];
	int soc_pin_number;
	char * pull;
	int index;
	PinBank *bank;
};

#endif
