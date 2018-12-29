#include <iostream>
#include <sstream>
#include <string>

int twos = 0;
int fives = 0;
void ctf(int);
int min(int,int);
int main(int argc, char** argv){
	int last = -1;
	std::stringstream ss(*(argv+1));
	ss>>last;
	for(int i=0;i<=last;++i){
		ctf(i);
	}
	int zeros = min(twos,fives);
	std::cout<<"number of zeros = "<<zeros<<std::endl;
	return 0;
}
void ctf(int number){
	while(number>1){
		if(number%2==0||number%5==0){
			if(number%2==0){
				twos++;
				number/=2;
			}else;
			if(number%5==0){
				fives++;
				number/=5;
			}else;
		}else{
			break;
		}
	}
}
int min(int a, int b){
	return (a<=b)?a:b;
}
