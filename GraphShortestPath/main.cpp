#include <queue>
#include <vector>


void getParams(int*, int*);
int** getGraph(int, int);
std::vector<int>* getPathInfo(int);
void computeShortestPath(int const **, std::vector<int>*, int);
void freeArrays(int**, std::vector<int>*, int);

class Node;


int main(){
	int N = 0;
	int M = 0;
	getParams(&N, &M);
	int** graph = getGraph(N, M);
	std::vector<int>* path_info = getPathInfo(N);
	computeShortestPaths(graph, path_info, N);


	freeArrays(graph, path_info, N);
	return 0;
}


void getParams(int* n, int* m){
	*n = 9;
	*m = 12;
}

int** getGraph(int n, int m){
	int** graph = nullptr;
	graph = new int*[n](); //init all to nullptr
	for(int i=0; i<n; ++i){
		graph[i] = new int[n](); //init all to 0
	}
}

std::vector<int>* getPathInfo(int N){
	std::vector<int>* path_info = nullptr; /*(std::vector<int>*)0*/
	path_info = new std::vector<int>[N];
}

void computeShortestPaths(int const ** graph, std::vector<int>* path_info, int N){
	//declare data structure to store distances from source node
	std::vector<Node> nodes;
	nodes.push_back(Node(0, 0, true));
	for(int i=1; i<N; ++i){
		nodes.push_back(Node(i, -1, false));
	}
	//declare priority queue to process nodes
	std::priority_queue<Node*> q;
	q.push(&nodes[0]);
	for(!visitedAll(nodes)){
		Node& current = *(q.front());
		q.pop();
		current.visited = true;
		for(int i=0; i<N; ++i){
			if(graph[current.ID][i]>0 && current.distance+graph[current.ID][i]<nodes[i].distance){
				nodes[i].distance = current.distance+graph[current.ID][i];
				q.push(&nodes[i]);
				path_info[i] = path_info[current.ID];
				path_info[i].push_back(current.ID);
			}else;
		}
	}
	
}

void freeArrays(int** graph, std::vector<int>* path_info, int N){
	///delete graph
	for(int i=0; i<N; ++i){
		delete[] graph[i];
	}
	delete[] graph;

	///delete path_info
	delete[] path_info;
}






class Node{
	public:
		int ID;
		int distance;
		bool visited;
	public:
		Node(int id, int dis, int v){
			ID = id;
			distance = dis;
			visited = v;
		}
		Node(const Node& rhs): ID(rhs.ID), distance(rhs.distance), visited(rhs.visited){
			//nothing
		}
		~Node(){
			//nothing
		}
		Node& operator=(const Node& rhs){
			this->ID = rhs.ID;
			this->distance = rhs.distance;
			this->visited = rhs.visited;
			return *this;
		}
	private:
		Node() = delete;
	public:
		bool operator<(const Node& rhs){
			return this->distance<rhs.distance;
		}
}
