#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
#include <string>
int squareSum(int,const std::vector<int>&, int);
template <typename T>
std::ostream& operator<<(std::ostream&, const std::vector<T>&);
int main(){
	int N=0;
	int K=0;
	std::vector<int> A{-1};
	//get inputs and check their legitimacy
	std::string s = "";
	std::stringstream ss;
	getline(std::cin, s);
	ss.str(s);
	ss>>N>>K;
	std::stringstream ss2;
	getline(std::cin, s);
	ss2.str(s);
	int n = 0;
	while(ss2>>n){
		A.push_back(n);
	}
	//lot of hassle
	for(int i=1;i<=N-K+1;++i){
		std::cout<<squareSum(i, A, K)<<" ";
	}std::cout<<std::endl;
	return 0;
}
int squareSum(int i, const std::vector<int>& A, int K){
	int sum = 0;
	for(int j=1; j<=K; ++j){
		sum+=powf(j,2)*A[i+j-1];
//(1,A,3) = 1*9+4*10+9*10
	}
	return sum;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec){
	for(int i=0;i<vec.size();++i){
		os<<vec[i]<<" ";
	}os<<std::endl;
	return os;
}
