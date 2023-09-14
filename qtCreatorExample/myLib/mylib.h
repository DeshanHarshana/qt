#ifndef MYLIB_H
#define MYLIB_H
#include <QObject>
#include "myLib_global.h"

class MYLIB_EXPORT MyLib : public QObject
{
    Q_OBJECT
signals:
    QString emitLevel(QString level);
public slots:
    void catchRandom(int number);
public:
    MyLib();
    int getData();
};

#endif // MYLIB_H
