#include <iostream>
#include <string>

int main(){
	//offset
	int offset = 'A'-'a';
	//get string from console
	std::string given("");
	std::cin>>given;
	std::string::iterator l = given.begin();
	std::string::iterator r = given.end()-1;
	while(l<r){
		char temp = *l;
		*l = *r;
		*r = temp;
		++l;
		--r;
	}
	*(given.begin())+=offset;
	*(given.end()-1)+=offset;

	std::cout<<given<<"\n";

	return 0;
}
