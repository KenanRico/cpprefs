#include "node.h"
#include <vector>

#ifndef TREE_H
class Tree{
	private:
		Node* Head;
		void Grow(int*,int,std::vector<Node*>&, int);
	public:
		Tree() = delete;
		Tree(const Tree&) = delete;
		Tree& operator=(const Tree&) = delete;
		Tree(int*, unsigned int);
		void PrintTree();
		~Tree();
};
#define TREE_H
#endif
