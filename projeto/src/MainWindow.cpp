#include <MainWindow.h>
#include <QPainter>
#include <Qt>

MainWindow::MainWindow()
{
    int w = 700;
    int h = 700;

    widgetTest = new HalfEdgeWidget(this);

    //Comentar em caso de bug na leitura do arquivo
    recebeArquivo(":halfEdgeFile");

    setWindowTitle("HalfEdge");
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


