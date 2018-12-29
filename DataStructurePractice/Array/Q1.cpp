#include <iostream>
#include <algorithm>
int gcd_equals_one(int, int);
int larger(int,int);
int smaller(int, int);
int main(){
	int size1 = 20;
	int size2 = 30;
	int** arr = new int*[size1];
	for(int i=0;i<size1;i++){
		arr[i] = new int[size2]();
//		std::fill_n(arr,size2,-1);
	}
	for(int i=0;i<size1;i++){
		for(int j=0;j<size2;j++){
			arr[i][j] = gcd_equals_one(i,j);
		}
	}
//	std::cout<<gcd_equals_one(100,202)<<std::endl;
	for(int i=0;i<size1;i++){
		for(int j=0;j<size2;j++){
			std::cout<<arr[i][j];
		}
		std::cout<<std::endl;
	}	
	delete []*arr;
	delete []arr;
	return 0;
}
int gcd_equals_one(int i, int j){
	if(i==1||j==1){
		return 1;
	}else if(i==0||j==0){
		return 0;
	}
	return gcd_equals_one(smaller(i,j),larger(i,j)%smaller(i,j));
}//Euclid: gcd of i and j = gcd of larger(i,j) and larger(i,j)-smaller(i,j)
int larger(int i, int j){
	return (i>=j)?i:j;
}
int smaller(int i, int j){
	return (i<j)?i:j;
}
