#include "mainwindow.h"
#include "ui_mainwindow.h"

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



void MainWindow::on_connect_clicked()
{
    TCPSocket=new QTcpSocket();
    QString host=ui->ipaddress->text();
    QString port = ui->port->text();
    TCPSocket->connectToHost(host,port.toInt());


    TCPSocket->open(QIODevice::ReadWrite);
    if(TCPSocket->isOpen()){
        QMessageBox::information(this, "QT", "Connected tp the server");
        connect(TCPSocket, SIGNAL(readyRead()),this, SLOT(Read_data_from_socket()));
    }else{
        QMessageBox::information(this, "QT", "Not Connected tp the server");
    }
}

void MainWindow::Read_data_from_socket()
{
    if(TCPSocket){
        if(TCPSocket->isOpen()){
            QByteArray data_from_server=TCPSocket->readAll();

            QString messageString =QString::fromStdString(data_from_server.toStdString());


            ui->server_response->append(messageString);
        }
    }
}


void MainWindow::on_send_clicked()
{
    if(TCPSocket){
        if(TCPSocket->isOpen()){
            QString writeData=ui->message->text();
            TCPSocket->write(writeData.toStdString().c_str());

        }else{
            QMessageBox::information(this,"Wt", "Error "+ TCPSocket->errorString() );
        }
    }else{
        QMessageBox::information(this,"Wt", "Error "+ TCPSocket->errorString() );
    }
}

