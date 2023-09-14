#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dowork.h"
#include <QPushButton>
#include <QThread>
#include <QRunnable>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //timer

    doWorkTimer=new DoWork;
    myThreadTimer = new QThread;
    connect(myThreadTimer, SIGNAL(started()), doWorkTimer, SLOT(timer()));
    connect(doWorkTimer,&DoWork::emitTimer, this, &MainWindow::updateTime);
    doWorkTimer->moveToThread(myThreadTimer);
    myThreadTimer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::myThreads_Start(){
    doWork1 = new DoWork;
    doWork2 = new DoWork;
    doWork3 = new DoWork;
    doWork4 = new DoWork;



    myThread1 = new QThread;
    connect(myThread1, SIGNAL(started()), doWork1, SLOT(worker1()));
    connect(doWork1,&DoWork::emitRandomNumber1, this, &MainWindow::OnDoWorkUpdateProgressBar1);
    doWork1->moveToThread(myThread1);
    myThread1->start();

    myThread2 = new QThread;
    connect(myThread2, SIGNAL(started()), doWork2, SLOT(worker2()));
    connect(doWork2,&DoWork::emitRandomNumber2, this, &MainWindow::OnDoWorkUpdateProgressBar2);
    doWork2->moveToThread(myThread2);
    myThread2->start();

    myThread3 = new QThread;
    connect(myThread3, SIGNAL(started()), doWork3, SLOT(worker3()));
    connect(doWork3,&DoWork::emitRandomNumber3, this, &MainWindow::OnDoWorkUpdateProgressBar3);
    doWork3->moveToThread(myThread3);
    myThread3->start();

    myThread4 = new QThread;
    connect(myThread4, SIGNAL(started()), doWork4, SLOT(worker4()));
    connect(doWork4,&DoWork::emitRandomNumber4, this, &MainWindow::OnDoWorkUpdateProgressBar4);
    doWork4->moveToThread(myThread4);
    myThread4->start();


}

void MainWindow::OnDoWorkUpdateProgressBar1(int x){
    colorChangepb1(x);
    ui->pb1->setValue(x);
}
void MainWindow::OnDoWorkUpdateProgressBar2(int x){
    colorChangepb2(x);
    ui->pb2->setValue(x);
}
void MainWindow::OnDoWorkUpdateProgressBar3(int x){
    colorChangepb3(x);
    ui->pb3->setValue(x);
}
void MainWindow::OnDoWorkUpdateProgressBar4(int x){
    colorChangepb4(x);
    ui->pb4->setValue(x);
}

void MainWindow::updateTime(QString time)
{
    ui->label_2->setText("Time " + time);
}

void MainWindow::on_pushButton_released()
{
    myThreads_Start();
}



void MainWindow::colorChangepb1(int x){
    if(x>75){
        QPalette pal = ui->pb1->palette();
        pal.setColor(QPalette::Highlight, Qt::red);
        ui->pb1->setPalette(pal);
    }else{
        QPalette pal = ui->pb1->palette();
        pal.setColor(QPalette::Highlight, Qt::blue);
        ui->pb1->setPalette(pal);
    }

}

void MainWindow::colorChangepb2(int x){
    if(x>75){
        QPalette pal = ui->pb2->palette();
        pal.setColor(QPalette::Highlight, Qt::red);
        ui->pb2->setPalette(pal);
    }else{
        QPalette pal = ui->pb2->palette();
        pal.setColor(QPalette::Highlight, Qt::blue);
        ui->pb2->setPalette(pal);
    }

}

void MainWindow::colorChangepb3(int x){
    if(x>75){
        QPalette pal = ui->pb3->palette();
        pal.setColor(QPalette::Highlight, Qt::red);
        ui->pb3->setPalette(pal);
    }else{
        QPalette pal = ui->pb3->palette();
        pal.setColor(QPalette::Highlight, Qt::blue);
        ui->pb3->setPalette(pal);
    }

}

void MainWindow::colorChangepb4(int x){
    if(x>75){
        QPalette pal = ui->pb4->palette();
        pal.setColor(QPalette::Highlight, Qt::red);
        ui->pb4->setPalette(pal);
    }else{
        QPalette pal = ui->pb4->palette();
        pal.setColor(QPalette::Highlight, Qt::blue);
        ui->pb4->setPalette(pal);
    }

}

