#include <iostream>

int main(){
	std::cout<<(int)'a'<<" "<<(int)'z'<<" "<<(int)'A'<<" "<<(int)'Z'<<"\n";
	//m,b,rand are variables involved in linear congruential method of random number generation
	const int m = 26;
	const int b = 18621;
	int rand = 11;
	for(int i=0; i<10; ++i){
		for(int j=0; j<4; ++j){
			rand = (rand*b+1)%m;
			std::cout<<(char)(rand+97);
		}std::cout<<" ";
	}std::cout<<"\n";
	return 0;
}
