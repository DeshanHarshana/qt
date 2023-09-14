#include "dowork.h"
#include <QDebug>
DoWork::DoWork()
{

}

void DoWork::qRampProcess()
{
    for(int i=0; i<10; i++){
        qDebug()<<"k";
        emit UpdateGUI(i);
        QThread::msleep(1000);
    }
}
