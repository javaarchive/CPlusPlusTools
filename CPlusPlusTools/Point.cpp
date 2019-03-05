#include "pch.h"
#include "Point.h"



Point Point::reflecty()
{
	return Point(-this->x,this->y);
}

Point Point::reflectx()
{
	return Point(this->x, -this->y);
}

Point::~Point()
{
	
}
