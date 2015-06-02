#include "board_revision.hpp"
#include "gpio.hpp"
#include <unistd.h>
/*from quick2wire.gpio import pins, In, Out

#pins_number = [22, 4, 17, 27, 18, 23, 24, 25]
pins_number = [3, 7, 0, 2, 1, 4, 5]
pins_obj=[]
for pin in pins_number:
	pins_obj.append(pins.pin(pin, direction=Out))
def sigint_handler(signal, frame):
	for pin in pins_obj:
		pin.close()
	sys.exit(0)
signal.signal(signal.SIGINT, sigint_handler)
while True:
	for i in range(0, 3):
		for pin in pins_obj:
			pin.open()
			pin.value = 1
			time.sleep(SLEEP_TIME)
			pin.value=0
			pin.close()*/

#include <vector>

#define PIN_COUNT 7
using namespace std;
int main(int argc, char* argv[]){

	GPIO g;
	int pin_numbers [PIN_COUNT] = {3, 7, 0, 2, 1, 4, 5};
	vector <Pin> pins;

	int sleep_time = atoi(argv[1]);

	for (int i = 0; i < PIN_COUNT; ++i)
	{
		Pin p = g.pins->at(pin_numbers[i]);
		p.open();
		pins.push_back(p);
	}

	int m = 3;
	while( m --> 0){
		for (unsigned int i = 0; i < pins.size(); ++i)
		{
			
			pins[i].setDirection(OUT);
			pins[i].setValue(1);
			sleep(sleep_time);
			pins[i].setValue(0);
		}
	}

	for (unsigned int i = 0; i < pins.size(); ++i)
	{
		pins[i].close();
	}
	

	return 0;
}

