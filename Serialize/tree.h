#include "node.h"

#include <string>


#ifndef TREE_H
#define TREE_H

class Tree{
	private:
		typedef enum NodeType{ NULL_NODE, REAL_NODE, INVALID_NODE } nodeType;
	private:
		Node* root;
	public:
		Tree(Node*);
		~Tree();
	private:
		Tree() = delete;
		Tree(const Tree&) = delete;
		Tree& operator=(const Tree&) = delete;
	public:
		//serialize
		std::string serialize() const;
		//deserialize
		static Node* deserialize(const std::string&);
		static nodeType genNode(Node*&, std::stringstream&, std::string&);
		static nodeType processToken(std::string&, int&, int&);
};

#endif
