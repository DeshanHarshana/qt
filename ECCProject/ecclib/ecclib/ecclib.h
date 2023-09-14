#ifndef ECCLIB_H
#define ECCLIB_H

#include "ecclib_global.h"
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QObject>
#include <QList>

class ECCLIB_EXPORT Ecclib : public QObject
{
    Q_OBJECT
signals:
    void emitClientMessage(QString message);
    void emitSocket(QTcpSocket *socket);

public:
    Ecclib();
    void startListning();


public slots:
    void onNewConnection();
    void onReadyRead();
    void onSendMessage(QString message);

private:
    QTcpServer *TCP_server;
    QList<QTcpSocket*> Client_connection_list;
};

#endif // ECCLIB_H
