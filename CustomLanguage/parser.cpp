#include "parser.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
Parser::Parser()
:Parsed(false){;}

Parser::Parser(const char* filename)
:Parsed(true){
	this->parse(filename);
}

void Parser:parse(const char* filename){
	std::fstream f(filename);
	while(not_end_of_f){
		std::string line{};
		getline(f,line);
		std::stringstream s(line);
		while(not_end_of_s){
			std::string action{};
			s>>action;
			if(action=="interger"){
				this->parse_integer(s);
			}else if(action=="string"){
				this->parse_string(s);
			}else if(action=="print"){
				this->parse_print(s);
			}else if(action=="function"{
				this->parse_function(s);
			}else{/*more to come*/}
		}
	Parsed = true;
}

void Parser::parse_integer(std::stringstream& s){
/*	std::string key{};
	int val = 0;
	s>>key;
	if(not_end_of_s){
		s>>val;
		Obj<int> obj(key,val);
		this->intVariables.push_back(obj);
	}else{
		Obj<int> obj(key,val);
		this->intVariables.push_back(obj);
	}	
*/
//Above implementation is garbage. Think of how to parse initialization with "=" sign.
	
}
void Parser::parse_string(std::stringstream& s){
/*	std::string key{};
	std::string val{};
	s>>key;
	if(not_end_of_s){
		s>>val;
		Obj<std::string> obj(key,val);
		this->intVariables.push_back(obj);
	}else{
		Obj<std::string> obj(key,val);
		this->intVariables.push_back(obj);
	}	
*/
//Same as said for parse_integer	
}
void Parser::parse_print(std::stringstream& s){
	//Think of a good algorithm to parse things inside and outside of quotes and don't settle with some stupid-ass algorithms.
}
void Parser::parse_function(std::stringstream& s){

}



void Parser::run(){

}

Parser::~Parser(){;}
