#include <MainWindow.h>
#include <QPainter>
#include <Qt>

MainWindow::MainWindow()
{
    QIcon op(":open");

    int w = 700;
    int h = 700;


    widgetTest = new HalfEdgeWidget(this);

    recebeArquivo(":halfEdgeFile");

    setWindowTitle("QT Raytrace 0.1");
    setFixedSize(w, h);

    widgetTest->resize(300,300);
    widgetTest->move(0, 0);
    widgetTest->show();
}


void MainWindow::recebeArquivo(const QString &filename)
{
    widgetTest->leArquivo(filename);
    repaint();
    widgetTest->show();
}


