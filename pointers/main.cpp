#include <iostream>

void printNum(int * const * const);

int main(){
	int num = 8;
	int const & ref = num;
	int * const ptr = &num;
	int * const * const pptr = &ptr;
	printNum(&ptr);
	return 0;
}

void printNum(int * const * const num){
	++(**num);
	std::cout<<**num<<"\n";
}

//"const" specifier affects the type to its left. "const int" is technically syntax sugar
