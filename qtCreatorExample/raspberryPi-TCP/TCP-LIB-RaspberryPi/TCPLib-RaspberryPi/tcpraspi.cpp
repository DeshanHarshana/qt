#include "tcpraspi.h"

TCPRaspi::TCPRaspi()
{
}
void TCPRaspi::startListning()
{
    TCP_server = new QTcpServer();
    if (TCP_server->listen(QHostAddress::Any, 8080)) {
        qDebug() << "Listning";
    } else {
        qDebug() << "Not Connected";
    }
    connect(TCP_server, &QTcpServer::newConnection, this, &TCPRaspi::onNewConnection);
}
void TCPRaspi::onNewConnection()
{
    QTcpSocket *socket = TCP_server->nextPendingConnection();
    Client_connection_list.append(socket);
    connect(socket, &QTcpSocket::readyRead, this, &TCPRaspi::onReadyRead);

}

void TCPRaspi::onReadyRead()
{
    QTcpSocket *socket = nullptr;
    socket = qobject_cast<QTcpSocket *>(sender());
    QByteArray message = socket->readAll();
    QString client = QString::number(socket->socketDescriptor());
    QString messageStr = QString("Message " + message + " Client ID = " + client);
    Client_connection_list.append(socket);
    emit emitClientMessage(messageStr);
}
