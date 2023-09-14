#ifndef WORKER_H
#define WORKER_H
#include <QThread>
#include <QDebug>

class Worker : public QThread
{
public:
    Worker();


public slots:
    void run();
};



#endif // WORKER_H
