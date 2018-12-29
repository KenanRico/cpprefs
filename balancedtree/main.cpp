#include "tree.h"
#include "node.h"
#include "selectionsort.h"
#include <iostream>
void PrintArray(int*,unsigned int);
int main(){
	int arr[] = {21,0,39,-1,9,-24,-16,93,102,33,61,5};
	unsigned int length = sizeof(arr)/sizeof(arr[0]);
	SelectionSort ss(arr,length);
	ss("ASCEND");
	Tree tree(arr,length);
//	std::cout<<arr[0]<<" "<<arr[length-1]<<std::endl;	
	PrintArray(arr,length);
	tree.PrintTree();
	return 0;
}
void PrintArray(int* arr, unsigned int length){
	for(unsigned int i=0;i<length;i++){
		std::cout<<arr[i]<<" ";
	}std::cout<<std::endl;
}


