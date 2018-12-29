

#ifndef NODE_H
#define NODE_H
class Node{
	private:
		int value;
	public:
//--------------------------------public pointers--------------------
		Node* left;
		Node* right;
//--------------------------------public functions--------------------------
		Node();
		Node(int);
		Node(const Node&);
		Node& operator=(const Node&);
		void SetValue(int);
		int GetValue();
		~Node();
};
#endif
