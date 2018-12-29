#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "node.h"

std::vector<std::string> lines;
unsigned int rows = -1;
Node** Head;

void parse();
void populate();
int maxKills();
void freeHead();

int main(){
	parse();
	populate();
	std::cout<<maxKills()<<std::endl;
	freeHead();
	return 0;
}

void parse(){
	int size = 0;
	try{
		std::cin>>size;
		if(size<0){
			throw "Out of range";
		}else{
			rows = size;
		}
	}catch(const char* Err){
		std::cerr<<Err<<std::endl;
	}
	Head = new Node*[size]();
	std::string trash;
	getline(std::cin, trash);
	for(int i=0; i<size; ++i){
		std::string line = "";
		try{
			getline(std::cin, line);
			if(line==""){
				throw "Empty line";
			}else{
				lines.push_back(line);
			}
		}catch(const char* Err){
			std::cerr<<Err<<std::endl;	
		}
	}
}

void populate(){
	if(rows!=lines.size()){
		std::cout<<"Sizes don't match. Something's off."<<std::endl;
	}else{
		for(std::vector<std::string>::const_iterator row=lines.begin(); row<lines.end(); ++row){
			std::stringstream ss(*row);
			int height = 0;
			int row_number = row-lines.begin();
			Node* current = Head[row_number];
			while(ss>>height){
				if(current==(Node*)0){
					Head[row_number] = new Node(height);
				}else{
					current->next = new Node(height);
					current = current->next;
				}
			}

		}

	}
}

int maxKills(){

	return 0;

}

void freeHead(){
	for(unsigned int i=0; i<rows; ++i){
		delete Head[i];
	}
	delete []Head;
}
