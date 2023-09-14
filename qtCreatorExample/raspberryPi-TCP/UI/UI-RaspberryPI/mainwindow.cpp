#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TCPRaspi *tcp_lib = new TCPRaspi();
    tcp_lib->startListning();

    connect(tcp_lib, &TCPRaspi::emitClientMessage, this, &MainWindow::on_emitClientMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_emitClientMessage(QString message)
{
    ui->textEdit->append(message);
}
