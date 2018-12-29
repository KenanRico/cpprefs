#include "debug.h"
#include <iostream>

void printAux(int** aux, int number_sys, int size){
	for(int i=0; i<number_sys; ++i){
		std::cout<<i<<": ";
		for(int j=0; j<size; ++j){
			std::cout<<aux[i][j]<<" ";
		}std::cout<<std::endl;
	}
}
