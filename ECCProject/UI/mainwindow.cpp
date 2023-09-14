#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Create a new thread and move the ecclib object to the new thread
    QThread* thread = new QThread();
    ecclib = new Ecclib();
    ecclib->moveToThread(thread);
    thread->start();

    // Connect the started signal of the thread to the startListning() method of the ecclib object
    connect(thread, &QThread::started, ecclib, &Ecclib::startListning);

    // Connect the emitClientMessage() signal of the ecclib object to the on_emitClientMessage() slot of this class
    connect(ecclib, &Ecclib::emitClientMessage, this, &MainWindow::on_emitClientMessage);

    connect(this, &MainWindow::sendMessage, ecclib, &Ecclib::onSendMessage);

    connect(ecclib, &Ecclib::emitSocket, this, &MainWindow::updateClientList);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_emitClientMessage(QString message)
{

    // qDebug() the message
    qDebug() << message;

    ui->textEdit->append(message);
}





void MainWindow::on_pushButton_released()
{
    QString message = ui->lineEdit->text();
    emit sendMessage(message);
}


void MainWindow::updateClientList(QTcpSocket *socket){
    QString socketDiscriptor = QString::number(socket->socketDescriptor());
    ui->textEdit_2->append(socketDiscriptor);
}
