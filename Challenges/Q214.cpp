#include <iostream>
#include <vector>

std::vector<int> list;
const int zero = 0;

int input();
int phi(int,int);
int phi_2(int);
int gcd(int,int);
int larger(int,int);
int smaller(int,int);
void create_chain();
void print(const std::vector<int>&);

int main(){
	list.push_back(input());
//	create_chain();
	print(list);
	return 0;
}
int input(){
	int input = -1;
	std::cout<<"Phi Input: "<<std::endl;
	std::cin>>input;	
	return input;
}
int phi(int input,int count){
	if(gcd(list[0],input)==1){
		count++;		
	}else;
	if(--input<1){
		return count;
	}else{
		return phi(input, count);
	}
}
int phi_2(int input){
	if(input>1){
		if(gcd(*(list.end()-1),input)==1){
			return phi_2(input-1)+1;		
		}else{
			return phi_2(input-1);
		}
	}else if(input==1){
		return 1;
	}else{
		return 0;
	}
}
int gcd(int a, int b){
	//gcd(a,b) = gcd((larger(a,b)-smaller(a,b)),smaller(a,b)) = gcd((larger(a,b)%smaller(a,b)),smaller(a,b))
	//i.e. gcd(72,68)=gcd(68,4)=gcd(4,0)=4
	if(a==0||b==0)
		return (a==0)?b:a;
	else if(a==1||b==1)
		return 1;
	else
		return gcd((larger(a,b)%smaller(a,b)),smaller(a,b));
}
int larger(int a, int b){
	return (a>=b)?a:b;
}
int smaller(int a, int b){
	return (a<b)?a:b;
}
void create_chain(){
	int curr = *list.begin();
	while((curr=phi_2(curr))>1){
		list.push_back(curr);
		std::cout<<curr<<std::endl;
	}

/*	while(curr>1){
		std::cout<<"in create_chain"<<std::endl;
		list.push_back(curr);
		curr=phi(curr,zero);
	}
*/
}
void print(const std::vector<int>& vec){
	for(std::vector<int>::const_iterator iter=vec.begin();iter<vec.end();iter++){
		std::cout<<*iter<<" ";
	}std::cout<<std::endl;
}

