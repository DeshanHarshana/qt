#ifndef DOWORK_H
#define DOWORK_H
#include <QObject>
#include <QThread>


class DoWork : public QThread
{
    Q_OBJECT
signals:
    void emitRandomNumber1(int x);
    void emitRandomNumber2(int x);
    void emitRandomNumber3(int x);
    void emitRandomNumber4(int x);
    void emitTimer(QString time);

public slots:
    void worker1();
    void worker2();
    void worker3();
    void worker4();
    void timer();
public:
    DoWork();

};
#endif // DOWORK_H
