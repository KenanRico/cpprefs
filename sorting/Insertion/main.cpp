#include <iostream>
void shift_n_shove(int* const, int* const);
int main(){
	int arr[] = {10,39,0,3,5,11,9,0,48,22,-1,8,6,2,2,3,22,95,4};
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
		int* temp = &arr[0];
		while(temp+1!=std::end(arr)){
			if(*temp>*(temp+1)){
				shift_n_shove(arr,temp+1);
			}else;
			temp++;
		}
	}
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
		std::cout<<arr[i]<<" ";
	}std::cout<<std::endl;	
}
void shift_n_shove(int* const arr, int* const ele){
	int* curr = arr;
	while(*ele>=*curr){
		curr++;
	}
	int temp = *ele;
	int* curr2 = &(*ele);
	while(curr2>curr){
		*curr2 = *(curr2-1);
		curr2--;
	}
	*curr = temp;
}
		
		
