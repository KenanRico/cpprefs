#include <tuple>
#include <string>
#include <iostream>
#include <sstream>

void parse(int&,int&,int*&);
std::tuple<int,int,int> findK(const int*,int,int);
void printSubarray(const int*,int,int,int);
int sum(const int*,int,int);

int main(){
	int N = 0;
	int X = 0;
	int* arr = (int*)0;
	parse(N,X,arr);
	std::tuple<int,int,int> subinfo = findK(arr,N,X);
	printSubarray(arr,std::get<0>(subinfo),std::get<1>(subinfo),std::get<2>(subinfo));
	delete arr;
	return 0;
}

void parse(int& N, int& X, int*& arr){
	std::cout<<"N and X:"<<std::endl;
	std::cin>>N>>X;
	arr = new int[N]();
	std::string trash = "";
	getline(std::cin, trash);
	std::string elements = "";
	std::cout<<"Array elements:"<<std::endl;
	getline(std::cin, elements);
	std::stringstream ss(elements);
	int ele = 0;
	int i = 0;
	while(ss>>ele){
		try{
			if(i<N){
				arr[i++] = ele;
			}else{
				throw "Input too long";
			}
		}catch(const char* Err){
			std::cerr<<Err<<std::endl;
		}
	}
}

std::tuple<int,int,int> findK(const int* arr, int N, int X){
	//soluteion: begin pointer chases end pointer and have an int store the max distance seen betweent he two
	int begin = 0;
	int end = 0;
	int all = arr[begin];
	std::cout<<"assigned all"<<std::endl;
	int max_length = 0;
	while(end<N){
		all = sum(arr, begin, end);
		if(all>X){
			if(begin<end){
				++begin;
			}else if(begin==end){
				++begin;
				++end;
			}else if(begin>end){
				std::cerr<<"Something ain't right about this counting"<<std::endl;
			}else;
		}else{
			max_length = (end-begin+1>max_length)?(end-begin+1):max_length;
			++end;
		}
	}
	end = (end==N)?end-1:end;
	return std::make_tuple(max_length, begin, end);
}

int sum(const int* arr, int begin, int end){
	int sum = 0;
	for(int i=begin; i<=end; ++i){
		sum+=arr[i];
	}
	return sum;
}


void printSubarray(const int* arr, int K, int begin, int end){
	try{
		if(K>=0&&begin>=0&&end>=0){
			std::cout<<"Max size is "<<K<<std::endl;
			std::cout<<"The elements are: ";
			for(int i=begin; i<=end; ++i){
				std::cout<<arr[i]<<" ";
			}std::cout<<std::endl;
		}else{
			throw "Invalid position";
		}
	}catch(const char* Err){
		std::cerr<<Err<<std::endl;
	}
}

