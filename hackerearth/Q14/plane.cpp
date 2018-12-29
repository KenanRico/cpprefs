#include "plane.h"
#include "point.h"
#include <vector>
#include <math.h>

Plane::Plane(){;}

Plane::~Plane(){;}

Plane::Plane(const Plane& rhs) : points(rhs.points)
{;}

Plane& Plane::operator=(const Plane& rhs){
	this->points = rhs.points;
	return *this;
}

void Plane::addPoint(const Point& p){
	points.push_back(p);
}

std::vector<float> Plane::distancesFromOrigin() const{
	std::vector<float> dis;
	for(std::vector<Point>::const_iterator p=points.begin(); p<points.end(); ++p){
		dis.push_back((float)sqrt(powf(p->getX(),2)+powf(p->getY(),2)));
	}
	return dis;
}
