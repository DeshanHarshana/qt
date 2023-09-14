#ifndef TCP_LIB_H
#define TCP_LIB_H

#include "TCP_Lib_global.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QObject>
#include <QList>
class TCP_LIB_EXPORT TCP_Lib : public QObject
{
    Q_OBJECT

signals:
    void emitClientMessage(QString message);
    void emitSocket(QTcpSocket *socket);
public slots:
    void onNewConnection();
    void onReadyRead();
    void onSendMessage(QString message, int socketId);
public:
    TCP_Lib();
    void startListning();
private:
    QTcpServer *TCP_server;
    QList<QTcpSocket*> Client_connection_list;
};

#endif // TCP_LIB_H
