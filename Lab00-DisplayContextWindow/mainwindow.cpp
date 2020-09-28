#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "my_widget_opengl.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wogl = new MiWidgetOpenGL();
    ui->verticalLayout->addWidget(wogl);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_RSlider_valueChanged(int value)
{
    QString texto = QString::fromStdString(std::to_string(value/100.0));
    ui->RLabel->setText(texto);
    wogl->r = value/100.0;
    wogl->update();
}

void MainWindow::on_GSlider_valueChanged(int value)
{
    QString texto = QString::fromStdString(std::to_string(value/100.0));
    ui->GLabel->setText(texto);
    wogl->g = value/100.0;
    wogl->update();

}

void MainWindow::on_BSlider_valueChanged(int value)
{
    QString texto = QString::fromStdString(std::to_string(value/100.0));
    ui->BLabel->setText(texto);
    wogl->b = value/100.0;
    wogl->update();
}
