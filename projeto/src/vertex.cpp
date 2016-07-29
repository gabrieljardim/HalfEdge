#include "vertex.h"

Vertex::Vertex()
{

}
Vertex::Vertex(int x, int y) : point(Point(x,y))
{

}
Vertex::Vertex(const Vertex &other) : point(Point(other.point))
{

}
