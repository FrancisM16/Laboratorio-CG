#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "my_widget_opengl.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_RSlider_valueChanged(int value);

    void on_GSlider_valueChanged(int value);

    void on_BSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    MiWidgetOpenGL *wogl;
};
#endif // MAINWINDOW_H
