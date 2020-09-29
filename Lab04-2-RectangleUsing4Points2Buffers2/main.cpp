#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    w.setWindowTitle("Rectangle Using 4 Points 2 Buffer 2");
    w.show();
    return a.exec();
}
