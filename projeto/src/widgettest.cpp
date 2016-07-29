#include "widgettest.h"
#include "halfedge.h"
#include "face.h"
#include "vertex.h"
#include <qpainter.h>
#include <QDebug>
#include <QSet>

WidgetTest::WidgetTest(QWidget* parent) : QWidget(parent)
{
    this->m_edge = nullptr;
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

void WidgetTest::leArquivo(const QString &filename)
{
    LeArquivo(filename, &m_edge);
    repaint();
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
