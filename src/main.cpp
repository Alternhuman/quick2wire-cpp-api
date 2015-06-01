#include "board_revision.hpp"
#include "gpio.hpp"

int main(int argc, char* argv[]){
	printf("%d\n", revision());
	GPIO g;
}
