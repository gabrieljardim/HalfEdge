#ifndef EDGE_H
#define EDGE_H

#include "point.h"

class Edge
{
public:
    Edge();
    Edge(float src_x, float src_y, float dst_x, float dest_y);
    Edge(Point src, Point dst);
    inline Point src(){return m_src;}
    inline Point dst(){return m_dst;}
    ~Edge();

private:
    Point m_src;
    Point m_dst;

};

#endif // EDGE_H
