#include <iostream>
#include <time.h>

int main(){
	long timer = time((long*)0);
	int trash = 0;
	std::cin>>trash;
	std::cout<<time((long*)0)-timer<<"\n";	
	return 0;
}
