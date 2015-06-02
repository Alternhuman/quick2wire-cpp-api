#include "board_revision.hpp"
#include "gpio.hpp"
#include <unistd.h>

int main(int argc, char* argv[]){

	GPIO g;
	Pin p = g.pins->at(3);
	p.open();
	p.setDirection(OUT);
	p.setValue(1);

	sleep(1);

	p.setValue(0);

	sleep(1);

	p.setValue(1);

	p.close();
	return 0;
}

