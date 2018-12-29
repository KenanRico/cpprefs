#include <iostream>

#ifndef NODE_H
#define NODE_H
class Node{
	private:
		static int count;
	public:
		int key;
		Node* next;
	public:
		Node()
		:key(0),next((Node*)0)
		{std::cout<<++count<<std::endl;}
		Node(const Node& rhs)
		:key(rhs.key),next((Node*)0)
		{std::cout<<++count<<std::endl;}
		Node(int _key)
		:key(_key),next((Node*)0)
		{std::cout<<++count<<std::endl;}
		Node& operator=(const Node& rhs){
			this->key = rhs.key;
			return *this;
		}
		~Node(){
				delete next;
				--count;
			std::cout<<count<<" "<<key<<std::endl;
		}
};
int Node::count = 0;
#endif

