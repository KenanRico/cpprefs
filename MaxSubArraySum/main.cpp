#include <iostream>
int main(){
//	int arr[] = {-4,1,0,9,-4,1,16,-200,8,9,8,-3,-6,11,0,4,-92}; //subject array
//	int arr[] = {4,5,0,-19,0,93,-82,1,2,-9,-8,-6,1,-100,83,12,8,0,-8,7};
	int arr[] = {1,2,-5,4,-3,2};
	int currSum = 0;
	int totalSum = 0;
	int *currFirst, *totalFirst, *Last = arr;
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);++i){
		currSum+=arr[i];
		if(currSum>totalSum){
			totalSum = currSum;
			totalFirst = currFirst;
			Last = &arr[i];
		}else;
		if(currSum<0){
			currSum = 0;
			(currFirst=&arr[i])++;
		}else;
	}
	std::cout<<"(";
	for(int* p=totalFirst;p<=Last;++p){
		std::cout<<","<<*p;
	}
	std::cout<<")"<<std::endl;
	std::cout<<totalSum<<std::endl;
	return 0;
}
