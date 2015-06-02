#include "board_revision.hpp"
#include "gpio.hpp"
int main(int argc, char* argv[]){

	GPIO g;
	Pin p = g.pins->at(3);
	p.open();
	p.setDirection(OUT);
	p.setValue(1);
	return 0;
}

