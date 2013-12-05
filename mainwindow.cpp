#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glviewport.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timer(this),
    widget(new GLViewport())
{
    ui->setupUi(this);
    setCentralWidget(widget);
//    timer.setInterval(1);
//    connect(&timer, SIGNAL(timeout()), this, SLOT(timeout()));
//    timer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    widget->bust();
}
