#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void getArray(std::vector<int>&);
int numberEvenSubarray(const std::vector<int>&);
void printArray(const std::vector<int>&);

int main(){
	std::vector<int> arr;
	getArray(arr);
	printArray(arr);
	int num_subarrays = numberEvenSubarray(arr);
	std::cout<<"Number of sub-arrays whose sum is even is: "<<num_subarrays<<std::endl;
	return 0;
}

void getArray(std::vector<int>& arr){
	std::cout<<"Input array elements down below"<<std::endl;
	std::string array_string = "";
	getline(std::cin, array_string);
	std::stringstream ss(array_string);
	int ele = 0;
	while(ss>>ele){
		arr.push_back(ele);
	}
}

int numberEvenSubarray(const std::vector<int>& arr){
	int result = 0;
	for(unsigned int i=0; i<arr.size(); ++i){
		bool even=true;
		for(unsigned int j=i; j<arr.size(); ++j){
			even = ((arr[j]%2==0)==even);
			result += even;
		}
	}
	return result;
}

void printArray(const std::vector<int>& arr){
	for(unsigned int i=0; i<arr.size(); ++i){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}
