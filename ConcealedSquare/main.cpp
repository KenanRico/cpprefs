#include <iostream>
#include <vector>
#include <math.h>
//1_2_3_4_5_6_7_8_9
bool Matched(unsigned long);
int main(){
	unsigned long number = 100000000;
	while(!Matched(pow(number+3,2))&&!Matched(pow(number+7,2))){
		number+=10;
	}
	std::cout<<number<<std::endl;
	return 0;
}
bool Matched(unsigned long number){
/*	for(int i=9;i>=1;--i){
		if(number==0)
			return false;
		else;
		if((number-i)%10!=0)
			return false;
		else;
*/
	std::vector<int> vec;
	while(number>0){
		vec.push_back(number%10);
		number%=10;
	}
	int check = 9;
	for(std::vector<int>::iterator iter=vec.begin();iter<vec.end();iter+=2){
		if(iter==vec.end())
			return false;
		else;
		if(*iter!=check)
			return false;
		else;
		--check;
	}
	return true;
}
