
#ifndef POINT_H
#define POINT_H
class Point{
	private:
		int x;
		int y;
	public: 
		Point();
		~Point();
		Point(const Point&);
		Point& operator=(const Point&);
		Point(int,int);
	public:
		int getX() const;
		int getY() const;
		float getDistanceFromOrigin();
};
#endif
