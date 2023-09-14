#include <QCoreApplication>
#include <mythread.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread *mThread1 = new MyThread("Thread 1");
    mThread1->start(QThread::HighPriority);

    MyThread *mThread2 = new MyThread("Thread 2");
    mThread2->start(QThread::LowestPriority);
    return a.exec();
}
