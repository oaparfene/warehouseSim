#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , floor(new WarehouseFloor(this))
{
    ui->setupUi(this);
    ui->editLayout->addWidget(floor);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_newOrder_clicked()
{
    floor->newOrder();
}

void MainWindow::on_startButton_clicked()
{
    floor->startSim();
}
