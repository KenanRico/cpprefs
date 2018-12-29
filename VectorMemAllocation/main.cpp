/***
This is a test program created for me to see how memory is allocated for c++ vectors & its elements for a few design schemes.
Use this as future references.
***/

/***
Conclusion: 
1. all elements in a vector are allocated on the heap
2. memory of vector elements is contiguous
3. Avoid having vectors holding pointers to dynamically allocated objects for caching efficiency
***/


#include <vector>
#include <sstream>
#include <iostream>


void PrintAddr(const std::vector<int>&);
void PrintAddr(const std::vector<int*>&);

int main(){
	//vector of integer on stack
	std::vector<int> stack_vec = {1,2,3,4,5,6,7,8,9,10};
	//vector of integer on heap
	std::vector<int>* heap_vec = new std::vector<int>({1,2,3,4,5,6,7,8,9,10});
	//vector of integer pointers each of which points to a dynamically allocated integer
	std::vector<int*> stack_dynamic_vec;
	for(int i=0; i<10; ++i){
		stack_dynamic_vec.push_back(new int(i));
	}

	//print memory schemes
	PrintAddr(stack_vec);
	PrintAddr(*heap_vec);
	PrintAddr(stack_dynamic_vec);

	delete heap_vec;
	for(int i=0; i<10; ++i){
		delete stack_dynamic_vec[i];
	}


	return 0;
}

void PrintAddr(const std::vector<int>& vec){
	std::stringstream ss;
	ss<<"vector address: "<<&vec<<"\nelement addresses: ";
	for(std::vector<int>::const_iterator i=vec.begin(); i!=vec.end(); ++i){
		ss<<&(*i)<<" ";
	}
	std::cout<<ss.str()<<"\n\n";
}

void PrintAddr(const std::vector<int*>& vec){
	std::stringstream ss;
	ss<<"vector address: "<<&vec<<"\nelement addresses: ";
	for(std::vector<int*>::const_iterator i=vec.begin(); i!=vec.end(); ++i){
		ss<<*i<<" ";
	}
	std::cout<<ss.str()<<"\n\n";
}
