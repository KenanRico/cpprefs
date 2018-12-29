#ifndef POINT_H
#define POINT_H
#include <string>
class Point{
	private:
		std::string* s;
		bool assigned;
	public:
		Point();
		Point(const Point&);
		Point& operator=(const Point&);
		Point(std::string);
		void print();
		~Point();
};
#endif

