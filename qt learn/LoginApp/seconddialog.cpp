#include "seconddialog.h"
#include "ui_seconddialog.h"
#include <QPixmap>

SecondDialog::SecondDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondDialog)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/Computer-PNG-Photos.png");
    int x=ui->graphicView->width();
    int y=ui->graphicView->height();
    ui->graphicView->setPixmap(pix.scaled(x,y,Qt::KeepAspectRatio));


    ui->mylist->addItem("Marks");

    for(int x=0; x<10; x++){
        ui->mylist->addItem(QString::number(x));
    }
}

SecondDialog::~SecondDialog()
{
    delete ui;
}
