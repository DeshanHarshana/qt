#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myLib = new Libraray();
    connect(myLib, &Libraray::emitLevel, this, &MainWindow::catchLevel);
    connect(this, &MainWindow::emitRandomValue, myLib, &Libraray::catchRandom);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::catchLevel(QString level) {
    ui->label_2->setText(level);
}

void MainWindow::on_pushButton_released()
{



    int rand= myLib->getData();
    ui->label->setText(QString::number(rand));
    emit emitRandomValue(rand);

}

