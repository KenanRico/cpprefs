#include <iostream>
#include <vector>
#include <sstream>
#include <tuple>
#include <string>

int parse(std::string&, std::vector<std::string>&);
void findMatches(const std::string&, const std::vector<std::string>&, int, std::vector<std::string>&);
void printMatches(const std::vector<std::string>&);
std::ostream& operator<<(std::ostream&, const std::vector<std::string>&);
int hash(char);

int main(){
	std::string myname = "";
	std::vector<std::string> girlsnames;
	int K = parse(myname, girlsnames);
	std::vector<std::string> matchedgirlsnames;
	findMatches(myname, girlsnames, K, matchedgirlsnames);
	printMatches(matchedgirlsnames);
	return 0;
}

int parse(std::string& myname, std::vector<std::string>& girlsnames){
	std::cout<<"Your name?"<<std::endl;
	std::cin>>myname;
	std::string garb = "";
	getline(std::cin, garb);
	std::string line = ""; 
	std::cout<<"Girls' names?"<<std::endl;
	getline(std::cin, line);
	std::stringstream ss(line);
	std::string girlname = "";
	while(ss>>girlname){
		girlsnames.push_back(girlname);
	}
	int K = 0;
	std::cout<<"How many to match?"<<std::endl;
	std::cin>>K;
	return K;
}
void findMatches(const std::string& myname, const std::vector<std::string>& girlsnames, int K, std::vector<std::string>& matchedgirlsnames){
	bool myletters[26] = {false};
	for(unsigned int i=0; i<myname.size(); ++i){
		int pos = hash(myname[i]);
		if(!myletters[pos]){
			myletters[pos] = true;
		}else;
	}
	std::vector<std::tuple<int,std::string> > matches_names;
	for(std::vector<std::string>::const_iterator girl=girlsnames.begin(); girl<girlsnames.end(); ++girl){
		int matches = 0;
		for(std::string::const_iterator letter=(*girl).begin(); letter<(*girl).end(); ++letter){
			int pos = hash(*letter);
			if(myletters[pos]){
				++matches;
			}else;
		}
		if(matches_names.size()==0){
			matches_names.push_back(std::make_tuple(matches, *girl));
		}else if(matches>0&&matches_names.size()<(unsigned int)K){
			matches_names.push_back(std::make_tuple(matches, *girl));
		}else{
			int replace_pos = -1;
			int min_match = matches;
			for(unsigned int i=0; i<matches_names.size(); ++i){
				if(min_match>std::get<0>(matches_names[i])){
					replace_pos = i;
					min_match = std::get<0>(matches_names[i]);
				}else;
			}
			if(replace_pos>=0){
				matches_names[replace_pos] = std::make_tuple(matches, *girl);
			}else;
		}		
	}
	for(auto iter=matches_names.begin(); iter<matches_names.end(); ++iter){
		matchedgirlsnames.push_back(std::get<1>(*iter));
	}
}
int hash(char c){
	if(c>=97&&c<=122){
		return (int)(c-97);
	}else if(c>=65&&c<=90){
		return (int)(c+32-97);
	}else{
		std::cerr<<"Invalid character"<<std::endl;
		return -1;
	}
}

void printMatches(const std::vector<std::string>& matchedgirlsnames){
	std::cout<<matchedgirlsnames;	
}
std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& vec){
	for(std::vector<std::string>::const_iterator iter=vec.begin(); iter<vec.end(); ++iter){
		std::cout<<*iter<<" ";
	}std::cout<<std::endl;
	return os;
}





