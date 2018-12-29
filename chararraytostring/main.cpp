#include <iostream>

std::string s(){
	return std::string("hahahaha");
}

int main(){
	char chararray[10] = {'a', 'b', 'c'};
	std::string str(chararray);
	std::string wtf("a:0.1,0.2 b:0.1,0.5");
	std::cout<<s()<<"\n";


	return 0;
}
