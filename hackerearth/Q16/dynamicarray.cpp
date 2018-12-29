#include <iostream>
#include "node.h"
#include <sstream>
#include <vector>

void buildArray(Node&);
void printArray(Node&);
void getLongestSequenceInfo(Node&, std::vector<int>&, int&);

int main(){
	Node Array(0);
	buildArray(Array);
	printArray(Array);

	std::vector<int> longestIncSequence;
	int length = 0;
	
	getLongestSequenceInfo(Array, longestIncSequence, length);
	
	std::cout<<"Longest increasing seqeuence: "<<length<<std::endl;
	for(std::vector<int>::iterator i=longestIncSequence.begin(); i<longestIncSequence.end(); ++i){
		std::cout<<*i<<" ";
	}
	std::cout<<std::endl;	

	return 0;
}

void buildArray(Node& Head){
	Node* current = &Head;
	int N = 0;
	int Q = 0;
	std::cin>>N>>Q;
	std::string line("");
	getline(std::cin, line);
	getline(std::cin, line);
	std::stringstream ss(line);
	int x = 0;
	while(ss>>x){
		Node* temp = current;
		current->next = new Node(x);
		current = current->next;
		current->last = temp;
	}
	for(int i=0; i<Q; ++i){
		int action = 0;
		std::cin>>action;
		if(action==1){
			int entry = 0;
			std::cin>>entry;
			Node* temp = current;
			current->next = new Node(entry);
			current = current->next;
			current->last = temp;
			getline(std::cin, line);
		}else if(action==2){
			current = current->last;
			delete current->next;
			current->next = (Node*)0;
			getline(std::cin, line);
		}else{
			std::cerr<<"Impossibru!"<<std::endl;
		}
	}
}

void printArray(Node& Head){
	Node* curr = Head.next;
	std::cout<<"Array looks like: ";
	while(curr!=(Node*)0){
		std::cout<<curr->value<<" ";
		curr = curr->next;
	}
	std::cout<<std::endl;
}

void getLongestSequenceInfo(Node& Head, std::vector<int>& vec, int& length){
	Node* a = Head.next;
	Node* b = Head.next;
	Node* c = Head.next;
	int huh = 0;
	while(c->next!=(Node*)0){
		if(c->next->value > c->value){
			++huh;
		}else{
			if(huh > length){
				length = huh;
				a = b;
			}else;
			b = c;
			huh = 0;
		}
		c = c->next;
	}
	for(int i=0; i<length; ++i){
		vec.push_back(a->value);
		a = a->next;
	}

}
