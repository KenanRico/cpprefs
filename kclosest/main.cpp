#include <iostream>
#include <iomanip> //std::setprecision
#include <vector>
#include <cmath>


class Point{
	private:
		float x;
		float y;
		float dist;
	public:
		Point(float _x, float _y): x(_x), y(_y), dist(sqrt(pow(x,2)+pow(y,2))){}
		~Point(){};
		Point(const Point& p): x(p.x), y(p.y), dist(p.dist){}
		Point& operator=(const Point& p){
			x = p.x;
			y = p.y;
			dist = p.dist;
		}
	private:
		Point() = delete;
	public:
		float Distance() const{
			return dist;
		}
	friend bool operator<(const Point&, const Point&);
};
bool operator<(const Point& lhs, const Point& rhs){
	return lhs.dist < rhs.dist;
}


void PopulatePoints(std::vector<Point>*);

int main(){
	//define points and N
	std::vector<Point> points;
	PopulatePoints(&points);
	int N = 5;
	int size = points.size();
	std::cout<<"All points' distance:\n";
	for(int i=0; i<size; ++i){
		std::cout<<std::setprecision(3)<<points[i].Distance()<<" ";
	}
	std::cout<<"\n";

	//sort the first N points
	for(int i=N-1; i>=0; --i){
		for(int j=size-1; j>0; --j){
			if(points[j]<points[j-1]){
				Point temp = points[j];
				points[j] = points[j-1];
				points[j-1] = temp;
			}
		}
	}

	//print result
	std::cout<<N<<" closest points:\n";
	for(int i=0; i<N; ++i){
		std::cout<<std::setprecision(3)<<points[i].Distance()<<" ";
	}
	std::cout<<"\n";

	return 0;
}

void PopulatePoints(std::vector<Point>* points){
	float vals[] = {1.4f, 0.0f, 6.7f, 1.0f, 2.8f, 0.2f, 0.4f, 1.9f, 3.7f, 2.2f, 0.5f, 8.1f, -2.4f, 2.2f, 0.6f, -9.1f, 6.0f, -1.0f};
	int size = sizeof(vals)/sizeof(float);
	for(int i=0; i+1<size; i+=2){
		points->push_back(Point(vals[i], vals[i+1]));
	}
}
