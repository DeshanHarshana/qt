#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include "worker.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    qInfo()<<"Starting"<<QThread::currentThread();
    qInfo()<< "Doing Stuff"<<QThread::currentThread();
    //Worker worker;
   // worker.run();
    Worker *worker =new Worker();
    QThread thread;
    thread.setObjectName("Woker Thread");
    worker->moveToThread(&thread);
    QObject::connect(&thread, &QThread::started,worker,&Worker::run);
    thread.start();
    qInfo()<<"Finish"<<QThread::currentThread();

    return a.exec();
}
