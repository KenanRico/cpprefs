#include <iostream>
#include <vector>

std::vector<int> mem;

int steps(int);

int main(){
	int meters = 29;
	std::cout<<"There are "<<steps(meters)<<" ways to walk "<<meters<<" m \n";
	//for(std::vector<int>::const_iterator i=mem.begin(); i<mem.end(); ++i){
	//	std::cout<<*i<<" ";
	//}
	std::cout<<mem.size()<<"\n";
	return 0;
}

int steps(int distance){
	//int result = 0;
	if(distance<=0){
		//mem.push_back(0);
		return 0;
	}else if(distance<=5){
		//mem.push_back(1);
		//result = mem[1];
		return steps(distance-5) + steps(distance-4) + steps(distance-3) + steps(distance-2) + steps(distance-1)+1;
	}else{
		//mem.push_back(steps(distance-5) + steps(distance-4) + steps(distance-3) + steps(distance-2) + steps(distance-1));
		return steps(distance-5) + steps(distance-4) + steps(distance-3) + steps(distance-2) + steps(distance-1);
		//result = mem[distance];
	}
	//return result;
}
