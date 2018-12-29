#include <iostream>
#include "selectionsort.h"

void print_array(int*, int);
int main(){
	int arr[] = {1,5,-9,5,2,0,11,-98,93,7,54,-81};
	int length = sizeof(arr)/sizeof(arr[0]);
	SelectionSort ss(arr,length);
	ss("DESCEND");
	print_array(arr,length);
	return 0;
}

void print_array(int* arr, int length){
	for(int i=0;i<length;++i){
		std::cout<<arr[i]<<" ";
	}std::cout<<std::endl;
}
