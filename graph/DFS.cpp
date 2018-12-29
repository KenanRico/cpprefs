#include <iostream>
#include <stack>
#include <string>


bool** graph = nullptr;
int N = 0;
int M = 0;
bool* visited = nullptr;
std::stack<int> stk;

void construct_graph();
int head_node();
void DFS(int, int*);
void destroy_graph();

int main(){
	construct_graph();
	int head = head_node();
	int connected = 0;
	DFS(head, &connected);
	std::cout<<"node"<<head<<" is connected to "<<connected<<" nodes \n";
	destroy_graph();
}

void construct_graph(){
	//parse first line of input into N and M (N = number of vertices, M=number of edges)
	std::cin>>N>>M;
	std::string trash("");
	getline(std::cin, trash);

	//construct graph(NxN) 
	graph = new bool*[N]();
	for(int i=0; i<N; ++i){
		graph[i] = new bool[N]();
		for(int j=0; j<N; ++j){
			graph[i][j] = false;
		}
	}
	//construct visited[N]
	visited = new bool[N]();
	for(int i=0; i<N; ++i){
		visited[i] = false;
	}
	
	//parse next M lines of input into v1 and v2 (indicating two nodes between which an edge exists)
	for(int i=0; i<M; ++i){
		int v1 = 0;
		int v2 = 0;
		std::cin>>v1>>v2;
		getline(std::cin, trash);
		graph[v1][v2] = true;
		graph[v2][v1] = true;
	}
}

int head_node(){
	int head = 0 ;
	std::cin>>head;
	std::string trash("");
	getline(std::cin, trash);
	return head;
}

void DFS(int head, int* connected){
	visited[head] = true;
	++*connected;
	stk.push(head);
	while(!stk.empty()){
		int curr = stk.top();
		stk.pop();
		for(int i=0; i<N; ++i){
			if(graph[curr][i]==true && visited[i]==false){
				++*connected;
				visited[i] = true;
				stk.push(i);
			}else;
		}
	}
}

void destroy_graph(){
	for(int i=0; i<N; ++i){
		delete[] graph[i];
	}
	delete[] graph;
	
	delete[] visited;	
}
