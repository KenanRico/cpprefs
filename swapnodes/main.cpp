#include <iostream>


struct Node{
	int val;
	struct Node* next;
};


void generateList(struct Node*&);
void printList(struct Node const *);
void doSwaps(struct Node*);
void destroyList(struct Node*);

int main(){
	struct Node* root = nullptr;
	generateList(root);
	printList(root);
	doSwaps(root);
	printList(root);
	destroyList(root);

	return 0;
}

void generateList(struct Node*& root){
	int array[11] = {2, 8, 0, 4, 11, 3, 19, 9, 2, 87, 4};
	root = new struct Node;
	root->val = array[0];
	root->next = new struct Node;
	struct Node* p = root;
	for(unsigned int i=1; i<11; ++i){
		p = p->next;
		p->val = array[i];
		p->next = new struct Node;
	}
	delete p->next;
	p->next = nullptr;
}

void printList(struct Node const * p){
	while(p!=nullptr){
		std::cout<<p->val<<" ";
		p = p->next;
	}
	std::cout<<"\n";
}

void doSwaps(struct Node* n){
	struct Node* left = &(*n);
	struct Node* right = n->next;
	struct Node* prev = nullptr;
	while(left!=nullptr && right!=nullptr){
		left->next = right->next;
		right->next = left;
		if(prev!=nullptr){
			prev->next = right;
			prev = left;
		}else;
		left+=2;
		right+=2;
	}
}

void destroyList(struct Node* n){
	while(n!=nullptr){
		struct Node* temp = n;
		n=n->next;
		delete temp;
	}
}
