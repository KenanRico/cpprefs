#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <dirent.h>
#include <algorithm>

#define OLD_PATH "./WindowsTxts/"
#define NEW_PATH "./UnixTxts/"


void GetWindowsTxts(std::vector<std::string>*);
std::string GetWindowsTxtContent(const std::string&);
void WriteContentAsUnixTxt(const std::string&, const std::string&);

int main(){
	//fetch all Windows txts to be converted
	std::vector<std::string> files;
	GetWindowsTxts(&files);
	//for each Windows txt
	for(std::vector<std::string>::const_iterator file=files.begin(); file!=files.end(); ++file){
		//read file into buffer
		std::string file_content = GetWindowsTxtContent(*file);
		//generate new content (carriage return removed) and write to new file
		WriteContentAsUnixTxt(*file, file_content);
	}

	return 0;
}

void GetWindowsTxts(std::vector<std::string>* files){
	DIR* dir = nullptr;
	if((dir=opendir(OLD_PATH)) != nullptr){
		struct dirent* ent = nullptr;
		while((ent=readdir(dir)) != nullptr){
			files->push_back(std::string(ent->d_name));
		}
		closedir(dir);
	}else{
		std::cout<<"Could not locate"<<OLD_PATH<<"!\n";
	}
}

std::string GetWindowsTxtContent(const std::string& fn){
	std::fstream fs(std::string(OLD_PATH+fn).c_str(), std::fstream::in);
	std::stringstream ss;
	ss<<fs.rdbuf();
	fs.close();
	return ss.str();
}

void WriteContentAsUnixTxt(const std::string& fn, const std::string& content){
	//generate UNIX text string from Windows content
	std::string new_content = content;
	new_content.erase(std::remove(new_content.begin(), new_content.end(), (char)13), new_content.end());
	//write new content to UNIX text files
	DIR* dir = nullptr;
	if((dir=opendir(NEW_PATH)) != nullptr){
		std::fstream fs(std::string(NEW_PATH+fn).c_str(), std::fstream::out);
		fs<<new_content;
		fs.close();
	}else{
		std::cout<<"Could not locate"<<NEW_PATH<<"!\n";
	}
}
