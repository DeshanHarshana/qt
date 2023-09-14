#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtCore>

class MyThread : public QThread
{
private:
    QString name="";
public:
    MyThread(QString n);
    void run();
    QString getName();

};

#endif // MYTHREAD_H
