#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TCPSocket=new QTcpSocket();
    TCPSocket->connectToHost(QHostAddress::LocalHost,8080);

    connect(TCPSocket, SIGNAL(readyRead()),this, SLOT(Read_data_from_socket()));

    TCPSocket->open(QIODevice::ReadWrite);
    if(TCPSocket->isOpen()){
        QMessageBox::information(this, "QT", "Connected tp the server");
    }else{
         QMessageBox::information(this, "QT", "Not Connected tp the server");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_released()
{
    if(TCPSocket){
         if(TCPSocket->isOpen()){
             QString writeData=ui->lineEdit->text();
             TCPSocket->write(writeData.toStdString().c_str());

         }else{
             QMessageBox::information(this,"Wt", "Error "+ TCPSocket->errorString() );
         }
    }else{
          QMessageBox::information(this,"Wt", "Error "+ TCPSocket->errorString() );
    }
}

void MainWindow::Read_data_from_socket()
{
    if(TCPSocket){
          if(TCPSocket->isOpen()){
             QByteArray data_from_server=TCPSocket->readAll();

             QString messageString =QString::fromStdString(data_from_server.toStdString());


             ui->textEdit->append(messageString);
          }
    }
}

