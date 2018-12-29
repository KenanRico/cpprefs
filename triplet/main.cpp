#include <iostream>


void initArray(int**, int*);
bool findTriplet(int const *, int, int*);
void destroyArray(int*);


int main(){
	int* arr = nullptr;
	int N = 0;
	initArray(&arr, &N);

	int triplet[3] = {0,0,0};
	bool success = findTriplet((int const *)arr, N, triplet);
	if(success){
		std::cout<<"triplet: ";
		for(int i=0; i<3; ++i){
			std::cout<<triplet[i]<<" ";
		}
		std::cout<<"\n";
	}else{
		std::cout<<"Could not find triplet\n";
	}

	destroyArray(arr);
	return 0;
}

void initArray(int** arr, int* N){
	*N = 10;
	*arr = new int[*N]();
	(*arr)[0] = -3;
	(*arr)[1] = 6;
	(*arr)[2] = 3;
	(*arr)[3] = 1;
	(*arr)[4] = -2;
	(*arr)[5] = 9;
	(*arr)[6] = -6;
	(*arr)[7] = 7;
	(*arr)[8] = 4;
	(*arr)[9] = -1;
}


bool findTriplet(int const * array, int size, int* triplet){
	bool result = false;

	for(int i=0; i<size; ++i){
		for(int j=i+1; j<size; ++j){
			if(hash_table[hash(0-array[i]-array[j])] > 0){

			}else{
				//keep interating
			}
		}
	}

	return result;
}


void destroyArray(int* arr){
	delete[] arr;
}
