#include "worker.h"

Worker::Worker()
{
    qInfo()<<this<<"Constructed"<<QThread::currentThread();
}

void Worker::run()
{
    for(int i=0; i<10;i++){
        qInfo()<<this <<"Working"<<QString::number(i);
        QThread::currentThread()->msleep(500);
    }

    this->deleteLater();

}
