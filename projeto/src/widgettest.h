#ifndef WIDGETTEST_H
#define WIDGETTEST_H

#include <QWidget>
#include <QSet>

struct HalfEdge;
struct Face;

class WidgetTest : public QWidget
{
public:
    WidgetTest(QWidget* parent);
    void paintEvent(QPaintEvent *event);
    void drawMesh(QSet<Face*>*set, HalfEdge* edge, QPainter& painter);
private:
    HalfEdge* m_edge;
    QPainter* m_painter;
};

#endif // WIDGETTEST_H
