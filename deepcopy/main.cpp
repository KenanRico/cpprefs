#include "point.h"
#include <iostream>
#include <string>
int main(){
	//initialize 4 point objects
	Point obj1("This is obj1 or obj2");
	Point obj2(obj1);
	Point obj3;
	Point obj4;
	obj4 = obj2;
	//print all objects
	obj1.print();
	obj2.print();
	obj3.print();
	obj4.print();	
	return 0;
}
