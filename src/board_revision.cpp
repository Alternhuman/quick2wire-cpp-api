#include "board_revision.hpp"

#define CPUINFO_PATH "/proc/cpuinfo"

#define PI_VERSION_1 1
#define PI_VERSION_2 2
int revision(){
	std::ifstream fcpuinfo(CPUINFO_PATH);
	if(fcpuinfo.fail()){
		return 3;
	}
	std::string aux_str;
	std::string revision_str("Revision");
	while(std::getline(fcpuinfo, aux_str)){
		if(revision_str.compare(0, revision_str.length(), aux_str.substr(0, revision_str.length())) == 0){
			if((aux_str.compare(aux_str.length() - 2, aux_str.length() -1, "2") == 0) || (aux_str.compare(aux_str.length() - 2, aux_str.length() - 1, "3") == 0)){
				return 1;
			}
			return 2;
		}
	}
	return 0;
}
