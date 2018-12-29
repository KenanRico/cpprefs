#include <iostream>
#include <string>
#include <vector>


void getCombos(std::vector<std::string>&, const std::vector<std::string>&);


int main(){
	//define keys
	std::string keys[10];
	keys[0] = "_";
	keys[1] = "abc";
	keys[2] = "def";
	keys[3] = "ghi";
	keys[4] = "jkl";
	keys[5] = "mno";
	keys[6] = "pqrs";
	keys[7] = "tuv";
	keys[8] = "wxyz";
	keys[9] = " ";
	//get input
	std::string input = "137";
	//get all potential letter combos
	std::vector<std::string> pressed;
	for(std::string::iterator c=input.begin(); c!=input.end(); ++c){
		int key = *c - 48;
		pressed.push_back(keys[key]);
	}
	std::vector<std::string> combos;
	getCombos(combos, pressed, 0);

	return 0;
}


void getCombos(std::vector<std::string>& combo, const std::vector<std::string>& pressed, int i){
	if(i<pressed.size()){
		for(int j=0; j<pressed[i].size(); ++i){
			
		}
	}else;
}
