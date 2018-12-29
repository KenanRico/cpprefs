#include "point.h"
#include <vector>

#ifndef PLANE_H
#define PLANE_H
class Plane{
	private:
		std::vector<Point> points;
	public:
		Plane();
		~Plane();
		Plane(const Plane&);
		Plane& operator=(const Plane&);
	public:
		void addPoint(const Point&);
		std::vector<float> distancesFromOrigin() const;
};
#endif
