#ifndef POINT_H
#define POINT_H


struct Point
{
    Point();
    Point(float x, float y);
    Point(const Point& other);
    ~Point();

    float x;
    float y;

};

#endif // POINT_H
