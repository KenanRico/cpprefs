#include "point.h"
#include <math.h>

Point::Point() : x(0),y(0)
{;}

Point::~Point(){;}

Point::Point(const Point& rhs) : x(rhs.x),y(rhs.y)
{;}

Point& Point::operator=(const Point& rhs){
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

Point::Point(int _x, int _y) : x(_x),y(_y)
{;}

int Point::getX() const{
	return this->x;
}

int Point::getY() const{
	return this->y;
}
float Point::getDistanceFromOrigin(){
	return (float)sqrt(powf(this->x,2)+powf(this->y,2));
}
