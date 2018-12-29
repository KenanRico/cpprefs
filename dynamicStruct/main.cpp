#include <iostream>


int main(){
	struct Arr{ int data[10]; };
	struct Arr * ptr = new struct Arr;
	ptr->data[5] = 999;
	std::cout<<ptr->data[5]<<"\n";
	delete ptr;

	return 0;
}
