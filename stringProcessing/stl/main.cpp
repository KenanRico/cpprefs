#include <iostream>
#include <string>
#include <sstream>


int main(){
	std::string s = "http://www.youtube.com menu resume";
	std::stringstream ss(s);
	std::string clean("");
	std::string launch("");
	std::string action("");
	ss>>clean>>launch>>action;



	std::cout<<clean<<" "<<launch<<" "<<action<<"\n";




	return 0;
}
