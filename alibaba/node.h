
#ifndef SINGLE_ENDED_NODE_H
#define SINGLE_ENDED_NODE_H
class Node{
	public:
		int key;
		Node* next;
	public:
		Node()
		:key(0),next((Node*)0)
		{;}
		Node(int _key)
		:key(_key),next((Node*)0)
		{;}
		Node(const Node& rhs)
		:key(rhs.key),next((Node*)0)
		{;}
		Node& operator=(const Node& rhs){
			this->key = rhs.key;
			return *this;
		}
		~Node(){
			delete next;
		}
};
#endif

