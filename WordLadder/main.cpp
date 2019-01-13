/*Shortest path problem disguised as string manipulation*/

#include <string>
#include <queue>
#include <iostream>


bool** GenGraphFromWords(const std::string&, std::string const *, const std::string&, int);
bool OneCharAway(const std::string&, const std::string&);
int ShortestPath(bool const * const *, int);
void PrintGraph(bool const * const *, int);
void FreeGraph(bool***, int);

int main(){
	//define inputs
	std::string in_word = "hit";
	std::string hidden_words[] = {"hot", "dot", "dog", "lot", "log"};
	std::string out_word = "cogggg";
	int word_count = sizeof(hidden_words)/sizeof(std::string) + 2;

	//generate graph from hidden words
	bool** graph = GenGraphFromWords(in_word, hidden_words, out_word, word_count);
	PrintGraph(graph, word_count);

	//calc shortest dist
	int shortest_path = ShortestPath(graph, word_count);

	std::cout<<"Shortest path from "<<in_word<<" to "<<out_word<<" is "<<shortest_path<<"\n";

	FreeGraph(&graph, word_count);

	return 0;
}

bool** GenGraphFromWords(const std::string& in, std::string const * hidden, const std::string& out, int count){
	bool** graph = new bool*[count];
	for(int i=0; i<count; ++i){
		graph[i] = new bool[count];
	}
	//connect input to rest of graph
	graph[0][0] = true;
	int h_count = count-1;
	for(int i=1; i<h_count; ++i){
		bool connected = OneCharAway(in,hidden[i-1]);
		graph[0][i] = connected;
		graph[i][0] = connected;
	}
	//connect output to rest of graph
	graph[count-1][count-1] = true;
	for(int i=1; i<h_count; ++i){
		bool connected = OneCharAway(out,hidden[i-1]);
		graph[count-1][i] = connected;
		graph[i][count-1] = connected;
	}
	//connect rest of graph
	for(int i=1; i<h_count; ++i){
		for(int j=1; j<h_count; ++j){
			graph[i][j] = OneCharAway(hidden[i-1],hidden[j-1]);
		}
	}
	return graph;
}

bool OneCharAway(const std::string& str1, const std::string& str2){
	bool result = false;
	if(str1==str2){
		result = true;
	}else if(str1.size()==str2.size()){
		int size = str1.size();
		bool already_one = false;
		for(int i=0; i<size; ++i){
			if(str1[i]!=str2[i]){
				if(already_one){
					goto RETURN;
				}else{
					already_one=true;
				}
			}
		}
		result = true;
	}
	RETURN: return result;
}

struct WordDistPair{
	int i;
	int dist;
};
int ShortestPath(bool const * const * graph, int dimension){
	int distance = -1;
	bool* visit = new bool[dimension];
	std::queue<struct WordDistPair> queue({(struct WordDistPair){0, 0}});
	visit[0] = true;
	while(!queue.empty()){
		struct WordDistPair node = queue.front();
		queue.pop();
		if (node.i==dimension-1){
			distance = node.dist;
			break;
		}
		for(int i=0; i<dimension; ++i){
			if(graph[node.i][i]==true && !visit[i]){
				queue.push((struct WordDistPair){i, node.dist+1});
				visit[i] = true;
			}
		}
	}
	delete[] visit;
	return distance;
}

void PrintGraph(bool const * const * graph, int dimension){
	for(int i=0; i<dimension; ++i){
		for(int j=0; j<dimension; ++j){
			std::cout<<graph[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	std::cout<<"\n";
}

void FreeGraph(bool*** graph_p, int count){
	bool**& graph = *graph_p;
	for(int i=0; i<count; ++i){
		delete[] graph[i];
	}
	graph = nullptr;
}
