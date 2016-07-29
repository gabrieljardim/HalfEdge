#ifndef HALFEDGE_H
#define HALFEDGE_H


struct Vertex;
struct Face;

struct HalfEdge
{

    HalfEdge();    
    HalfEdge(Face* argFace, Vertex* argVertex );
    HalfEdge(Face* argFace, Vertex* argVertex, HalfEdge* argNext, HalfEdge* argTwin );
    ~HalfEdge();

    Face* face;
    Vertex* vertex;
    HalfEdge* next;
    HalfEdge* twin;

};

#endif // HALFEDGE_H
