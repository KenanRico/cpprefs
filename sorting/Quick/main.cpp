#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int arr[] = {1,9,7,-13,44,0,-53,0,244,100,-22,93,1,39,15,-21,-15,9,2};

void quickSort(int,int);
void printArr();
void print(const char*);

void logErase();
void logArr();
void logLeftRight(int,int);

int main(){
	logErase();
	printArr();
	logArr();
	quickSort(0, sizeof(arr)/sizeof(int)-1);
	printArr();
	logArr();
	return 0;
}

void quickSort(int left, int right){
	if(left>=right||right<0){
		return;
	}else;
	int pivot = arr[left];
	int i = left;
	int j = right;
	while(i<j){
		while(arr[i]<=pivot){
			++i;
		}
		while(arr[j]>pivot){
			--j;
		}
		if(i<j){
//			std::cout<<i<<" "<<j<<std::endl;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;	
		}else{
			break;
		}
	}
	logLeftRight(i,j);
//	printArr();
	logArr();
	arr[left] = arr[j];
	arr[j] = pivot;
	quickSort(left,j-1);
	quickSort(j+1, right);
}
void printArr(){
	for(unsigned int i=0; i<sizeof(arr)/sizeof(int); ++i){
		std::cout<<arr[i]<<" ";
	}std::cout<<std::endl;
}
void print(const char* s){
	std::cout<<s<<std::endl;
}
void logErase(){
	std::ofstream fstrm("log.txt", std::ios::trunc);
	fstrm<<"log:"<<std::endl;
	fstrm.close();
}
void logLeftRight(int i, int j){
	std::ofstream fstrm("log.txt", std::ios::app);
	fstrm<<i<<" "<<j<<std::endl;
	fstrm.close();
}
void logArr(){
//	erase("log.txt");
	std::ofstream fstrm("log.txt", std::ios::app);
	for(unsigned int i=0; i<sizeof(arr)/sizeof(int); ++i){
		fstrm<<arr[i]<<" ";
	}
	fstrm<<std::endl;
	fstrm.close();
}
	
