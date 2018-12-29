#include "process.h"

#include <iostream>


Process::Process(): process_ID(-1), process_name("default"), memory_usage(0.0f){
	//get process info
}

Process::~Process(){
	//do nothing
}

void Process::printProcessInfo() const{
	std::cout<<"Process information:\n"<<"ID: "<<process_ID<<" | Name: "<<process_name<<" | Memory: "<<memory_usage<<"\n";
}
