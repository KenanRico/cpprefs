#include <iostream>

void texttonumstring(const char*, const char*, const char*);
void print_8b_binary(int);

int main(){
	texttonumstring("complex", "fdzgxjv", "parttwo");
	texttonumstring("fdzgxjv", "fdzgxjv", "parttwo");
	texttonumstring("parttwo", "fdzgxjv", "parttwo");
	return 0;
}

void texttonumstring(const char* plain1, const char* cypher1, const char* plain2){
	const char* c1 = plain1;
	const char* c2 = cypher1;
	const char* c3 = plain2;
	int offset = 0;
	while(*(c1+offset)!='\0'){
		int distance = (int)*(c2+offset)-(int)*(c1+offset);
		//std::cout<<((int)*(c3+offset)+distance)<<" ";
		//std::cout<<(int)*(c3+offset)<<" ";
		print_8b_binary((int)*(c1+offset));
		++offset;
	}
	std::cout<<"\n";
}

void print_8b_binary(int dec){
	int bin[8] = {0};
	for(int i=7; i>=0; --i){
		bin[i] = dec%2;
		dec /= 2;
	}
	for(int i=0; i<8; ++i){
		std::cout<<bin[i];
	}
	std::cout<<" ";
}	

