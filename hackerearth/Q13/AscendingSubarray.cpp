#include <iostream>
#include <vector>
#include <tuple>
#include <sstream>
#include <string>

void start(std::vector<int>&);
std::tuple<std::vector<int>::const_iterator, std::vector<int>::const_iterator> findSequence(const std::vector<int>&);
void push_pop(std::vector<int>&, int, int);
void printSequence(std::vector<int>::const_iterator, std::vector<int>::const_iterator);

int main(){
	std::vector<int> vec;
	start(vec);
	printSequence(vec.begin(),vec.end()-1);
	return 0;
}

void start(std::vector<int>& vec){
	unsigned int N = 0;
	int Q = 0;
	std::cout<<"N(size) and Q(operators):"<<std::endl;
	std::cin>>N>>Q;
	std::string trash = "";
	getline(std::cin, trash);
	std::string elements = "";
	std::cout<<"Elements:"<<std::endl;
	getline(std::cin, elements);
	std::stringstream ss(elements);
	int ele = 0;
	while(ss>>ele){
		vec.push_back(ele);
	}
	try{
		if(vec.size()!=N){
			throw "Incorrect input size";
		}else{
			for(int i=0; i<Q; ++i){
				int action = 0;
				int element = 0;
				std::string line = "";
				getline(std::cin, line);
				std::stringstream ss(line);
				ss>>action>>element;
				push_pop(vec,action,element);
				std::tuple<std::vector<int>::const_iterator, std::vector<int>::const_iterator> begin_end = findSequence(vec);
				printSequence(std::get<0>(begin_end), std::get<1>(begin_end));
			}
		}
	}catch(const char* Err){
		std::cerr<<Err<<std::endl;
		return;
	}
	


}

void push_pop(std::vector<int>& vec, int action, int element){
	switch(action){
		case 1: {
			vec.push_back(element);
			break;
		}
		case 2: {
			vec.pop_back();
			break;
		}
	}
}

std::tuple<std::vector<int>::const_iterator, std::vector<int>::const_iterator> findSequence(const std::vector<int>& vec){
	std::vector<int>::const_iterator first = vec.begin();
	std::vector<int>::const_iterator last = first;
	std::vector<int>::const_iterator max_first = first;
	std::vector<int>::const_iterator max_last = first;
	int max = 0;
	int count = 0;
	while(last<vec.end()-1){
		if(*(last+1)>*last){
			++count;
			max_last = last+1;
		}else{
			if(count>max){
				max = count;
				count = 0;
			}else;
			max_first = first;
			first = last;
		}
		++last;
	}
	return std::make_tuple(max_first,max_last);
}

void printSequence (std::vector<int>::const_iterator first, std::vector<int>::const_iterator last){
	for(std::vector<int>::const_iterator iter=first; iter<=last; ++iter){
		std::cout<<*iter<<" ";
	}std::cout<<std::endl;
}
