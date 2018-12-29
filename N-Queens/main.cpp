#include <iostream>


void initBoard(int**&, int);
void destroyBoard(int**, int);
void printBoard(int const **, int);
void reformatBoard(int**, int);

bool populateBoard(int**, int, int);
void placeQueen(int**, int, int, int);
void removeQueen(int**, int, int, int);


int main(){

	int N = 8;
	int** board = nullptr;

	initBoard(board, N);
	bool result = populateBoard(board, N, 0);
	if(result){
		reformatBoard(board, N);
		printBoard((int const **)board, N);
	}else{
		std::cout<<"Cannot find solution! \n";
	}
	destroyBoard(board, N);

	return 0;
}


void initBoard(int**& board, int N){
	board = new int*[N]();
	for(int i=0; i<N; ++i){
		board[i] = new int[N]();
	}
}
void destroyBoard(int** board, int N){
	for(int i=0; i<N; ++i){
		delete[] board[i];
	}
	delete[] board;
}
void printBoard(int const ** board, int N){
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			std::cout<<board[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	std::cout<<"\n";
}
void reformatBoard(int** board, int N){
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			if(board[i][j]<0){
				board[i][j] = 0;
			}else;
		}
	}
}


bool populateBoard(int** board, int N, int index){
	bool result = false;
	//check which row is being populated
	if(index>=N){
		result = true;
	}else{
	//check every box on "index"th row and try placing a queen on the empty ones
		for(int i=0; i<N; ++i){
			if(board[index][i]==0){
				//update board's values after placing queen in box (index, i)
				placeQueen(board, N, index, i);
				//assign "result" to result of populateBoard()
				result = populateBoard(board, N, index+1);
				/*if result==true, meaning that placing a queen in box (index, i) can lead to a correct solution, 
				  stops iterating; otherwise, undo the changes and keeps on iterating*/
				if(result){
					break;
				}else{
					removeQueen(board, N, index, i);
				}
			}else;
		}
	}
	return result;
}

void placeQueen(int** board, int N, int row, int col){
	//cross out all reachable boxes from this queen
	for(int i=0; i<N; ++i){
		--board[row][i];
	}
	for(int i=0; i<N; ++i){
		--board[i][col];
	}
	for(int i=0; i<N; ++i){
		int r = row-i;
		int c = col-i;
		if(0<=r && r<N && 0<=c && c<N){
			--board[r][c];
		}else{
			break;
		}
	}
	for(int i=0; i<N; ++i){
		int r = row-i;
		int c = col+i;
		if(0<=r && r<N && 0<=c && c<N){
			--board[r][c];
		}else{
			break;
		}
	}
	for(int i=0; i<N; ++i){
		int r = row+i;
		int c = col+i;
		if(0<=r && r<N && 0<=c && c<N){
			--board[r][c];
		}else{
			break;
		}
	}
	for(int i=0; i<N; ++i){
		int r = row+i;
		int c = col-i;
		if(0<=r && r<N && 0<=c && c<N){
			--board[r][c];
		}else{
			break;
		}
	}
	//place queen
	board[row][col] = 1;
}

void removeQueen(int** board, int N, int row, int col){
	//recover all reachable boxes from this queen
	for(int i=0; i<N; ++i){
		++board[row][i];
	}
	for(int i=0; i<N; ++i){
		++board[i][col];
	}
	for(int i=0; i<N; ++i){
		int r = row-i;
		int c = col-i;
		if(0<=r && r<N && 0<=c && c<N){
			++board[r][c];
		}else{
			break;
		}
	}
	for(int i=0; i<N; ++i){
		int r = row-i;
		int c = col+i;
		if(0<=r && r<N && 0<=c && c<N){
			++board[r][c];
		}else{
			break;
		}
	}
	for(int i=0; i<N; ++i){
		int r = row+i;
		int c = col+i;
		if(0<=r && r<N && 0<=c && c<N){
			++board[r][c];
		}else{
			break;
		}
	}
	for(int i=0; i<N; ++i){
		int r = row+i;
		int c = col-i;
		if(0<=r && r<N && 0<=c && c<N){
			++board[r][c];
		}else{
			break;
		}
	}
	//remove queen
	board[row][col] = 0;
}
