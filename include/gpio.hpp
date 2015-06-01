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
	void init();
private:
	int pi_revision;
	PinBank *pins;	
};


class PinBank{
public:
	PinBank();
	Pin at(int index);
	int write();
	int read();
	Pin pin(int index);
	Pin init(int index);
	bool has_len();
	int length();

private:
	int index_to_soc(int index);
	int count;
	int by_revision(int v1, int v2);
	int pi_revision;
};

class Pin{

public:
	Pin();
	int init(PinBank *bank, int index, int soc_pin_number,char* direction=IN, int interrupt=0, int pull=0);
	int get_soc_pin_number();
	int enter();
	int exit();
	PinBank* getBank();
	void setBank(PinBank *);
	int getIndex();
	void setIndex(int value);
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
	int index;
	PinBank *bank;
};



#endif