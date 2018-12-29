#include <map>
#include <string>
#include <iostream>


int main(){
	std::map<int, int*> m;
	m.insert(std::make_pair(10, new int(10)));
	m.insert(std::make_pair(7, new int(7)));
	m.insert(std::make_pair(5, new int(5)));

	int i=8;
	std::cout<<"address:"<<m[i]<<"\n";

	for(std::map<int, int*>::iterator i=m.begin(); i!=m.end(); ++i){
		delete i->second;
	}

	return 0;

}
