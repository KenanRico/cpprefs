#include <iostream>
#include <random>
int main(){
//	std::default_random_engine e(time(0));
//	std::cout<<e()<<" "<<e()<<std::endl;
	unsigned int num_hex = 0xffffffff;
	unsigned int num_bin = 1<<11;
	std::cout<<num_hex<<" "<<num_bin<<std::endl;
	std::uniform_int_distribution<unsigned int> u(0,99);
	std::default_random_engine e(time(0));
	int result = u(e);
	std::cout<<result<<std::endl;
	return 0;
}

