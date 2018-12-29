#include "colony.h"
#include <deque>
#include <iostream>
#include <random>
template<typename T>
void Randomize(std::deque<T>& deq){
	for(int i=0;i<deq.size();i++){
		std::default_random_engine e(time(0));
		std::uniform_int_distribution<unsigned int> u(0,deq.size()-1);
		int index = u(e);
//		int index = rand()%deq.size();
		T temp = deq[index];
		deq[index] = deq[deq.size()-1-index];
		deq[deq.size()-1-index] = temp;
		temp = deq[0];
		deq.pop_front();
		deq.push_back(temp);
	}
}
Colony::Colony()
:Count(2){
	All.push_back(Bunny(1,sex::male));
	All.push_back(Bunny(2,sex::female));
}
void Colony::Mating(){
	std::deque<Bunny> Adults;
	for(Bunny bun: All){
		if(bun.Age>=4){
			Adults.push_back(bun);
		}else;
	}
	Randomize(Adults);
	for(int i=0;i<Adults.size();i+=2){
		if(i<Adults.size()-1){
			Bunny b1 = Adults[i];
			Bunny b2 = Adults[i+1];
			if(b1.Sex!=b2.Sex){
				All.push_back(Bunny(Count+1,b1,b2));
				Count++;
			}else;
		}else{
			break;
		}
	}	
}
void Colony::Dying(){
	for(std::deque<Bunny>::iterator iter=All.begin();iter<All.end();iter++){
		if(iter->Age>10){
			All.erase(iter);
		}else;
	}
}
void Colony::ForestFire(){
	Randomize(All);
	for(int i=0;i<All.size()/2;i++){
		All.pop_front();
	}	
}			
void Colony::ADayHasPassed(){
	for(Bunny& bun: All){
		bun.Grow();
	}
	Mating();
	Dying();
	std::default_random_engine e(time(0)-5000);
	std::uniform_int_distribution<unsigned int> u(0,15);
	if(u(e)==0){
		ForestFire();
	}else;
}
int Colony::Number(){
	return this->Count;
}
void Colony::Members(){
	for(Bunny bun: All){
		std::cout<<bun.Info()<<std::endl;
	}
}
Colony::~Colony(){;}
