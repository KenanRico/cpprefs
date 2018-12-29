#include <iostream>
#include <tuple>

int arr[] = {21,4,843,1,-72,33,99,8,51,12,9,0,53,981,1};
const unsigned int size = sizeof(arr)/sizeof(int);

void printArray();
void printDynamicArr(const int*, int);
std::tuple<const int*, int> mergeSort(const int, const int);
std::tuple<const int*, int> merge(std::tuple<const int*, int>, std::tuple<const int*, int>);
std::tuple<int,int> smaller(int, int);

int main(){
	printArray();
	std::tuple<const int*, int> result = mergeSort(0,size-1);
	const int* new_arr = std::get<0>(result);
	if(std::get<1>(result)!=size){
		std::cerr<<"Sizes don't match! new_arr's size is "<<std::get<1>(result)<<"."<<std::endl;
		printDynamicArr(new_arr, std::get<1>(result));
	}else{
		for(unsigned int i=0; i<size; ++i){
			arr[i] = new_arr[i];
		}	
	}
	delete[] new_arr;
	printArray();
	return 0;
}

void printArray(){
	for(unsigned int i=0; i<size; ++i){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

std::tuple<const int*,int> mergeSort(const int start, const int end){
	if(start==end){
		int* single_ele = new int[1]();
		single_ele[0] = arr[start];
//		std::cout<<"in mergeSort with 1 element: "<<arr[start]<<" "<<start<<std::endl;
		return std::make_tuple(single_ele, 1);
	}else{
		int mid = (end+start)/2;
		std::tuple<const int*,int> first_half_info = mergeSort(start, mid);
		std::tuple<const int*,int> second_half_info = mergeSort(mid+1, end);
		return merge(first_half_info, second_half_info);
	}
}

std::tuple<const int*,int> merge(std::tuple<const int*,int> first_half_info, std::tuple<const int*,int> second_half_info){
//	std::cout<<"in merge()"<<std::endl;
	const int* first_half = std::get<0>(first_half_info);
	const int* second_half = std::get<0>(second_half_info);
	int size_1 = std::get<1>(first_half_info);
	int size_2 = std::get<1>(second_half_info);
	int merged_size = size_1 + size_2;
	int* merged_aux = new int[merged_size]();
	int pos_1 = 0;
	int pos_2 = 0;
	for(int i=0; i<merged_size; ++i){
		if(pos_1<size_1 && pos_2<size_2){
			std::tuple<int,int> smaller_info = smaller(first_half[pos_1], second_half[pos_2]);
			merged_aux[i] = std::get<1>(smaller_info);
			if(std::get<0>(smaller_info)==1){
				++pos_1;
			}else if(std::get<0>(smaller_info)==2){
				++pos_2;
			}else{
				std::cout<<"wtf?"<<std::endl;
			}
		}else{
			if(pos_1>=size_1 && pos_2<size_2){
				merged_aux[i] = second_half[pos_2];
				++pos_2;
			}else if(pos_1<size_1 && pos_2>=size_2){
				merged_aux[i] = first_half[pos_1];
				++pos_1;
			}else{
				std::cerr<<"IMPOSSIBRU!! size_1 is "<<size_1<<", size_2 is "<<size_2<<". pos_1 is "<<pos_1<<", pos_2 is "<<pos_2<<"."<<std::endl;
				delete[] first_half;
				delete[] second_half;
				return std::make_tuple((int*)0, -1);
			}
		}
//		std::cout<<"LOL:"<<merged_aux[i]<<std::endl;
/*		if(merged_aux[i]==0){
			printDynamicArr(first_half, size_1);
			printDynamicArr(second_half, size_2);
		}else;
*/	}
//not sure how "delete[]" works on single dynamic object rather than an array
	delete[] first_half;
	delete[] second_half;
	return std::make_tuple(merged_aux, merged_size);	
}

std::tuple<int,int> smaller(int first, int second){
	return std::make_tuple((first<second)?1:2,(first<second)?first:second);
}

void printDynamicArr(const int* arr, int length){
	for(int i=0; i<length; ++i){
		std::cout<<*(arr+i)<<" ";
	}
	std::cout<<std::endl;
}
