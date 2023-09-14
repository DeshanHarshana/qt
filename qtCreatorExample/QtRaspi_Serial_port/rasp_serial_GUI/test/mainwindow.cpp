#include "mainwindow.h"
#include "ui_mainwindow.h"
QSerialPort serial;
QString port="/dev/ttyAMA0";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial.setPortName(port);
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QIODevice::ReadWrite);
    serial.flush();

    connect(this,&MainWindow::emitSerial, this,&MainWindow::readPort);

    if(serial.isOpen())
    {
        ui->label->setText("Open Port = " + port );
    }else{
        ui->label->setText("Port is not opened");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::readPort(){
    QString dataAsString;
    if(serial.isOpen())
    {
        QByteArray dataRead = serial.readAll();
        dataAsString = QString::fromStdString(dataRead.toStdString());
        ui->textEdit->append(dataAsString);

    }
}

void MainWindow::on_pushButton_clicked()
{
    if(serial.isOpen()){
        emit emitSerial();
        QString message = ui->lineEdit->text();
        QByteArray ba = message.toUtf8();
        char  *write_buffer = ba.data();
        serial.write(write_buffer);

    }
}

