#include <string>
#include <iostream>
#include <vector>

void addTokens(const std::string, const std::vector<std::string>&, const std::vector<char>&, std::vector<std::string>&);

int main(){
	std::string URL = "www.youtube.com?additionalDATAxxx&launch=remote";
	std::vector<std::string> tokens {"Launch=preLoad&", "#start?"};
	std::vector<char> delimiters {'?', '&'};
	std::vector<std::string> segments;
	addTokens(URL, tokens, delimiters, segments);
	URL = "";
	for(std::vector<std::string>::const_iterator seg=segments.begin(); seg!=segments.end(); ++seg){
		URL += *seg;
	}
	std::cout<<URL<<"\n";
	return 0;
}

void addTokens(const std::string URL, const std::vector<std::string>& tokens, const std::vector<char>& delimiters, std::vector<std::string>& segments){
	if(tokens.size()==delimiters.size()){
		std::string::size_type pos0 = 0;
		std::string::size_type pos1 = 0;
		for(std::vector<char>::const_iterator iter=delimiters.begin(); iter!=delimiters.end(); ++iter){
			pos0 = pos1;
			pos1 = URL.find(*iter);
			segments.push_back(URL.substr(pos0, ++pos1));
			segments.push_back(tokens[iter-delimiters.begin()]);
		}
		segments.push_back(URL.substr(pos1, URL.size()+1));
	}else{
		std::cerr<<"Number of tokens and delimiters mismatched \n";
	}		
}
