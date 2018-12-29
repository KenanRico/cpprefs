#include "selectionsort.h"
#include <string>
#include <cstring>

void sort_ascend(int*,int);
void sort_descend(int*,int);
int& array_min(int*,int);
int& array_max(int*,int);
//---------------------------------------------Class Functions---------------------------------------------
SelectionSort::SelectionSort(int* arr, int length)
:arr(arr),length(length){;}

void SelectionSort::operator()(const char* order){
	if(strcmp(order,"ASCEND")==0){
		sort_ascend(this->arr,this->length);
	}else if(strcmp(order,"DESCEND")==0){
		sort_descend(this->arr,this->length);
	}else{
		std::cout<<"Unrecognized sorting order!"<<std::endl;
	}
}

SelectionSort::~SelectionSort(){;}
//--------------------------------------------------------------------------------------------------------


//------------------------------------------------------Actual sorting algorithm, ez---------------------------------------------------
void sort_ascend(int* arr, int length){
	for(int i=0;i<length;++i){
		int sub_first = arr[i];
		int& curr_min = array_min(&arr[i],length-i);
		arr[i] = curr_min;
		curr_min = sub_first;
	}		
}
void sort_descend(int* arr, int length){
	for(int i=0;i<length;++i){
		int sub_first = arr[i];
		int& curr_max = array_max(&arr[i],length-i);
		arr[i] = curr_max;
		curr_max = sub_first;
	}		
}
//--------------------------------------------------------------------------------------------------------------------------------------


int& array_min(int* arr, int length){
	int min = arr[0];
	int min_pos = 0;
	for(int i=0;i<length;++i){
		if(arr[i]<min){
			min = arr[i];
			min_pos = i;
		}else;
	}
	return arr[min_pos];	
}
int& array_max(int* arr, int length){
	int max = arr[0];
	int max_pos = 0;
	for(int i=0;i<length;++i){
		if(arr[i]>max){
			max = arr[i];
			max_pos = i;
		}else;
	}
	return arr[max_pos];	
}
