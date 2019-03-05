#pragma once
#include <iostream>
#include <cmath>
class Point
{
public:
	int x;
	int y;
	static double getDist(Point x,Point y) {
		int a = x.x - y.x;
		int b = x.y - y.y;
		return std::sqrt(a*a + b*b);
	}
	Point() {
		this->x = 0;
		this->y = 0;
	}
	Point(int x,int y) {
		this->x = x;
		this->y = y;
	}
	Point reflecty();
	Point reflectx();
	~Point();
};

