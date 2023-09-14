#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   myLib = new MyLib();
    // Connect the signal from MyLib to the slot in MainWindow
    connect(myLib, &MyLib::emitLevel, this, &MainWindow::catchLevel);
   connect(this, &MainWindow::emitRandomValue, myLib, &MyLib::catchRandom);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{



    int rand= myLib->getData();
    ui->label->setText(QString::number(rand));
    emit emitRandomValue(rand);

}

void MainWindow::catchLevel(QString level) {
    ui->label2->setText(level);
}
