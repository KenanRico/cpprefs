#include <iostream>
#include <vector>
#include "node.h"
#include <sstream>
void random_distribute(std::vector<int>::const_iterator, const std::vector<int>::iterator, Node*, bool);
void sum_each_level(std::vector<int>&, Node*, std::vector<int>::size_type);
void tempppp(std::vector<int>::const_iterator, const std::vector<int>::iterator, Node*, const std::vector<Node*>&);
int main(){
	std::string line = "";
	std::vector<int> vec;
	try{
		getline(std::cin,line);
		if(line.empty()){
			throw "Empty entry";
		}else;
		std::istringstream sstrm(line);
		while(sstrm){
			int temp;
			sstrm>>temp;
			vec.push_back(temp);
		}
	}catch(const char* message){
		std::cerr<<message<<std::endl;
		return -1;
	}
	Node Root(vec[0]);
/*	Root.left = new Node(20);
	Root.right = new Node(49);
	Root.left->left = new Node(-9);
	Root.left->right = new Node(82);
	Root.right->right = new Node(-102);
*/
	std::vector<Node*> nodes = {&Root};
	std::vector<int>::const_iterator iter = vec.begin();
	tempppp(iter+1, vec.end(), &Root, nodes);
	std::vector<int> sums;
	sum_each_level(sums, &Root, 0);
	for(const int& x: sums){
		std::cout<<x<<" ";
	}std::cout<<std::endl;	
	return 0;
}

void random_distribute(std::vector<int>::const_iterator iter, const std::vector<int>::iterator vec_end, Node* Head, bool balanced){
	Node* current = Head;
	if(iter!=vec_end){
		current->SetValue(*iter);
		iter++;
	}else{
		return;
	}
	if(balanced){
		if(current->left!=0&&current->right!=0){
			random_distribute(iter, vec_end, current->left, true);
			random_distribute(iter, vec_end, current->right, true);
		}
		else if(current->left!=0)
			random_distribute(iter, vec_end, current->left, false);
		else if(current->right!=0)
			random_distribute(iter, vec_end, current->right, false);
		else
			std::cout<<"Very strange situation"<<std::endl;
	}else{
//		random_distribute(iter, vec_end, current->parent, true);
	}
}

void tempppp(std::vector<int>::const_iterator iter, const std::vector<int>::iterator vec_end, Node* Head, const std::vector<Node*>& nodes){
	std::vector<Node*> current_level;
	for(Node* x: nodes){
		if(iter!=vec_end){
			x->left = new Node(*iter);
			iter++;
		}else return;
		if(iter!=vec_end){
			x->right = new Node(*iter);
			iter++;
		}else return;
		current_level.push_back(x->left);
		current_level.push_back(x->right);
	}
	tempppp(iter, vec_end, Head, current_level);
}


void sum_each_level(std::vector<int>& vec, Node* current, std::vector<int>::size_type level){
	if(level+1>vec.size()){
		vec.push_back(current->GetValue());
	}else{
		vec[level]+=current->GetValue();
	}
	if(current->left!=(Node*)0){
		sum_each_level(vec,current->left,level+1);
	}else;
	if(current->right!=(Node*)0){
		sum_each_level(vec,current->right,level+1);
	}else;
}

