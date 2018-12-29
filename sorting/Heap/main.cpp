


void heapSort(int*, const int);
printArray(const int*, const int);

int main(){
	int arr[] = {31,49,12,0,4,91,17,12,18,3,74};
	const unsigned int size = sizeof(arr)/sizeof(int);
	printArray(arr,size);
	heapSort(arr, size);
	printArray(arr,size);
	return 0;
}

void heapSort(int* arr, const int size){
	int heap_size = size;
	while(heap_size>1){
		maxHeapify(arr, heap_size);
		swapFirstLast(arr, heap_size);
		--heap_size;
	}
}
void maxHeapify(int* arr, int size){
	int index = size;
	//finishi this shit

}
void swapFirstLast(int* arr, int size){
	int temp = arr[0];
	arr[0] = arr[size-1];
	arr[size-1] = temp;
}

void printArray(const int* arr, const int size){
	for(unsigned int i=0; i<size; ++i){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}
