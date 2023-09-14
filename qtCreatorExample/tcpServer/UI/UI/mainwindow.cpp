#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TCP_Lib *tcp_lib = new TCP_Lib();
    tcp_lib->startListning();

    connect(tcp_lib, &TCP_Lib::emitClientMessage, this, &MainWindow::on_emitClientMessage);
    connect(tcp_lib, &TCP_Lib::emitSocket, this, &MainWindow::on_emitClientSocket);
    connect(this, &MainWindow::emitMessage, tcp_lib, &TCP_Lib::onSendMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_emitClientMessage(QString message)
{
    ui->textEdit->append(message);
}


void MainWindow::on_emitClientSocket(QTcpSocket *socket){
    QString client = QString::number(socket->socketDescriptor());

    if (ui->comboBox->findText(client)==-1) {
        ui->comboBox->addItem(client);
    }

}

void MainWindow::on_pushButton_clicked()
{
    QString socketId=ui->comboBox->currentText();
    QString messgae = ui->lineEdit->text();
    emit emitMessage(messgae, socketId.toInt());
}

