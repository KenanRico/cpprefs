#include "node.h"
#include <iostream>
#include <tuple>

const int hash_range = 10;
int arr[] = {31,-2,39,10,9,88,-2,0,11,-19, 8, 3, -92};

void printArray();
int hash(int);
Node** makeTable();
void freeTable(Node**);
std::tuple<bool,int,int> pairExists(int, Node**);

int main(){
	printArray();
	int input = 0;
	std::cin>>input;
	Node** table = makeTable();
	std::tuple<bool,int,int> found = pairExists(input, table);
	if(std::get<0>(found)){
		std::cout<<"Found pair of integer that add up to input: "<<std::get<1>(found)<<" and "<<std::get<2>(found)<<std::endl;
	}else{
		std::cout<<"Did not find pair of integer that add up to input"<<std::endl;
	}
	freeTable(table);	
	return 0;
}
void printArray(){
	std::cout<<"Array contains: ";
	for(unsigned int i=0; i<sizeof(arr)/sizeof(int); ++i){
		std::cout<<arr[i]<<" ";
	}std::cout<<std::endl;
}
int hash(int number){
	int num = (number>=0)?number:-number;
	return num%hash_range;
}
Node** makeTable(){
	Node** table = new Node*[hash_range];
	for(unsigned int i=0;i<sizeof(arr)/sizeof(int);++i){
		if(table[hash(arr[i])]==(Node*)0){
			table[hash(arr[i])] = new Node(arr[i]);
		}else{
			Node* curr = table[hash(arr[i])];
			while(curr->next!=(Node*)0){
				curr = curr->next;
			}
			curr->next = new Node(arr[i]);
		}

	}
	return table;
}
void freeTable(Node** table){
	for(int i=0; i<hash_range; ++i){
		delete table[i];
	}
	delete[] table;
}
std::tuple<bool,int,int> pairExists(int input, Node** table){
	for(unsigned int i=0;i<sizeof(arr)/sizeof(int);++i){
		int diff = input-arr[i];
		int slot = hash(diff);
		Node* curr = table[slot];
		//traverse list and check for diff
		while(curr!=(Node*)0){
			if(curr->key==diff){
				return std::make_tuple(true,arr[i],diff);
			}else;
			curr = curr->next;
		}
	}	
	return std::make_tuple(false,0,0);
}
