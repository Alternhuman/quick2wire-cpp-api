#include "board_revision.hpp"
#include "gpio.hpp"
int main(int argc, char* argv[]){
//	printf("%d\n", revision());
	GPIO g;
	Pin p = g.pins->at(3);
	//p.init(g.pins, 0, 27);
	p.open();
	p.setDirection(OUT);
	p.setValue(1);
	return 0;
}

