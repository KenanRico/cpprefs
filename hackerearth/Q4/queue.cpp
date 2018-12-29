#include "node.h"
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <sstream>

std::vector<std::string> input;
Node Head;

void parseInput();
void operateQueue();
void push(std::tuple<int,int>);
void pop();
void printQueue();
std::ostream& operator<<(std::ostream&, std::tuple<int,int>);

int main(){
	parseInput();
	operateQueue();
	printQueue();
	return 0;
}

void parseInput(){
	int count = -1;
//	char useless;
	std::string dumbbitch = "";
	if(std::cin>>count||count>0){
		getline(std::cin, dumbbitch);
		std::cout<<"Enter "<<count<<" inputs below:"<<std::endl;
	}else{
		std::cout<<"Input failed you know why"<<std::endl;
		return;
	}
	while(count>0){
		std::string line = "";
		getline(std::cin, line);
		input.push_back(line);
		--count;
//		std::cout<<input[0]<<std::endl;
	}
}
void operateQueue(){
	for(std::vector<std::string>::const_iterator iter=input.begin(); iter<input.end(); ++iter){
		std::stringstream ss(*iter);
		char action='-';
		ss>>action;
		if(action=='E'){
			int school = 0;
			int roll = 0;
			if(ss>>school>>roll){
				try{
					if(school>4||school<1){
						throw "school";
					}else if(roll>50000||roll<1){
						throw "roll";
					}else;
					std::tuple<int,int> student = std::make_tuple(school, roll);
					push(student);	
				}catch(const char* err){
					std::cerr<<err<<" out of range"<<std::endl;
					return;
				}
			}else;
		}else if(action=='D'){
			pop();
		}else{
			std::cerr<<"Unrecognized action"<<std::endl;
			return;
		}
	}
}
void push(std::tuple<int,int> student){
	Node* curr = &Head;
	int school = std::get<0>(student);	
	while(curr!=(Node*)0){
		if(curr->next==(Node*)0){
			curr->next = new Node(student);
			break;
		}else if(std::get<0>(curr->next->key)>school){
			Node* nxt = curr->next;
			curr->next = new Node(student);
			curr->next->next = nxt;
			break;	
		}else{
			curr = curr->next;
		}
	}
}
void pop(){
	Node* curr = Head.next;
	if(curr!=(Node*)0){
		Node* nxt = curr->next;
		curr->setKeepNext();
		Head.next = nxt;
		delete curr;
	}else{
		std::cerr<<"Queue is empty"<<std::endl;
		return;
	}
}
void printQueue(){
	Node* curr = Head.next;
	while(curr!=(Node*)0){
		std::cout<<curr->key<<" ";
		curr = curr->next;
	}std::cout<<std::endl;
}
std::ostream& operator<<(std::ostream& os, std::tuple<int,int> key){
	os<<"("<<std::get<0>(key)<<","<<std::get<1>(key)<<")";
	return os;
}
