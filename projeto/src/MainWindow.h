#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "halfedgewidget.h"

class MainWindow : public QMainWindow
{

public:
    MainWindow();    
    void recebeArquivo(const QString &);
    
private:
   HalfEdgeWidget *widgetTest;
};


#endif
