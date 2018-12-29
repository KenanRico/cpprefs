#include <iostream>
#include <string>
#include <tuple>


int hashFunction(const char);
std::tuple<char,int> maxOccurence(int*, int);
int main(){
	std::string input=" ";
	std::cin>>input;
	int arr[256] = {0};
	for(std::string::iterator iter=input.begin(); iter<input.end(); ++iter){
		++arr[hashFunction(*iter)];
	}
	std::tuple<char, int> charCount = maxOccurence(&arr[0], 256);
	std::cout<<"Most occured is "<<std::get<0>(charCount)<<", "<<std::get<1>(charCount)<<" times"<<std::endl;
	return 0;
}
int hashFunction(const char c){
	return (int)c;
}
std::tuple<char,int> maxOccurence(int* arr, int size){
	char character = '-';
	int count = -1;
	int i=0;
	while(i<size){
		if(*(arr+i)>count){
			character = (char)i;
			count = *(arr+i);
		}else;
		++i;
	}
	return std::make_tuple(character, count);
}



