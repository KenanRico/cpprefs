#ifndef NODE_H
#define NODE_H
class Node{
	public:
		int value;
		Node* last;
		Node* next;
	public:
		Node(int);
		~Node();
		Node() = delete;
		Node(const Node&) = delete;
		Node& operator=(const Node&) = delete;
};
#endif
