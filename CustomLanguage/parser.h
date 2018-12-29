#include <vector>
#include <iostream>
#include "obj.h"
#include <sstream>

#ifndef PARSER_H
#define PARSER_H
class Parser{
	private:
		std::vector<Obj<int> > intVariables;
		std::vector<Obj<std::string> > stringVariables;
		std::vector<Func> Functions;	
		bool Parsed;
		void parse_integer(std::stringstream&);
		void parse_string(std::stringstream&);
		void parse_print(std::stringstream&);
		void parse_function(std::stringstream&);
	public:
		Parser();
		Parser(const char*);
		void parse(const char*);
		void run();
		~Parser();
		Parser(const Parser&) = delete;
		Parser& operator=(const Parser&) = delete;
};
#endif
