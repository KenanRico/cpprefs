#include <iostream>
#include <vector>
#include <tuple>

std::vector<std::tuple<int> > points;
void DrawLine(int,int,int,int,int);
int Round(float);
int main(){
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;
	int eu = 0;
	std::cout<<"Please enter two points: "<<std::endl;
	std::cout<<"Point 1: "; std::cin>>x1>>y1;
	std::cout<<"Point 2: "; std::cin>>x2>>y2;
	std::cout<<"Just exactly a number of two to the how many times of points do you want:"<<std::endl;
	std::cin>>eu;
	DrawLine(x,y,eu)
	return 0;
}
void DrawLine(int x1, int x2, int y1, int y2, int eu){
	if(eu>0){
		int mid_x = Round((x1+x2)/2);
		int mid_y = Round((y1+y2)/2);
		DrawLine(x1,y1,mid_x,mid_y,eu-1);
		points.push_back(std::make_tuple(mid_x,mid_y));
		DrawLine(mid_x+1,mid_y+1,x2,y2,eu-1);
	}else;
}
int Round(float unrounded){


	return rounded;
}
