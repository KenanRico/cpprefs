#include "node.h"

Node::Node(int x): value(x), last((Node*)0), next((Node*)0){
	;
}
Node::~Node(){
	delete next;
}
