#include <iostream>
#include <vector>

std::vector<int> memoization;

int fib(int);

int main(){
	std::cout<<fib(7)<<"\n";
	return 0;
}

int fib(int x){
	int result = 0;
	if(x<memoization.size()){
		result = memoization[x-1];
	}else if(x==memoization.size()){
		memoization.push_back(*(memoization.end()-1)*x);
		result = memoization[x+1];
	}else{
		result = fib(x-2) * fib(x-1);
	}
	return result;
}
