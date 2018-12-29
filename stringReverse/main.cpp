#include <iostream>
#include <string>

void reverse(std::string::iterator, std::string::iterator);

int main(){
	std::string s("Hi nice to meet you!");
	reverse(s.begin(), s.end()-1);
	std::cout<<s<<"\n";
	return 0;
}

void reverse(std::string::iterator left, std::string::iterator right){
	if(!left<right){
		return;
	}else{
		char temp = *left;
		*left = *right;
		*right = temp;
		reverse(left+1, right-1);
	}
}
