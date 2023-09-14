#include "tcp_lib.h"

TCP_Lib::TCP_Lib()
{
}
void TCP_Lib::startListning()
{
    TCP_server = new QTcpServer();
    if (TCP_server->listen(QHostAddress::Any, 8080)) {
        qDebug() << "Listning";
    } else {
        qDebug() << "Not Connected";
    }
    connect(TCP_server, &QTcpServer::newConnection, this, &TCP_Lib::onNewConnection);
}
void TCP_Lib::onNewConnection()
{
    QTcpSocket *socket = TCP_server->nextPendingConnection();
    Client_connection_list.append(socket);
    connect(socket, &QTcpSocket::readyRead, this, &TCP_Lib::onReadyRead);

}

void TCP_Lib::onReadyRead()
{
    QTcpSocket *socket = nullptr;
    socket = qobject_cast<QTcpSocket *>(sender());
    QByteArray message = socket->readAll();
    QString client = QString::number(socket->socketDescriptor());
    QString messageStr = QString("Message " + message + " Client ID = " + client);
    // Check if the socket is already in the list
    bool isInList = false;
    for (QTcpSocket *s : Client_connection_list) {
        if (s == socket) {
            isInList = true;
            break;
        }
    }

    // If the socket is not in the list, add it
    if (!isInList) {
        Client_connection_list.append(socket);
    }
    emit emitSocket(socket);
    emit emitClientMessage(messageStr);
}
void TCP_Lib::onSendMessage(QString message, int SocketId)
{

    foreach (QTcpSocket *socket, Client_connection_list) {
        if(socket->socketDescriptor() == SocketId){

            socket->write((message+"\n").toStdString().c_str());
        }
    }




}
