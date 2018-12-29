#include <stdio.h>
#include <stdlib.h>

int main(){
	int* num = (int*) malloc(sizeof(int));
	*num = fork();
	if(*num==0){
		printf("In child process, pID is %d \n", *num);
	}else{
		printf("In parent process, child's pID is %d \n", *num);
	}
	free(num);
}
