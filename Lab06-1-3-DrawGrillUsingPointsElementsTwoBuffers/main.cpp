#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    w.setWindowTitle("Draw Grill Using Points Elements Two Buffers");
    w.show();
    return a.exec();
}
