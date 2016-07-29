#ifndef WIDGETTEST_H
#define WIDGETTEST_H

#include <QWidget>
#include "io.h"

struct HalfEdge;
class QPainter;

class WidgetTest : public QWidget
{
public:
    WidgetTest(QWidget* parent);
    void paintEvent(QPaintEvent *event);
    void drawMesh(QPainter& painter);

signals:
    void recebeArquivo(const QString &);

private:
    HalfEdge* m_edge;
    QPainter* m_painter;
};

#endif // WIDGETTEST_H
