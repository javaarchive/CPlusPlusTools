#pragma once
#include <iostream>
class Point
{
public:
	int x;
	int y;
	Point() {
		std::cout << "Extra";
		this->x = 0;
		this->y = 0;
	}
	~Point();
};

