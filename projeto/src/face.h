#ifndef FACE_H
#define FACE_H

struct HalfEdge;

struct Face
{
    Face();
    Face(HalfEdge* edge);
    HalfEdge* edge;
    ~Face(){}
};

#endif // FACE_H
