#include "someclass.h"
#include <iostream>

int main(){
	int size = 0;
	std::cin>>size;
	std::string trash="";
	getline(std::cin,trash);
	Someclass obj(size);
	obj.print();
	std::cout<<obj.count()<<std::endl;
	return 0;
}
