Examples
========

In this example, some pins are light up and turned down after the time specified in the shell parameters.

.. code-block:: cpp

	#include <quick2wire/gpio.hpp>
	#include <unistd.h>
	#include <vector>
	#include <time.h>
	#include <math.h>

	#define PIN_COUNT 7
	using namespace std;
	int main(int argc, char* argv[]){

		GPIO g;
		int pin_numbers [PIN_COUNT] = {3, 7, 0, 2, 1, 4, 5};
		vector <Pin> pins;
		
		if(argc < 2){
			fprintf(stdout, "Usage %s [sleep time in seconds]", argv[0]);
			exit(1);
		}
		
		double sleep_time = atof(argv[1]);
		if(sleep_time < 0){
			fprintf(stdout, "Wrong sleep time value");
			exit(2);
		}

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
				usleep(sleep_time*1000000);
				pins[i].setValue(0);
			}
		}

		for (unsigned int i = 0; i < pins.size(); ++i)
		{
			pins[i].close();
		}
		
		return 0;
	}