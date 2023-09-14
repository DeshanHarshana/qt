#include "mythread.h"
#include <QtCore>
#include <QtDebug>

MyThread::MyThread(QString nm)
{
    this->name=nm;
}

void MyThread::run(){
    for(int i=0; i<100;i++){
        qDebug() << this->getName() << " running " << i;
    }
}

QString MyThread::getName(){
    return this->name;
}

