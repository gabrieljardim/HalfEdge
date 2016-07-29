#include "point.h"

Point::Point() : x(0), y(0) {}

Point::Point(float x, float y): x(x), y(y) {}

Point::Point(const Point &other): x(other.x), y(other.y) {}


Point::~Point()
{

}

