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

