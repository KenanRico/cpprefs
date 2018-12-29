#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> vec;

void parse();
void process();
void check(const std::string&, const std::string&);
bool checkMovement(const char, const std::string&, const std::string&);
int main(){
	parse();
	process();
	return 0;
}

void parse(){
	int input_count = 0;
	std::cin>>input_count;
	std::string toss = "";
	getline(std::cin,toss);
	while(input_count>0){
		std::string before_after = "";
		getline(std::cin,before_after);
		vec.push_back(before_after);
		--input_count;
	}
}
void process(){
	for(std::vector<std::string>::iterator iter=vec.begin(); iter<vec.end(); ++iter){
		std::stringstream ss(*iter);
		std::string before = "";
		std::string after = "";
		ss>>before>>after;
		check(before, after);
	}
}
void check(const std::string& before, const std::string& after){
	//check length
	if(before.size()==after.size()){
		//check order
		bool match = true;
		int diff = -1;
		std::string::const_iterator beforeI = before.begin();
		std::string::const_iterator afterI = after.begin();
		while(beforeI<before.end()&&afterI<after.end()){
			while(beforeI<before.end()&&*beforeI=='#'){
				++beforeI;
			}
			while(afterI<after.end()&&*afterI=='#'){
				++afterI;
			}
			if(beforeI==before.end()&&afterI==after.end()){
				match = true;
				break;
			}else if(beforeI==before.end()||afterI==after.end()){
				match = false;
				break;
			}else if(*beforeI!=*afterI){
				match = false;
				break;
			}else if(*beforeI==*afterI){
				++beforeI;
				++afterI;
			}else;
		}
		if(match){
			if(checkMovement('A',before,after)&&checkMovement('B',before,after)){
				std::cout<<"Yes"<<std::endl;
			}else{
				std::cout<<"No"<<std::endl;
			}
		}else{
			std::cout<<"No"<<std::endl;
		}
	}else{
		std::cout<<"No"<<std::endl;
	}
}


bool checkMovement(const char bot, const std::string& before, const std::string& after){
	int beforePos = 0;
	int afterPos = 0;
	std::string::const_iterator beforeI = before.begin();
	std::string::const_iterator afterI = after.begin();
	switch(bot){
		case 'A':
			while(beforeI<before.end()&&afterI<after.end()){std::cout<<"1"<<std::endl;
				while(beforeI<before.end()&&*beforeI=='#'){std::cout<<"2"<<std::endl;
					++beforeI;
					++beforePos;
				}
				if(*beforeI=='B'){
					++beforeI;
					++beforePos;
				}else;
				while(afterI<after.end()&&*afterI=='#'){
					++afterI;
					++afterPos;
				}
				if(*afterI=='B'){
					++afterI;
					++afterPos;
				}else;
				if(beforePos<afterPos){
					return false;
				}else{
					++beforeI;
					++beforePos;
					++afterI;
					++afterPos;
				}
			}
			break;
		case 'B':
			beforeI = before.end() - 1;
			afterI = after.end() - 1;
			while(beforeI<before.end()&&afterI<after.end()){std::cout<<"3"<<std::endl;
				while(beforeI>=before.begin()&&*beforeI=='#'){std::cout<<"4"<<std::endl;
					--beforeI;
					++beforePos;
				}
				if(*beforeI=='A'){
					--beforeI;
					++beforePos;
				}else;
				while(afterI>=after.begin()&&*afterI=='#'){
					--afterI;
					++afterPos;
				}
				if(*afterI=='A'){
					--afterI;
					++afterPos;
				}else;
				if(beforePos<afterPos){
					return false;
				}else{
					--beforeI;
					++beforePos;
					--afterI;
					++afterPos;	
				}
			}
			break;
		default:
			std::cout<<"That's not a bot"<<std::endl;
			return false;
	}
	return true;
}
