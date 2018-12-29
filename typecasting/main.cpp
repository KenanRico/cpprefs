#include <iostream>
#include <stdio.h>
#include <random>
int main(){
	for(int i=0;i<0xFF;i++){
		std::cout<<i<<" "<<(char)i<<std::endl;
	}
	int *p = new int(20);
	std::cout<<p<<" "<<p+1<<std::endl;
	delete p;
	int x = 5;
	std::cout<<&x<<std::endl;
	std::cout<<time(0)<<std::endl;
	return 0;

}
