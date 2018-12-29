#include <iostream>

void hehe();

int main(){
	hehe();
	hehe();
	hehe();
	hehe();
	return 0;
}

void hehe(){
	static int i = 0;
	std::cout<<++i<<"\n";
}
