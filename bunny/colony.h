#include <iostream>
#include "bunny.h"
#include <deque>

#ifndef COLONY_H
#define COLONY_H
class Colony{
	private:
		std::deque<Bunny> All;
		int Count;
	public: 
		Colony();
		Colony(const Colony&) = delete;
		Colony& operator=(const Colony&) = delete;
		void ADayHasPassed();
		void Mating();
		void Dying();
		void ForestFire();
		void Members();
		int Number();
		~Colony();
};
#endif
