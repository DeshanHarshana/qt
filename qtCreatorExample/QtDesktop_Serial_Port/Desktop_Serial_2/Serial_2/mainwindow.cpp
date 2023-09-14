#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    COMPORT->setPortName("/dev/tty54");
    COMPORT->setBaudRate(QSerialPort::BaudRate::Baud19200);
    COMPORT->setParity(QSerialPort::Parity::NoParity);
    COMPORT->setDataBits(QSerialPort::DataBits::Data8);
    COMPORT->setStopBits(QSerialPort::StopBits::OneStop);
    COMPORT->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
    COMPORT->open(QIODevice::ReadWrite);

    if(COMPORT->isOpen()){
        qDebug()<<"Serial Port is connected";
    }else{
        qDebug()<<"Serial Port is not connected";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

