#include "widgettest.h"
#include "halfedge.h"
#include "face.h"
#include "vertex.h"
#include <qpainter.h>
#include <QDebug>

WidgetTest::WidgetTest(QWidget* parent) : QWidget(parent)
{
   //teste para desenhar malha
   Face* face1 = new Face();

   HalfEdge* edge1 = new HalfEdge(face1, new Vertex(30,50), nullptr, nullptr);
   HalfEdge* edge2 = new HalfEdge(face1, new Vertex(150, 50), nullptr, nullptr);
   HalfEdge* edge3 = new HalfEdge(face1, new Vertex(90, 100), nullptr, nullptr);

   edge1->vertex->edge = edge1;
   edge2->vertex->edge = edge2;
   edge3->vertex->edge = edge3;

   face1->edge = edge1;
   edge1->next = edge2;
   edge2->next = edge3;
   edge3->next = edge1;

   this->m_edge = edge1;
}

void WidgetTest::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    drawMesh(painter);
}

void WidgetTest::drawMesh(QPainter& painter)
{
    HalfEdge* auxEdge = m_edge;

    if(auxEdge == nullptr)
        return;

    do
    {
        if(auxEdge->vertex != nullptr)
        {
            painter.setPen(QPen(Qt::red, 15, Qt::SolidLine, Qt::RoundCap));
            painter.drawPoint(auxEdge->vertex->point.x, auxEdge->vertex->point.y);

            if((auxEdge->next != nullptr)&& (auxEdge->next->vertex != nullptr))
            {
                Point point1 = auxEdge->vertex->point;
                Point point2 = auxEdge->next->vertex->point;
                painter.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap));
                painter.drawLine(point1.x, point1.y, point2.x, point2.y);
            }
        }

        auxEdge = auxEdge->next;

    } while((auxEdge != nullptr) && (auxEdge != m_edge));
    qDebug() << "DrawMesh";
}


/*
 * if()
 *
 *
 *
 *
 * */
