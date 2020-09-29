#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QSurfaceFormat fmt;
    fmt.setVersion( 3, 3 );
    fmt.setProfile( QSurfaceFormat::CompatibilityProfile);
    QSurfaceFormat::setDefaultFormat( fmt );

    ui->setupUi(this);
    wogl = new MiWidgetOpenGL();
    wogl->setFormat(fmt);
    ui->verticalLayout->addWidget(wogl);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButton_clicked()
{
     wogl->primitiva=0;
     wogl->update();

}

void MainWindow::on_radioButton_2_clicked()
{
    wogl->primitiva=1;
    wogl->update();
}

void MainWindow::on_radioButton_3_clicked()
{
    wogl->primitiva=2;
    wogl->update();
}

void MainWindow::on_radioButton_4_clicked()
{
    wogl->primitiva=3;
    wogl->update();
}

void MainWindow::on_radioButton_5_clicked()
{
    wogl->primitiva=4;
    wogl->update();
}

void MainWindow::on_radioButton_6_clicked()
{
    wogl->primitiva=5;
    wogl->update();
}

void MainWindow::on_radioButton_7_clicked()
{
    wogl->primitiva=6;
    wogl->update();
}
