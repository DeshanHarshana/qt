#include "ecclib.h"
#include <QDebug>
Ecclib::Ecclib()
{
}
int Ecclib::getData(){
    return 56;
}

void Ecclib::startConnection(){
    qDebug()<< "Connected";
}

QString Ecclib::getMessage(){
    return "Hellow";
}

