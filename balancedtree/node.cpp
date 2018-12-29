#include "node.h"

Node::Node()
:value(0),left((Node*)0),right((Node*)0){;}

Node::Node(int val)
:value(val),left((Node*)0),right((Node*)0){;}

//use copy constructor with caution (might not be working properly!)
Node::Node(const Node& rhs)
:value(rhs.value),left(new Node(*(rhs.left))), right(new Node(*(rhs.right))){;}
//use assignment operator with caution (might not be working properly!)
Node& Node::operator=(const Node& rhs){
	this->value = rhs.value;
	this->left = new Node(*(rhs.left));
	this->right = new Node(*(rhs.right));
	return *this;
}

void Node::SetValue(int val){
	this->value = val;
}

int Node::GetValue(){
	return this->value;
}

Node::~Node(){
	delete this->left;
	delete this->right;
}



