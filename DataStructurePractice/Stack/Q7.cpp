//Implemented with linked list

#include "../util/double_ended_node.h"
#include <iostream>
#include <string>

void handle_stack(const std::string&);
void print_stack(const DoubleNode&);
int main(){
	std::string input{""};
	std::cout<<"Insert pattern: ";
	std::cin>>input;
	handle_stack(input);
	return 0;
}
void handle_stack(const std::string& input){
	DoubleNode Root;
	DoubleNode* curr = &Root;
	for(std::string::const_iterator iter=input.begin();iter<input.end();iter++){
		if(*iter=='*'){
			//pop()
			if(curr==&Root)
				break;
			else;
			curr = curr->previous;
			delete curr->next;
			curr->next = (DoubleNode*)0;	
		}else{
			//push(*iter)
			curr->next = new DoubleNode(*iter,curr);
			curr = curr->next;
		}
		print_stack(Root);
	}
}
void print_stack(const DoubleNode& Root){
	for(DoubleNode* curr=Root.next;curr!=(DoubleNode*)0;curr=curr->next){
		std::cout<<curr->key;
	}std::cout<<std::endl;
}
