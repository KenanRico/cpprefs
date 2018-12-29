#include <iostream>
#include <string>
#include "point.h"
Point::Point()
:s(0),assigned(false)
{}
Point::Point(const Point& rhs)
:s(new std::string(*(rhs.s))),assigned(true)
{}
Point::Point(std::string new_s)
:s(new std::string(new_s)),assigned(true)
{}
Point& Point::operator=(const Point& rhs){
	if(this->assigned)
		delete this->s;
	else
		this->assigned = true;
	this->s = new std::string(*(rhs.s));
//	this->print();
	return *this;
}
void Point::print(){
		if(this->assigned)
			std::cout<<(*(this->s))<<" "<<(this->s)<<std::endl;
		else	
			std::cout<<"Pointer unassigned"<<std::endl;
}
Point::~Point(){
	if(this->assigned)
		delete this->s;
	else;
	std::cout<<"Deleting object now"<<std::endl;
}

