#include <iostream>
#include <memory>

int main(){
	unsigned int num = 0x00000001;
	unsigned int mask = 0x00000004;
	std::shared_ptr<int> p = std::make_shared<int>(6);
	if(num & mask == mask){
		//num -= mask;
	}else{
		//num+=mask;
	}
	std::cout<<*p<<"\n";
	return 0;
}
