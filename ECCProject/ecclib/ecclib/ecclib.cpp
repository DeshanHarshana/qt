#include "ecclib.h"

Ecclib::Ecclib()
{

}

void Ecclib::startListning()
{
    TCP_server = new QTcpServer();
    if (TCP_server->listen(QHostAddress::Any, 8080)) {
        qDebug() << "Listning";
    } else {
        qDebug() << "Not Connected";
    }
    connect(TCP_server, &QTcpServer::newConnection, this, &Ecclib::onNewConnection);
}

void Ecclib::onNewConnection()
{
    QTcpSocket *socket = TCP_server->nextPendingConnection();
    Client_connection_list.append(socket);
    connect(socket, &QTcpSocket::readyRead, this, &Ecclib::onReadyRead);
    emit emitSocket(socket);
}

void Ecclib::onReadyRead()
{

    QTcpSocket *socket = nullptr;
    socket = qobject_cast<QTcpSocket *>(sender());
    QByteArray message = socket->readAll();
    QString client = QString::number(socket->socketDescriptor());
    QString messageStr = QString(message + " " + client);

    Client_connection_list.append(socket);
    emit emitClientMessage(messageStr);
}

void Ecclib::onSendMessage(QString message)
{
    foreach (QTcpSocket *socket, Client_connection_list) {
        socket->write((message+"\n").toStdString().c_str());
    }
}

