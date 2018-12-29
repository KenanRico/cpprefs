#include <algorithm>
#include <iostream>
#include <vector>
int main(){
	std::vector<int> vec{1,3,5,0,1,9,44,21,39};
	std::cout<<*(std::find(vec.begin(),vec.end(),111))<<std::endl;
	return 0;
}
