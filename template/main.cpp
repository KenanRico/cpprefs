#include <iostream>
#include <string>
template <typename T> T twice(const T&);
int main(){
	std::cout<<twice(std::string("Hi"))<<std::endl;
	std::cout<<twice(12)<<std::endl;
	return 0;
}
template <typename T>
T twice(const T& x){
	return x+x;
}
