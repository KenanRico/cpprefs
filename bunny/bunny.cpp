#include "bunny.h"
#include <sstream>
//#include "bunnyinfo.h"
Bunny::Bunny(int id, sex sx)
:Age(0){
	this->ID = id;
	this->Sex = sx;
	switch(rand()%3){
		case 0: this->Color = color::brown; break;
		case 1: this->Color = color::black; break;
		case 2: this->Color = color::yellow; break;
		default: break;
	}
}
Bunny::Bunny(int count, const Bunny& b1, const Bunny& b2)
:ID(count),Age(0){
	if(b1.Sex!=b2.Sex){
		this->Color = (b1.Color==b2.Color)?b1.Color:((rand()%2==0)?b1.Color:b2.Color);
		this->Sex = (rand()%2==0)?sex::male:sex::female;
	}else{
		this->Color = color::black;
		this->Age = 11;
		this->Sex = sex::male;
	}
}

Bunny::Bunny(const Bunny& bun)
:ID(bun.ID),Age(bun.Age),Sex(bun.Sex),Color(bun.Color){;}

Bunny& Bunny::operator=(const Bunny& bun){
	this->ID = bun.ID;
	this->Age = bun.Age;
	this->Sex = bun.Sex;
	this->Color = bun.Color;
}
int Bunny::getID(){
	return ID;
}
int Bunny::getAge(){
	return Age;
}
sex Bunny::getSex(){
	return Sex;
}
color Bunny::getColor(){
	return Color;
}
void Bunny::Grow(){
	Age++;
}
std::string Bunny::Info(){
	std::string info = "";
	std::stringstream ss;
	std::string s = "";
	std::string c = "";
	s = (Sex==sex::male)?"male":"female";
	switch(Color){
		case color::yellow: c = "Yellow"; break;
		case color::brown: c = "Brown"; break;
		case color::black: c = "Black"; break;
		default: break;
	}
	ss<<ID<<" "<<Age<<" "<<s<<" "<<c;
	return ss.str();
}
Bunny::~Bunny(){;}

std::ostream& operator<<(std::ostream& os, const Bunny& b){
	std::string s = "";
	std::string c = "";
	s = (b.Sex==sex::male)?"male":"female";
	switch(b.Color){
		case color::yellow: c = "Yellow"; break;
		case color::brown: c = "Brown"; break;
		case color::black: c = "Black"; break;
		default: break;
	}
	os<<b.ID<<" "<<b.Age<<" "<<s<<" "<<c;
	return os;
}




