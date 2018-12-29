#include <iostream>
#include <vector>
#include <math.h>
#include "debug.h"

int arr[] = {2983,421,8,902,18,8934,70,1193,927,4,78,0,228,5892,7821,845,38,11213};
const int number_sys = 10;

int hash(int,int);
void radixSort();
int maxDigit();
void remap(int**,unsigned int,const std::vector<int>&);
void allocAux(int**&,unsigned int);
void freeAux(int**,unsigned int);
void printArr(unsigned int);

int main(){
	printArr(sizeof(arr)/sizeof(int));
	radixSort();
	return 0;
}

int hash(int number, int digit){
	//figure out last_digit of number
	int after = number/powf(10,digit);	
	return after%10;
}

void radixSort(){
	const unsigned int size = sizeof(arr)/sizeof(int);
	int** aux = new int*[number_sys](); //0~9
	int digits = maxDigit();
	for(int i=0; i<digits; ++i){
		allocAux(aux, size);
		std::vector<int> indexes(10,0);
		for(unsigned int j=0; j<size; ++j){
			int current_number = arr[j];
			int current_number_slot = hash(current_number, i);
			try{
				if(indexes[current_number_slot]<(signed)size){
					aux[current_number_slot][indexes[current_number_slot]] = current_number;
//					std::cout<<"j = "<<j<<" current_number = "<<current_number<<std::endl;
//					printAux(aux, number_sys, size);
				}else{
					throw "overflow in radixSort";
				}
			}catch(const char* Err){
				std::cerr<<Err<<std::endl;
				return;
			}
			++indexes[current_number_slot];
		}
		printAux(aux, number_sys, size);
//		printArr(size);
		remap(aux, size, indexes);
		printArr(size);
		freeAux(aux, size);
	}
	delete[] aux;
}

int maxDigit(){
	int max = 0;
	for(unsigned int i=0; i<sizeof(arr)/sizeof(int); ++i){
		max = (arr[i]>max)?arr[i]:max;
	}
	int digit = 1;
	while((max/=10)!=0){
		++digit;
	}
	return digit;
}

void remap(int** aux, unsigned int arr_size, const std::vector<int>& indexes){
	unsigned int index = 0;
	for(unsigned int i=0; i<indexes.size(); ++i){
		int temp = indexes[i];
		while(temp>0){
			try{
				if(index<arr_size){
					arr[index] = aux[i][indexes[i]-temp];
				}else{
					throw "overflow in remap";
				}
			}catch(const char* Err){
				std::cerr<<Err<<std::endl;
				return;
			}
			++index;
			--temp;
		}
	}	
}

void allocAux(int** &aux, unsigned int arr_size){
	for(int i=0; i<number_sys; ++i){
		aux[i] = new int[arr_size]();
	}
}
void freeAux(int** aux, unsigned int arr_size){
	for(int i=0; i<number_sys; ++i){
		delete[] aux[i];
	}
}

void printArr(unsigned int size){
	std::cout<<"printArr: ";
	for(unsigned int i=0; i<size; ++i){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}
