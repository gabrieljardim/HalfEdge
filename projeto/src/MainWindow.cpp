#include <MainWindow.h>
#include <QPainter>
#include <Qt>

MainWindow::MainWindow()
{
    QIcon op(":open");
    QIcon sv(":save");

    int w = 700;
    int h = 700;

    //setCentralWidget(centralpanel);


    widgetTest = new WidgetTest(this);
    tb = new QToolBar("Tool Bar", this);
    fdo = new QFileDialog(this, Qt::Window);
    fds = new QFileDialog(this, Qt::Window);


    fdo->setDirectory("..");
    fdo->setNameFilter("*.dat");

    fds->setDirectory("..");
    fds->setNameFilter("*.png");


    
    connect(tb, SIGNAL(actionTriggered( QAction * )), this, SLOT(clicou(QAction*)));
    //connect(fdo, SIGNAL(fileSelected(const QString &)), centralpanel, SLOT(recebeArquivo(const QString &)));
    //connect(fds, SIGNAL(fileSelected(const QString &)), centralpanel, SLOT(salvaArquivo(const QString &)));
    
    
    open = tb->addAction(op, "");
    save = tb->addAction(sv, "");

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

    if(a == save)
    {
        fds->setAcceptMode(QFileDialog::AcceptSave);
        fds->open();
    }
}

void MainWindow::update(void)
{
    repaint();
    qDebug() << "HelloWorld";
}

