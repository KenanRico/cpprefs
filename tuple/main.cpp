#include <iostream>
#include <tuple>
#include <deque>

std::tuple<int,char> func(const std::deque<char>&);

int main(){
	std::tuple<int,int,char> t = std::make_tuple(1,4,'z');
	std::cout<<std::get<1>(t)<<std::endl;
	std::deque<char> deq({'z','b','l','o','p','r','q'});
	std::cout<<std::get<0>(func(deq))<<" "<<std::get<1>(func(deq))<<std::endl;
	return 0;
}

std::tuple<int,char> func(const std::deque<char>& deq){
	return std::make_tuple(deq.size(), *(deq.end()-1));
}

