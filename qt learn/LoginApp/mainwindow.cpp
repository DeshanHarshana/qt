#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
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


void MainWindow::on_login_clicked()
{
    QString username=ui->uname->text();
    QString password=ui->pw->text();

    if(username == "test" && password == "1234"){

        QMessageBox::information(this,"Login", "Username and password are correct");
        hide();
        secDialog=new SecondDialog(this);
        secDialog -> show();
    }else{
        QMessageBox::warning(this,"Login", "Username and password are not correct");
    }
}

