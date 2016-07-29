#include "MainWindow.h"
#include <QWidget>



int main (int argc, char** argv)
{

    QApplication myApp(argc, argv);
    MainWindow mainWindow;

    mainWindow.show();
    myApp.exec();
    return 0;
}
