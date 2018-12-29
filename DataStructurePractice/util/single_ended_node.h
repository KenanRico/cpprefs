
#ifndef SINGLE_ENDED_NODE_H
#define SINGLE_ENDED_NODE_H
class SingleNode{
	public:
		int key;
		SingleNode* next;
	public:
		SingleNode()
		:key(0),next((SingleNode*)0)
		{;}
		SingleNode(const SingleNode& rhs)
		:key(rhs.key),next((SingleNode*)0)
		{;}
		SingleNode& operator=(const SingleNode& rhs){
			this->key = rhs.key;
			return *this;
		}
		~SingleNode(){
			delete next;
		}
};
#endif

