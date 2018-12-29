#include <iostream>
#include <string>
#include "bunnyinfo.h"

#ifndef BUNNY_H
#define BUNNY_H
class Bunny{
	private:
		int ID;
		int Age;
		sex Sex;
		color Color;
	public:
		Bunny(int,sex);
		Bunny(const Bunny&);
		Bunny& operator=(const Bunny&);
		Bunny(int, const Bunny&, const Bunny&);	
		friend std::ostream& operator<<(std::ostream&, const Bunny&);
		friend class Colony;
		int getID();
		int getAge();
		sex getSex();
		color getColor();
		void Grow();
		std::string Info();
		~Bunny();
};
#endif

std::ostream& operator<<(std::ostream, const Bunny&);

//std::ostream& operator<<(std::ostream& os, const Bunny& b){
//	os<<b.ID<<" "<<b.Age<<" "<<b.Sex<<" "<<b.Color;
//	return os;
//}

