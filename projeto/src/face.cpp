#include "face.h"
#include "halfedge.h"

Face::Face() : edge(nullptr)
{

}

Face::Face(HalfEdge* edge) : edge(edge)
{

}
