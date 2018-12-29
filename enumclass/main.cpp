#include <iostream>

enum class number{
	ONE,
	TWO,
	THREE
};
int main(){
	number x = number::ONE;
	switch(x){
		case number::ONE: std::cout<<"x is one"<<std::endl; break;
		case number::TWO: std::cout<<"x is two"<<std::endl; break;
		case number::THREE: std::cout<<"x is three"<<std::endl; break;
		default: std::cout<<"nothing"<<std::endl; break;
	}
	return 0;
}
