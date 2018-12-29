#include "tree.h"

#include <string>
#include <iostream>



int main(){
	//init a tree
	Tree tree(Tree::deserialize("6:3 2:1 71:9 66:0 17:1 90:2 0:9"));
	
	//free whole tree, put info into string
	std::string str = tree.serialize();
	std::cout<<str<<"\n";

	//construct a second tree with serialized data
	//Tree tree_2(Tree::deserialize(str));


	return 0;
}
