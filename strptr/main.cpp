/*This program is used to check size of std::string pointer on 64bit Unix system. The result is 8 bits (meaning each std::string occupies 8 bytes w/ overhead)*/

#include <iostream>
#include <string>


int main(){
	std::string str = "lalalala";
	std::string* ptr = &str;
	for(int i=0; i<10; ++i){
		std::cout<<ptr++<<" ";
	}
	std::cout<<"\n";
	return 0;
}
