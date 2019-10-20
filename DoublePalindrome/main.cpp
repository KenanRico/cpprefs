#include <string>
#include <iostream>


int FindSplit(const std::string&, const std::string&, int);
bool IsPalindrome(char const *, char const *);

int main(){
	std::string a = "abcdedxxx";
	std::string b = "zzz1,zcba";
	int length = a.size();

	int split = FindSplit(a, b, length);
	std::cout<<"Find split : "<<split<<"\n";

	return 0;

}

int FindSplit(const std::string& a, const std::string& b, int length){
	int split = 0;
	bool cut_a = true;
	bool cut_b = true;
	int right = length-1-split;
	while(split<=right){
		if(cut_a){
			cut_a = a[split]==b[right];
			if(IsPalindrome(&b[split+1],&b[right-1])){
				break;
			}
		}
		if(cut_b){
			cut_b = b[split]==a[right];
			if(IsPalindrome(&a[split+1],&a[right-1])){
				break;
			}
		}
		++split;
		--right;
	}
	return split+1;
}

bool IsPalindrome(char const * left, char const * right){
	bool result = true;
	while(left<right){
		if(*left!=*right){
			result = false;
			break;
		}
		--right;
		++left;
	}
	return result;
}
