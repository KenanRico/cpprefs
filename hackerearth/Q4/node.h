#include <tuple>

#ifndef NODE_H
#define NODE_H
class Node{
	public:
		std::tuple<int,int> key;
		Node* next;
		bool keepnext;
	public:
		Node()
		:key(0,0),next((Node*)0),keepnext(false)
		{;}
		Node(const Node& rhs)
		:key(rhs.key),next((Node*)0),keepnext(false)
		{;}
		Node(std::tuple<int,int> _key)
		:key(_key),next((Node*)0),keepnext(false)
		{;}
		Node& operator=(const Node& rhs){
			this->key = rhs.key;
			return *this;
		}
		~Node(){
			if(!keepnext){
				delete next;
			}else;
		}
		void setKeepNext(){
			this->keepnext = true;
		}
};
#endif

