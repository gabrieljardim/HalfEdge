#ifndef HALFEDGE_H
#define HALFEDGE_H

class Edge;

class HalfEdge
{

public:
    HalfEdge();
    ~HalfEdge();

private:
    Edge* m_prev;
    Edge* m_next;
    Edge* m_twin;

};

#endif // HALFEDGE_H
