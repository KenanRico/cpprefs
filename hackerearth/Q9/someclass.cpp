#include "someclass.h"
#include <iostream>
#include <string>
#include <sstream>

Someclass::Someclass(int s)
:arr(new bool[s]()),size(s){
	parse();
}
Someclass::Someclass(const Someclass& rhs)
:arr(new bool[rhs.size]()),size(rhs.size){
	for(unsigned int i=0;i<size;++i){
		arr[i] = rhs.arr[i];
	}
}
Someclass& Someclass::operator= (const Someclass& rhs){
	if(this->arr!=(bool*)0){
		delete this->arr;
	}else;
	this->size = rhs.size;
	this->arr = new bool[this->size]();
	for(unsigned int i=0;i<size;++i){
		arr[i] = rhs.arr[i];
	}
	return *this;
}
Someclass::~Someclass(){
	if(this->arr!=(bool*)0){
		delete this->arr;
	}else;
}


void Someclass::parse(){
	std::string line;
	getline(std::cin,line);
	std::stringstream ss(line);
	bool bit = 0;	
	unsigned int pos = 0;
	while(ss>>bit){
		*(arr+pos) = bit;
		++pos;
	}
	changeBit();
}
void Someclass::changeBit(){
//	1 0 0 0 1 0 1 0 1 1 0 0 0 1 1 1 0 1 1 1 1
	int maxchange = 0;
	int changepos = -1;
	for(unsigned int i=1; i<size-1; ++i){
		int oldones = (arr[i-1])+(arr[i])+(arr[i+1])+(arr[i-1]!=arr[i])+(arr[i]!=arr[i+1]);
		int newones = oldones-(arr[i])+(!arr[i])-(arr[i-1]!=arr[i])+(!arr[i-1]!=arr[i])-(arr[i]!=arr[i+1])+(!arr[i]!=arr[i+1]);
		if(newones>oldones){
			if((newones-oldones)>maxchange){
				maxchange = newones-oldones;
				changepos = i;
			}else;
		}else;
	}

	arr[changepos] = !arr[changepos];

}

void Someclass::print(){
	for(unsigned int i=0; i<size; ++i){
		std::cout<<*(arr+i)<<" ";
	}std::cout<<std::endl;
}

int Someclass::count(){
	int ones = 0;
	for(unsigned int i=0; i<this->size; ++i){
		ones+=(arr[i]==1);
	}
	if(this->size>=2){
		for(unsigned int i=1; i<this->size; ++i){
			ones+=(*(arr+i)!=*(arr+i-1));
		}
	}else;
	return ones;
}
