
#ifndef DOUBLE_ENDED_NODE_H
#define DOUBLE_ENDED_NODE_H
class DoubleNode{
	public:
		char key;
		DoubleNode* next;
		DoubleNode* previous;
	public:
		DoubleNode()
		:key('_'),next((DoubleNode*)0),previous((DoubleNode*)0)
		{;}
		DoubleNode(char x, DoubleNode* prev)
		:key(x),next((DoubleNode*)0),previous(prev)
		{;}
		DoubleNode(const DoubleNode& rhs)
		:key(rhs.key),next((DoubleNode*)0),previous((DoubleNode*)0)
		{;}
		DoubleNode& operator=(const DoubleNode& rhs){
			this->key = rhs.key;
			return *this;
		}
		~DoubleNode(){
			delete next;
//			delete previous;
		}
};
#endif

