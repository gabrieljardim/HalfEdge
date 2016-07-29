#include "widgettest.h"
#include "halfedge.h"
#include "face.h"
#include "vertex.h"
#include <qpainter.h>
#include <QDebug>
#include <QSet>

WidgetTest::WidgetTest(QWidget* parent) : QWidget(parent)
{
   //teste para desenhar malha


   Face* face1 = new Face();
   Face* face2 = new Face();

   Vertex* vertex1 = new Vertex(30,50);
   Vertex* vertex2 = new Vertex(150, 50);
   Vertex* vertex3 = new Vertex(90, 100);

   Vertex* vertex4 = new Vertex(180, 150);
   Vertex* vertex5 = new Vertex(250, 120);

   HalfEdge* edge1 = new HalfEdge(face1, vertex1, nullptr, nullptr);
   HalfEdge* edge2 = new HalfEdge(face1, vertex2, nullptr, nullptr);
   HalfEdge* edge3 = new HalfEdge(face1, vertex3, nullptr, nullptr);

   HalfEdge* edge4 = new HalfEdge(face2, vertex2, nullptr, nullptr);
   HalfEdge* edge5 = new HalfEdge(face2, vertex3, edge2, nullptr);
   HalfEdge* edge6 = new HalfEdge(face2, vertex4, nullptr, nullptr);
   HalfEdge* edge7 = new HalfEdge(face2, vertex5, nullptr, nullptr);



   face1->edge = edge1;
   face2->edge = edge5;

   edge1->vertex->edge = edge1;
   edge2->vertex->edge = edge2;
   edge3->vertex->edge = edge3;
   edge5->vertex->edge = edge5;
   edge6->vertex->edge = edge6;
   edge7->vertex->edge = edge7;

   edge2->twin = edge5;

   edge1->next = edge2;
   edge2->next = edge3;
   edge3->next = edge1;
   edge4->next = edge7;
   edge5->next = edge4;
   edge6->next = edge5;
   edge7->next = edge6;


   this->m_edge = edge1;
}

void WidgetTest::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QSet<Face*>* mySet = new QSet<Face*>;
    drawMesh(mySet, m_edge, painter);
    mySet->clear();
    delete mySet;

}

void WidgetTest::drawMesh(QSet<Face*>* set, HalfEdge* edge, QPainter& painter)
{
    HalfEdge* auxEdge = edge;
    int i = 0;

    if(auxEdge == nullptr)
        return;

    qDebug() << "Minha face: " << auxEdge->face;

    //insere no conjunto a face caso já não exista
    set->insert(auxEdge->face);

    do
    {
        qDebug() << "Iterations: " << i++;

        if(auxEdge->vertex != nullptr)
        {
            painter.setPen(QPen(Qt::red, 8, Qt::SolidLine, Qt::RoundCap));
            painter.drawPoint(auxEdge->vertex->point.x, auxEdge->vertex->point.y);

            if((auxEdge->next != nullptr)&& (auxEdge->next->vertex != nullptr))
            {
                Point point1 = auxEdge->vertex->point;
                Point point2 = auxEdge->next->vertex->point;
                painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
                painter.drawLine(point1.x, point1.y, point2.x, point2.y);
            }
        }
        if(auxEdge->twin != nullptr)
        {
            qDebug() << "Achei meu twin";
            if(!set->contains(auxEdge->twin->face))
            {
                qDebug() << "Nunca vi essa face";
                 drawMesh(set, auxEdge->twin, painter);
            }
            else
                qDebug() << "Ja visitei esse jovem";
        }

        auxEdge = auxEdge->next;

    } while((auxEdge != nullptr) && (auxEdge != edge));

    qDebug() << *set;
}


/*ideia do algoritmo para senhar
 *
 * algoritmo recursivo
 *
 * coloca face atual na lista de visitados
 * ve se existe twin da aresta atual
 * se existir chama função recursiva com esse twin, set de faces visitadas
 * senão desenha e vai pra next
 * retorna quando aux = half edge inicial
 *
 *
 *
 *
 *
 * */
