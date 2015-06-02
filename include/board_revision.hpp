#ifndef _H_BOARD_HPP
#define _H_BOARD_HPP

#include <fstream>
#include <string>
#include <iostream>

/*
	Returns an integer indicating the number of version of the Raspberry.
	In the event that the library is not running on a Raspberry, 0 is returned.
	The function uses the Revision field in the /proc/cpuinfo file.
	\returns PI_VERSION_1 (real value 1) or PI_VERSION_2 (real value 2). 0 if not running on Raspberry Pi.
*/
int revision();

#endif