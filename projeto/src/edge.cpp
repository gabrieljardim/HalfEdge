#include "edge.h"

Edge::Edge()
{
    m_src.x = 0;
    m_src.y = 0;
    m_dst.x = 0;
    m_dst.y = 0;
}

Edge::Edge(float src_x, float src_y, float dst_x, float dst_y)
{
    m_src.x = src_x;
    m_src.y = src_y;
    m_dst.x = dst_x;
    m_dst.y = dst_y;
}

Edge::Edge(Point src, Point dst) : m_src(src), m_dst(dst)
{

}

Edge::~Edge()
{

}

