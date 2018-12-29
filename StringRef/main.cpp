#include <iostream>
#include <string>

void print(const std::string&);

int main(){
	int type = 0; //0 for literal, 1 for local object, 2 for temp
	switch(type){
		case 0:{
			print("this is a literal");
		}break;
		case 1:{
			std::string obj("this is an object reference");
			print(obj);
		}break;
		case 2:{
			print(std::string("this is a temporarily created string"));
		}break;
		dafault: break;
	}
	return 0;
}

void print(const std::string& str){
	std::string local_str = str;
	std::cout<<local_str<<"\n";
}
