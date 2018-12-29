#include "node.h"

#include <vector>


Node::Node(int v, int c): _value(v){
	for(int i=0; i<c; ++i){
		children.push_back(nullptr);
	}
}

Node::~Node(){
	//do nothing
}

int Node::value() const{
	return _value;
}

int Node::link_count() const{
	return children.size();
}

std::vector<Node*>& Node::allNodes(){
	return children;
}


