#include "tree.h"
#include "node.h"

#include <string>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iostream>


Tree::Tree(Node* node): root(node){
	
}

Tree::~Tree(){
	//free tree
}

std::string Tree::serialize() const{
	//init string stream
	std::stringstream ss;

	//serialize tree into string stream
	std::queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		//pop queue
		Node* current = q.front();
		q.pop();
		//write node to string
		if(current==nullptr){ //if node is null, write "NULL" to ss and continue
			ss<<"NULL ";
		}else{ //if node is not null, write node's info to ss and queue its children, then free the node
			ss<<current->value()<<":"<<current->link_count()<<" ";
			const std::vector<Node*>& nodes = current->allNodes();
			for(std::vector<Node*>::const_iterator iter=nodes.begin(); iter!=nodes.end(); ++iter){
				q.push(*iter);
			}
			delete current;
		}
	}

	//get string
	std::string str = ss.str();
	return str.substr(0, str.size()-1);
}




Node* Tree::deserialize(const std::string& str){
	//use a queue to achieve inverse-BFS
	/*steps:*/
	//pop queue to get a node
	//for however many links this node has, iterate through them, get next token from string, allocate dynamic Node, and push to queue

	//init head node (return value)
	Node* head = nullptr;

	//init string stream and token string, and assign head node
	std::stringstream ss(str);
	std::string token("");
	if(genNode(head, ss, token)!=INVALID_NODE){
		//continue
	}else{
		return nullptr;
	}
	
	//push head node to queue
	std::queue<Node*> q;
	q.push(head);

	//start BFS
	while(!q.empty()){
		Node* current = q.front();
		q.pop();
		std::vector<Node*>& children = current->allNodes();
		for(std::vector<Node*>::iterator iter=children.begin(); iter!=children.end(); ++iter){
			if(genNode(*iter, ss, token)!=INVALID_NODE){
				q.push(*iter);
			}else{
				return head;
			}
		}
	}

	return head;
}

//returns true if node is successfully allocated, false if no more content in ss or next token in ss is invalid
Tree::nodeType Tree::genNode(Node*& node, std::stringstream& ss, std::string& token){
	Tree::nodeType type = INVALID_NODE;

	if(ss>>token){
		int value = 0;
		int link_count = 0;
		type = processToken(token, value, link_count);
		if(type==REAL_NODE){
			node = new Node(value, link_count);
		}else if(type==NULL_NODE){
			node = nullptr;
		}else if(type==INVALID_NODE){
			//node is invalid
		}
	}else{
		type = INVALID_NODE;
	}

	return type;
}

Tree::nodeType Tree::processToken(std::string& token, int& value, int& count){
	nodeType result = INVALID_NODE;

	int colon_pos = 0;
	if((colon_pos=token.find(':'))!=std::string::npos){
		std::replace(token.begin(), token.end(), ':', ' ');
		std::stringstream ss(token);
		ss>>value>>count;
		result = REAL_NODE;
	}else if(token=="NULL"){
		result = NULL_NODE;
	}else{
		result = INVALID_NODE;
	}

	return result;
}

