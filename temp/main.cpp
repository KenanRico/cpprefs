#include <iostream>
#include <vector>

struct point{int x; int y;};

int main(){
	std::vector<struct point> points;
	points.push_back((point){19,7});
	std::cout<<points[0].x<<" "<<points[0].y<<"\n";
	return 0;
}



