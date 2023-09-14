#include "calc.h"
#include "ui_calc.h"
#include<QRegularExpression>
#include<QRegularExpressionMatch>

double calcVal=0.0;
bool divTrigger=false;
bool multiTrigger=false;
bool addTrigger=false;
bool subTrigger=false;

Calc::Calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calc)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcVal));

    QPushButton *numButtons[10];
    for(int i=0; i<10;i++){
        QString butName="Button"+QString::number(i);
        numButtons[i]=Calc::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));

    }

    connect(ui->Add, SIGNAL(released()), this, SLOT(MathButtonPress()));
    connect(ui->Substrct, SIGNAL(released()), this, SLOT(MathButtonPress()));
    connect(ui->Multiply, SIGNAL(released()), this, SLOT(MathButtonPress()));
    connect(ui->Divide, SIGNAL(released()), this, SLOT(MathButtonPress()));

    connect(ui->Equal, SIGNAL(released()), this, SLOT(EqualButton()));

    connect(ui->Clear, SIGNAL(released()), this, SLOT(clearButtonPressed()));

    connect(ui->ChangeSign, SIGNAL(released()), this, SLOT(ChangeNumberSign()));
}

Calc::~Calc()
{
    delete ui;
}

void Calc::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal=button->text();
    QString displayVal=ui->Display->text();
    if((displayVal.toDouble()==0) || (displayVal.toDouble()==0.0)){
        ui->Display->setText(butVal);
    } else{
        QString newVal = displayVal+butVal;
        double dblNewVal=newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal,'g', 16));
    }
}

void Calc::MathButtonPress(){
    divTrigger=false;
    multiTrigger=false;
    addTrigger=false;
    subTrigger=false;

    QString displayVal = ui->Display->text();
    calcVal= displayVal.toDouble();
    QPushButton *button =(QPushButton *)sender();
    QString butVal = button->text();
    if(QString::compare(butVal, "/", Qt::CaseInsensitive)==0){
        divTrigger=true;
    }else if(QString::compare(butVal, "*", Qt::CaseInsensitive)==0){
        multiTrigger=true;
    }else if(QString::compare(butVal, "+", Qt::CaseInsensitive)==0){
        addTrigger=true;
    }else {
        subTrigger=true;
    }

    ui->Display->setText("");
}

void Calc::EqualButton(){
    double solution =0.0;
    QString displayVal=ui->Display->text();
    double dbDisplayVal = displayVal.toDouble();
    if(addTrigger || subTrigger || multiTrigger || divTrigger){
        if(addTrigger){
            solution=calcVal+dbDisplayVal;
        }
        else if(subTrigger){
            solution = calcVal-dbDisplayVal;
        }else if(multiTrigger){
            solution = calcVal*dbDisplayVal;
        }else{
            solution = calcVal/dbDisplayVal;
        }
    }
    ui->Display->setText(QString::number(solution));
}

void Calc::ChangeNumberSign(){
    QString displayVal = ui->Display->text();
    QRegularExpression re;
    re.setPattern("[-]?[0-9.]*");
    QRegularExpressionMatch match = re.match(displayVal);

    if(match.hasMatch()){
            double dblDisplayVal=displayVal.toDouble();
            double dblDisplayValSign = -1*dblDisplayVal;
            ui->Display->setText((QString::number(dblDisplayValSign)));
    }
}

void Calc::clearButtonPressed(){
    ui->Display->setText("");
}


