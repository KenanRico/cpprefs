#include <iostream>
#include <string>

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
class SelectionSort{
	private:
		int* arr;
		int length;
	public:
		SelectionSort() = delete;
		SelectionSort(const SelectionSort&) = delete;
		SelectionSort& operator=(const SelectionSort&) = delete;
		SelectionSort(int*, int);
		void operator()(const char*);	
		~SelectionSort();
};
#endif	
