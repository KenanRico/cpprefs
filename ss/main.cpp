#include <sstream>
#include <iostream>

int main(){
	std::stringstream ss;
	float x = 0.9182f;
	float y = 0.271f;

	ss<<x<<" "<<y;
	std::string str = ss.str();
	
	std::cout<<str<<"\n";

	return 0;
}
