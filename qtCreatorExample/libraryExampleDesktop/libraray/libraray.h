#ifndef LIBRARAY_H
#define LIBRARAY_H
#include <QObject>
#include "libraray_global.h"

class LIBRARAY_EXPORT Libraray: public QObject
{
    Q_OBJECT
signals:
    QString emitLevel(QString level);
public slots:
    void catchRandom(int number);
public:
    Libraray();
    int getData();
};

#endif // LIBRARAY_H
