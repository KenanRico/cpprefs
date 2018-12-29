#include <RapidXML/rapidxml.hpp>
#include <RapidXML/rapidxml_print.hpp>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>
#include <algorithm>


void parseIntoTileSet(rapidxml::xml_node<>*);
void parseIntoImageLayer(rapidxml::xml_node<>*);
void parseIntoLayer(rapidxml::xml_node<>*);
int stringtoint(const char*);
int** stringtomatrix(const char*, int, int);
void commatospace(std::string&);

int main(){
	std::fstream fs("temp/map1.tmx");
	std::vector<char> buffer((std::istreambuf_iterator<char>(fs)), std::istreambuf_iterator<char>());
	buffer.push_back('\0');
	rapidxml::xml_document<> doc;
	doc.parse<0>(&buffer[0]);

	rapidxml::xml_node<>* root = doc.first_node();
	for(rapidxml::xml_node<>* set_layer = root->first_node(); set_layer!=(rapidxml::xml_node<>*)0; set_layer=set_layer->next_sibling()){
		std::string type(set_layer->name());
		if(type=="tileset"){
			parseIntoTileSet(set_layer);
		}else if(type=="imagelayer"){
			parseIntoImageLayer(set_layer);
		}else if(type=="layer"){
			parseIntoLayer(set_layer);
		}else;
	}

	

	/*rapidxml::xml_node<>* node =  doc.first_node()->first_node("layer")->first_node("data");
	std::cout<<node->name()<<std::endl;
	std::string data = node->value();
	//std::cout<<data<<std::endl;
	std::stringstream ss(data);
	std::string row("");
	while(getline(ss, row)){
		std::stringstream sss(row);
		int first = 0;
		sss>>first;
		std::cout<<first<<std::endl;	
	}*/
	fs.close();
	return 0;
}

void parseIntoTileSet(rapidxml::xml_node<>* node){
	std::cout<<"parsing for tileset"<<std::endl;
	int first = stringtoint(node->first_attribute("firstgid")->value());
	int last = first-1 + stringtoint(node->first_attribute("tilecount")->value());
	std::cout<<first<<" "<<last<<std::endl;
}
void parseIntoImageLayer(rapidxml::xml_node<>* node){
	std::cout<<"parsing for imagelayer"<<std::endl;

}
void parseIntoLayer(rapidxml::xml_node<>* node){
	std::cout<<"parsing for layer"<<std::endl;
	int columns = stringtoint(node->first_attribute("width")->value());
	int rows = stringtoint(node->first_attribute("height")->value());
	std::string datastring = node->first_node("data")->value();
	int** data = stringtomatrix(datastring.c_str(), columns, rows);
	for(int row=0; row<rows; ++row){
		for(int col=0; col<columns; ++col){
			std::cout<<data[row][col]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
	delete[] data;
}

int stringtoint(const char* sValue){
	int iValue = 0;
	std::string s(sValue);
	int digit = 0;
	for(std::string::iterator i=s.end()-1; i>=s.begin(); --i){
		int curr = *i-48;
		iValue += (curr>=0&&curr<=9)?curr*powf(10,digit):0;
		if(*i=='-'){
			iValue *= -1;
		}else;
		++digit;
	}
	return iValue;

}
int** stringtomatrix(const char* datastring, int cols, int rows){
	std::stringstream ss(datastring);
	std::string line("");
	int** data = new int*[rows]();
	for(int i=0; i<rows; ++i){
		data[i] = new int[cols]();
	}
	int rownumber = 0;
	int colnumber = 0;
	getline(ss,line);
	while(getline(ss, line)){
		commatospace(line);
		std::stringstream currentline_ss(line);
		while(currentline_ss >> data[rownumber][colnumber++]);
		++rownumber;
		colnumber = 0;
	}
	return data;
}
void commatospace(std::string& line){
	std::replace(line.begin(), line.end(), ',', ' ');
}
