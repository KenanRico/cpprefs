
#include <vector>


#ifndef NODE_H
#define NODE_H

class Node{
	private:
		int _value;
		std::vector<Node*> children;
	public:
		Node(int, int);
		~Node();
	private:
		Node() = delete;
		Node(const Node&) = delete;
		Node& operator=(const Node&) = delete;
	public:
		int value() const;
		int link_count() const;
		std::vector<Node*>& allNodes();
};

#endif
