#include <iostream>
#include <tuple>

std::tuple<int,int,int> getSpecs();
void fillArray(int*,int,int,int);
void addActions(int*,int,int);

int main(){
	std::tuple<int,int,int> specs = getSpecs();
	int rows = std::get<0>(specs);
	int cols = std::get<1>(specs);
	int num_adds = std::get<2>(specs);
	int** arr = new int[rows][cols];
	fillArray(arr,rows,cols);
	addActions(arr,rows,cols);
	delete [][]arr;
	return 0;
}
std::tuple<int,int,int> getSpecs(){
	int N = 0;
	int M = 0;
	int K = 0;
	std::cout<<"#rows, #columns, #additions"<<std::endl;
	std::cin>>N>>M>>K;
	try{
		if(N<1||M<1||K<1||N>1000||M>1000||K>1000){
			throw "Input out of range";
		}else;
	}catch(const char* errmsg){
		std::cerr<<errmsg<<std::endl;
		return std::make_tuple(-1,-1,-1);
	}
	return std::make_tuple(N,M,K);
}
void fillArray(int* arr, int row, int col){
	for(int i=0; i<row; ++i){
		for(int j=0; i<col; ++j){
			std::cin>>arr[i][j];
			char trash = '-';
			getline(std::cin, trash);
		}
	}
}
void addActions(int* arr, int row, int col, int adds){
	int R=0;
	int C=0;
	int S=0;
	int D=0;
	while(adds>0){
		std::cin>>R>>C>>S>>D;
		for(int i=R; i<min(row,R+S); ++i){
			for(int j=C; j<(col,C+S); ++j){
				arr[i][j]+=D;
			}
		}
		--adds;
		char trash = '-';
		getline(std::cin, trash); 
	}
}

