#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dowork.h"
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::QSWRampStart()
{
    doWork = new DoWork;

    qRampingThread = new QThread;
    connect(qRampingThread, SIGNAL(started()), doWork, SLOT(qRampProcess()));

    connect(doWork,&DoWork::UpdateGUI, this, &MainWindow::OnDoWorkUpdateEvents);

    doWork->moveToThread(qRampingThread);
    qRampingThread->start();

}

void MainWindow::OnDoWorkUpdateEvents(int x){
    ui->label->setText(QString::number(x));
}


void MainWindow::on_pushButton_clicked()
{
    QSWRampStart();
}


