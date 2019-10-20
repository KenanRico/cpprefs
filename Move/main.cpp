#include <utility>
#include <iostream>
#include <string>


int main(){
	int* a = new int(100);
	int* b = std::move(a);
	std::cout<<a<<" "<<*a<<" "<<b<<" "<<*b<<"\n";
	return 0;
}
