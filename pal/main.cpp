#include <iostream>
#include <fstream>
#include <string>

bool checkPalindrome(const std::string&);

int main(){
	std::ifstream fs("file.txt", std::ios::in);
	std::string line("");
	int pal_count = 0;
	int lineN = 1;
	while(getline(fs,line)){
		if(checkPalindrome(line)){
			++pal_count;
			std::cout<<lineN<<"\n";
		}else;
		++lineN;
	}
	fs.close();
	std::cout<<pal_count<<" palindromes in total \n";
	return 0;
}

bool checkPalindrome(const std::string& s){
	bool result = true;
	std::string::const_iterator left = s.begin();
	std::string::const_iterator right = s.end()-1;
	while(left<right){
		if(*left!=*right){
			result = false;
			break;
		}else{
			++left;
			--right;
		}
	}
	return result;
}
