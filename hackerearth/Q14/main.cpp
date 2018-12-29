#include <iostream>
#include <vector>
#include <string>
#include "point.h"
#include "plane.h"

void populatePlane(Plane&);
void checkCircleInclusion(const Plane&, std::vector<int>&);
int count(int, const std::vector<float>&);
void printOutput(const std::vector<int>&);


int main(){
	Plane MyPlane;
	populatePlane(MyPlane);
	std::vector<int> points_in_circle;
	checkCircleInclusion(MyPlane, points_in_circle);
	printOutput(points_in_circle);
	return 0;
}

void populatePlane(Plane& p){
	std::cout<<"Number of points on the plane: "<<std::endl;
	int numPts = 0;
	std::cin>>numPts;
	std::string garbage = "";
	getline(std::cin, garbage);
	std::cout<<"coordinates of points: "<<std::endl;
	for(int i=0; i<numPts; ++i){
		int x = 0;
		int y = 0;
		std::cin>>x>>y;
		getline(std::cin, garbage);
		p.addPoint(Point(x,y));
	}
}

void checkCircleInclusion(const Plane& p, std::vector<int>& points_in_circle){
	std::cout<<"Number of circles: "<<std::endl;
	int numCircs = 0;
	std::cin>>numCircs;
	std::string garbage = "";
	getline(std::cin, garbage);
	const std::vector<float> distances = p.distancesFromOrigin();
	std::cout<<"radius's of circles: "<<std::endl;
	for(int i=0; i<numCircs; ++i){
		float radius = 0;
		std::cin>>radius;
		getline(std::cin, garbage);
		points_in_circle.push_back(count(radius, distances));
	}

}
int count(int radius, const std::vector<float>& distances){
	int inclusions = 0;
	for(std::vector<float>::const_iterator iter=distances.begin(); iter<distances.end(); ++iter){
		inclusions+=(*iter<radius);
	}
	return inclusions;
}

void printOutput(const std::vector<int>& points_in_circle){
	std::cout<<"Output: "<<std::endl;
	for(unsigned int i=0; i<points_in_circle.size(); ++i){
		std::cout<<points_in_circle[i]<<std::endl;
	}
}
