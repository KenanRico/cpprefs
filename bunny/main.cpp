#include <iostream>
#include "colony.h"
const int period = 40;
int day = 0;
int main(){
	Colony NWA;
	while(day<period){
		NWA.ADayHasPassed();
		day++;
	NWA.Members();
	std::cout<<NWA.Number()<<std::endl;
	}
//	NWA.Members();
	return 0;
}
