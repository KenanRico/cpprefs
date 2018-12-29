#include <iostream>
#include <string>
bool isNum(char);
int main(){
	int arr[10] = {0};
	std::string S("");
	std::cin>>S;
	for(std::string::const_iterator is=S.begin(); is<S.end(); ++is){
		if(isNum(*is)){
			arr[*is-48]++;
		}else;
	}
	for(int i=0; i<10; ++i){
		std::cout<<arr[i]<<" ";
	}std::cout<<std::endl;
	return 0;
}
bool isNum(char c){
	return (c>47&&c<58);
}


++a+b
