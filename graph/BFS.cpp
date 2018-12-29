#include <iostream>
#include <queue>

std::queue<char> myQueue;
struct Graph{
	bool edge[9][9] = {
		{0,1,0,0,1,1,0,0,0},
		{1,0,1,0,0,0,0,0,0},
		{0,1,0,1,0,0,1,0,1},
		{0,0,1,0,0,0,0,0,0},
		{1,0,0,0,0,1,0,0,0},
		{1,0,0,0,1,0,1,1,0},
		{0,0,1,0,0,1,0,0,1},
		{0,0,0,0,0,1,0,0,1},
		{0,0,1,0,0,0,1,1,0}
	};
	bool visited[9];
	int value[9];
};

struct Graph graph;

void BFS(char);
int nodeI(char);
char nodeC(int);

int main(){
	BFS('D');
	return 0;
}

void BFS(char root){
	//start with vertex D
	myQueue.push(root);
	graph.visited[nodeI(root)] = true;
	while(!myQueue.empty()){
		char v = myQueue.front();
		std::cout<<v<<"\n";
		myQueue.pop();
		for(int i=0; i<9; ++i){
			if(graph.edge[nodeI(v)][i] && !graph.visited[i]){
				myQueue.push(nodeC(i));
				graph.visited[i] = true;
			}else;
		}
	}
}

int nodeI(char c){
	return (int)(c-'A');
}
char nodeC(int i){
	return (char)('A'+i);
}
