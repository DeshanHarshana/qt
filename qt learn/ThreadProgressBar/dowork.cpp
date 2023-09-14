#include "dowork.h"
#include <QDateTime>
#include <QString>
DoWork::DoWork()
{

}

void DoWork::worker1(){
    while(true) {
        int randomNumber = 1 + (rand() % 100);

        emit emitRandomNumber1(randomNumber);

        QThread::msleep(500);
    }
}

void DoWork::worker2(){
    while(true) {
        int randomNumber = 1 + (rand() % 100);

        emit emitRandomNumber2(randomNumber);

        QThread::msleep(100);
    }
}

void DoWork::worker3(){
    while(true) {
        int randomNumber = 1 + (rand() % 100);

        emit emitRandomNumber3(randomNumber);

        QThread::msleep(1000);
    }
}

void DoWork::worker4(){
    while(true) {
        int randomNumber = 1 + (rand() % 100);

        emit emitRandomNumber4(randomNumber);

        QThread::msleep(1200);
    }
}

void DoWork::timer(){
    while(true){
        QDateTime currentDateTime = QDateTime::currentDateTime();


        QString currentTimeString = currentDateTime.toString("hh:mm:ss");

        emit emitTimer(currentTimeString);
        QThread::msleep(1000);
    }
}
