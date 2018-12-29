#include <iostream>
#include <cstring>

void insert(char*, int, char);
int hash(char, int);
void checkPresence(char*, int);


int main(int argc, char** argv){
	int size = strlen(*(argv+1));
	char* hTable = new char[size]();
	for(int i=0; i<size; ++i){
		insert(hTable, size, (*(argv+1))[i]);
	}
	checkPresence(hTable,size);
	return 0;
}


void insert(char* table, int size, char c){
	std::cout<<table[1]<<" "<<size<<" "<<c<<"\n";
	int pos = hash(c, size);
	if(pos<size){
		table[pos] = c;
	}else{
		std::cout<<"Hashed pos too large: "<<pos<<"\n";
	}
}

int hash(char c, int size){
	return (int)c % size;
}

void checkPresence(char* table, int size){
	char c = ' ';
	while(c!='.'){
		std::cin>>c;
		if(table[hash(c,size)]==c){
			std::cout<<"character found \n";
		}else{
			std::cout<<"character not found \n";
		}
	}
}
