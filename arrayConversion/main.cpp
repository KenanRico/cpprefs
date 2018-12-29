#include <iostream>

bool convertable(const int*, unsigned int, const int*, unsigned int);

int main(){
	int arr1[] = {2,16,7,1,9,1,11};
	int arr2[] = {5,10,2,20,-2,19,-8};
	if(convertable(arr1, sizeof(arr1)/sizeof(int), arr2, sizeof(arr2)/sizeof(int))){
		std::cout<<"YES \n";
	}else{
		std::cout<<"NO \n";
	}
	return 0;
}

bool convertable(const int* a1, unsigned int s1, const int* a2, unsigned int s2){
	bool result = false;
	if(s1==s2){
		int diff = 0;
		for(unsigned int i=0; i<s1; ++i){
			diff = (a2[i]+diff) - a1[i];
			if(i==s1-1){
				if(diff==0){
					result = true;
				}else{
					result = false;
				}
			}else;
		}
	}else{
		result = false;
	}
	return result;
}
