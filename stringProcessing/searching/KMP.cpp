#include <iostream>
#include <fstream>

void getText(std::string&);
void getPattern(std::string&);
int* getPrefixArray(const std::string&, unsigned int);
int firstEncounter(const std::string&, const std::string&, const int*, unsigned int);


int main(){
	std::string text("");
	getText(text);
	std::string pattern("");	
	getPattern(pattern);
	int* prefix = getPrefixArray(pattern, pattern.size());
	int firstPos = firstEncounter(text, pattern, prefix, pattern.size());
	delete prefix;
	std::cout<<"Pattern is first found at "<<firstPos<<" character \n";
	return 0;
}

void getText(std::string& text){
	std::ifstream fs("text.txt", std::ios::in);
	std::string line("");
	while(getline(fs, line)){
		text += line;
	}
	fs.close();
}

void getPattern(std::string& pattern){
	std::cout<<"what pattern to look for? \n";
	std::cin>>pattern;
}

int* getPrefixArray(const std::string& pattern, unsigned int size){
	int* prefix = new int[size]();
	


	return prefix;
}

int firstEncounter(const std::string& text, const std::string& pattern, const int* prefix){
	int position = -1;
	int p1 = 0;
	while(text.size()-p1 > pattern.size()){
		int p2 = 0;
		while(p2<pattern.size()){
			if(text[p1]==pattern[p2]){
				++p1;
				++p2;
			}else{
				break;
			}
		}
		if(p2==pattern.size()-1){
			position = p1;
			break;
		}else{
			p1 += (p2+1-prefix[p2]);
		}	
	}
	return position;
}



