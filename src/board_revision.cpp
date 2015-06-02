#include "board_revision.hpp"

#define CPUINFO_PATH "/proc/cpuinfo"

#define PI_VERSION_1 1
#define PI_VERSION_2 2
int revision(){
	//TODO: check ifstream error
	std::ifstream f(CPUINFO_PATH);
	std::string str;
	std::string s("Revision");
	while(std::getline(f, str)){
		if(s.compare(0, s.length(), str.substr(0, s.length())) == 0){
			if((str.compare(str.length() - 2, str.length() -1, "2") == 0) || (str.compare(str.length() - 2, str.length() - 1, "3") == 0)){
				return 1;
			}
			return 2;
		}
	}
	return 0;
}
