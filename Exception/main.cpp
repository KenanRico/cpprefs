#include <iostream>
#include <exception>

int main(){
	int num = 6;
	int *p = &num;
	try{
		int result = num/0;
		std::cout<<"Success"<<std::endl;
	}catch(...){
		std::cerr<<"Exception thrown"<<std::endl;
	}


	return 0;
}
