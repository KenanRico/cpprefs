#include "tree.h"
#include "selectionsort.h"
#include <vector>
#include <iostream>

void printhelper(Node*);
void Tree::Grow(int* arr, int length, std::vector<Node*>& current_generation, int level){
	int* next_first = arr;
	std::cout<<*arr<<std::endl;
	if(length<=0) return; else;
	if(level==0){
		Head->SetValue(*arr);
		next_first++;
		--length;
		Head->left = new Node();
		current_generation.push_back(Head->left);
		Head->right = new Node();
		current_generation.push_back(Head->right);
		Grow(next_first,length,current_generation,level+1);
	}else{
		std::vector<Node*> next_generation;
		for(unsigned int i=0; i<current_generation.size()&&length>0; i++){
			current_generation[i]->SetValue(*next_first);
			next_first++;
			--length;
			current_generation[i]->left = new Node;
			next_generation.push_back(current_generation[i]->left);
			current_generation[i]->right = new Node;
			next_generation.push_back(current_generation[i]->right);
		}
		Grow(next_first,length,next_generation,level+1);
	}
}
Tree::Tree(int* arr, unsigned int length)
:Head(new Node(0)){
	std::vector<Node*> generations;
	std::cout<<length<<std::endl;
	Grow(arr, length, generations, 0);
//	Grow(arr, 8, generations, 0);
}
void Tree::PrintTree(){
	printhelper(this->Head);
}
Tree::~Tree(){
	delete this->Head;
}

void printhelper(Node* n){
	if(n==nullptr){
		return;
        }else{
		std::cout<<n->GetValue()<<" ";
		printhelper(n->left);	
		printhelper(n->right);	
	}
}
