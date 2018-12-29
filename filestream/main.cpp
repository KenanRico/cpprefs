#include <fstream>
#include <iostream>
#include <string>


int main(){
	std::fstream fout("file.txt", std::ios::out|std::ios::app);
	fout<<"\nsome string";
	fout.close();

	std::fstream fin("file.txt", std::ios::in);
	std::string s("");
	fin>>s;
	std::cout<<s<<"\n";
	fin.close();




	return 0;
}
