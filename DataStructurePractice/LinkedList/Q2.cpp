#include "../util/single_ended_node.h"
#include <iostream>
//----------------------------------------
void movenexttofront(SingleNode* const Head, SingleNode* const curr){
	SingleNode* temp = curr->next;
	if(temp==(SingleNode*)0){
		std::cout<<"Next node is nullptr"<<std::endl;
		return;
	}else{
		curr->next = curr->next->next;
		temp->next = Head->next;
		Head->next = temp;
	}
}
//--------------------------------------------
void printlist(const SingleNode* const);
int main(){
	SingleNode Root;
	SingleNode* Head = &Root;
	SingleNode* curr = Head;
	for(int i=0;i<15;i++,curr=curr->next){
		curr->key = i;
		curr->next = new SingleNode;
//		curr = curr->next;
	}
	movenexttofront(Head, Head->next->next->next);
	printlist(Head);
	return 0;
}
void printlist(const SingleNode* const Head){
	for(const SingleNode* curr=Head;curr!=(SingleNode*)0;curr=curr->next){
		std::cout<<curr->key<<" ";
	}std::cout<<std::endl;
}

