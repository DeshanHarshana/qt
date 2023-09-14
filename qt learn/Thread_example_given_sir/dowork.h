#ifndef DOWORK_H
#define DOWORK_H

#include <QObject>
#include <QThread>

class DoWork : public QObject
{
    Q_OBJECT
signals:
    void UpdateGUI(int x);
public slots:
    void qRampProcess();

public:
    DoWork();
};

#endif // DOWORK_H
