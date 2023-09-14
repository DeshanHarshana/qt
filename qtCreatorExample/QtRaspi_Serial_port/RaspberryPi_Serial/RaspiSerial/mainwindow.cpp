#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    if (serialPortInfos.isEmpty()) {
        ui->textEdit_2->append("No available serial ports found.");
    } else {
        for (const QSerialPortInfo &portInfo : serialPortInfos) {
            ui->textEdit_2->append(portInfo.portName());
        }
    }

    QSerialPort COMPORT;
    COMPORT.setPortName("ttyAMA0");
    COMPORT.setBaudRate(QSerialPort::BaudRate::Baud115200);
    COMPORT.setParity(QSerialPort::Parity::NoParity);
    COMPORT.setDataBits(QSerialPort::DataBits::Data8);
    COMPORT.setStopBits(QSerialPort::StopBits::OneStop);
    COMPORT.setFlowControl(QSerialPort::FlowControl::NoFlowControl);
    COMPORT.open(QIODevice::ReadWrite);

    if(COMPORT.isOpen()){
        ui->textEdit->append("Serial Port is connected");
    }else{
        ui->textEdit->append("Serial Port is not connected");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

