#ifndef ECCLIB_H
#define ECCLIB_H

#include "ecclib_global.h"
#include <QDebug>
class ECCLIB_EXPORT Ecclib
{
public:
    Ecclib();
    int getData();
    void startConnection();
    QString getMessage();
};

#endif // ECCLIB_H
