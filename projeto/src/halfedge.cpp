#include "halfedge.h"
#include "vertex.h"
#include "face.h"

HalfEdge::HalfEdge() : face(nullptr), vertex(nullptr), next(nullptr), twin(nullptr)
{

}
HalfEdge::HalfEdge(Face* argFace, Vertex* argVertex, HalfEdge* argNext, HalfEdge* argTwin )
    : face(argFace), vertex(argVertex), next(argNext), twin(argTwin)
{

}

HalfEdge::~HalfEdge()
{

}

