#include <iostream>
#include <string>
#include <math.h>

int numPoints = 0;
int numCircles = 0;
int** points = (int**)0;
int* radius = (int*)0;

void parseData();
void printResult();
float distanceFromOrigin(int,int);

int main(){
	parseData();
	printResult();
	return 0;
}

void parseData(){
	std::cout<<"how many points? \n";
	std::cin>>numPoints;
	std::string garbage("");
	getline(std::cin, garbage);
	points = new int*[numPoints]();
	for(int i=0; i<numPoints; ++i){
		*(points+i) = new int[2]();
		std::cin>>**(points+i)>>*(*(points+i)+1);
		getline(std::cin, garbage);
	}
	std::cout<<"how many circles at origin? \n";
	std::cin>>numCircles;
	getline(std::cin, garbage);
	radius = new int[numCircles]();
	for(int i=0; i<numCircles; ++i){
		std::cin>>radius[i];
		getline(std::cin, garbage);
	}
}

void printResult(){
	for(int i=0; i<numCircles; ++i){
		int sum = 0;
		for(int j=0; j<numPoints; ++j){
			if(radius[i]>=distanceFromOrigin(points[j][0], points[j][1])){
				++sum;
			}else;
		}
		std::cout<<sum<<"\n";
	}
}

float distanceFromOrigin(int x, int y){
	return sqrt(powf(x,2)+powf(y,2));
}
