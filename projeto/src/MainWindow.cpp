#include <MainWindow.h>
#include <QPainter>
#include <Qt>

MainWindow::MainWindow()
{
    QIcon op(":open");

    int w = 700;
    int h = 700;

    //setCentralWidget(centralpanel);

    widgetTest = new WidgetTest(this);
    tb = new QToolBar("Tool Bar", this);
    fdo = new QFileDialog(this, Qt::Window);


    fdo->setDirectory("..");
    fdo->setNameFilter("*.dat");
    
    connect(tb, SIGNAL(actionTriggered( QAction * )), this, SLOT(clicou(QAction*)));
    connect(fdo, SIGNAL(fileSelected(const QString &)), widgetTest, SLOT(recebeArquivo(const QString &)));
    
    open = tb->addAction(op, "");

    addToolBar(Qt::LeftToolBarArea, tb);

    //connect(centralpanel, SIGNAL(atualizaMain()), this, SLOT(update()));

    setWindowTitle("QT Raytrace 0.1");
    setFixedSize(w, h);

    widgetTest->resize(300,300);
    widgetTest->move(tb->width(), 0);
    widgetTest->show();
}

void MainWindow::clicou(QAction* a)
{
    if(a == open)
    {
        fdo->setAcceptMode(QFileDialog::AcceptOpen);
        fdo->open();
    }
}

void MainWindow::update(void)
{
    repaint();
    qDebug() << "HelloWorld";
}

