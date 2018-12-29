#include <iostream>

void swap(int*,int*);
int main(){
	int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
	if(std::begin(arr)==0){
		return -1;
	}else;
	if(sizeof(arr)/sizeof(arr[0])==1){
		return 0;
	}else;
	for(unsigned int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
		int* a = arr;
		int* b = a+1;
		while(b<std::end(arr)-i){
			if(*a>*b) swap(a,b); else;
			a++;
			b++;
		}
	}
	for(unsigned int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
		std::cout<<arr[i]<<" ";
	}std::cout<<std::endl;
	return 0;
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
