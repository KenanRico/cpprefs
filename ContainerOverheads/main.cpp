/*
Program that examines overhead size of various sequential containers.
Interestingly this taught me a lot about using templates (template template syntax, template specialization(full and partial), template function overloading and name lookup orders)
*/

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <deque>


//template <typename T, typename CT> void PopulateContainer(T* data, int size, CT* container);
template <template<class, class> class CT, class D, class Alloc> void PopulateContainer(D*, int size, CT<D, Alloc>*);
template <class D> void PopulateContainer(D* data, int size, std::queue<D>* container);
template <typename T> void PrintContainer(const T&, const T&);
template <typename D> void PrintContainer(std::queue<D>&);

int main(){
	int data[] = {1,2,3,4,5,6,7,8,9,10, 11, 12, 13, 14, 15, 16, 17, 18};
	int size = sizeof(data)/sizeof(int);
	//populate containes
	std::vector<int> vec;
	PopulateContainer(data, size, &vec);
	std::list<int> list;
	PopulateContainer(data, size, &list);
	std::queue<int> q;
	PopulateContainer(data, size, &q);
	std::deque<int> dq;
	PopulateContainer(data, size, &dq);
	//print mem overhead
	int data_in_bytes = sizeof(data);
	std::cout
		<<"vector overhead: "<<sizeof(vec)+vec.size()*sizeof(int)-data_in_bytes<<" bytes\n"
		<<"list overhead: "<<sizeof(list)+list.size()*sizeof(int)-data_in_bytes<<" bytes\n"
		<<"queue overhead: "<<sizeof(q)+q.size()*sizeof(int)-data_in_bytes<<" bytes\n"
		<<"dequeue overhead: "<<sizeof(dq)+dq.size()*sizeof(int)-data_in_bytes<<" bytes\n";
	return 0;
}

template <template<class, class> class CT, class D, class Alloc> void PopulateContainer(D* data, int size, CT<D, Alloc>* container){
	for(int i=0; i<size; ++i){
		container->push_back(data[i]);
	}
}

template <class D> void PopulateContainer(D* data, int size, std::queue<D>* container){
	for(int i=0; i<size; ++i){
		container->push(data[i]);
	}
}

template <typename T> void PrintContainer(const T& begin, const T& end){
	for(T i=begin; i!=end; ++i){
		std::cout<<*i<<" ";
	}
	std::cout<<"\n";
}
