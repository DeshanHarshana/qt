#ifndef TCPRASPI_H
#define TCPRASPI_H

#include "TCPLib-RaspberryPi_global.h"
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QObject>
#include <QList>
class TCPLIBRASPBERRYPI_EXPORT TCPRaspi: public QObject
{
    Q_OBJECT
signals:
    void emitClientMessage(QString message);
public slots:
    void onNewConnection();
    void onReadyRead();
public:
    TCPRaspi();
    void startListning();
private:
    QTcpServer *TCP_server;
    QList<QTcpSocket*> Client_connection_list;
};

#endif // TCPRASPI_H
