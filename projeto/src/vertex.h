#ifndef VERTEX_H
#define VERTEX_H

#include "point.h"

struct HalfEdge;

struct Vertex
{
    Vertex();
    Vertex(int x, int y);
    Point point;
    HalfEdge* edge;
    ~Vertex();
};

#endif // VERTEX_H
