#include <stdio.h>
#include <string>
#include <vector>


int main(){
	union Data{
		std::string* a;
		std::vector<int>* b;
	};
	std::vector<int> vec = {1,42,1,54,19};
	const Data data = {.b=&vec};
	printf("%d\n", data.a==(std::string*)0);

	return 0;
}
