#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TCP_server=new QTcpServer();
    if(TCP_server->listen(QHostAddress::LocalHost,8080)){
        //tcp_server object has their own newConnection() signal and if it trigger then
        //we execute newConnection() slot
        connect(TCP_server,SIGNAL(newConnection()), this, SLOT(newConnection()));
        QMessageBox::information(this, "QT", "Server Started");
    }else{
        QMessageBox::information(this, "QT", "server Start fail");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}




//this function is check is any client are comming or not and store it to list
/*
 *
Sure, the code you are referring to is the newConnection() function in the MainWindow class.
This function is called whenever a new client connects to the server. The function first checks
if there are any pending connections using the TCP_server->hasPendingConnections() method.
If there are pending connections, the function then calls the Add_new_Client_Connection()
function to add the new connection to a list of client connections.

The Add_new_Client_Connection() function takes a QTcpSocket object as its argument.
A QTcpSocket object represents a TCP connection between the server and a client.
The Add_new_Client_Connection() function adds the QTcpSocket object to the list of client connections
and then connects the readyRead() signal of the QTcpSocket object to the
Read_data_from_the_Socket() slot in the MainWindow class. This means that whenever
the QTcpSocket object has data available to be read, the Read_data_from_the_Socket()
slot will be called.

In summary, the newConnection() function is responsible for handling new client connections.
It first checks if there are any pending connections, and if there are,
it adds the new connections to a list of client connections and connects the
readyRead() signal of the QTcpSocket objects to the Read_data_from_the_Socket() slot.
*/
void MainWindow::newConnection()
{
    while(TCP_server->hasPendingConnections()){
        Add_new_Client_Connection(TCP_server->nextPendingConnection());
    }
}






//read data from the client
/*Sure, the code you are referring to is the Read_data_from_the_Socket()
 * method in the MainWindow class. This method is called whenever there is
 * data available to be read from a client connection. The method first
 * gets the QTcpSocket object that sent the data by calling the sender() function.
 * The sender() function returns the object that emitted the signal that called the method.
 * In this case, the signal that was emitted is the readyRead() signal of a QTcpSocket object.

Once the QTcpSocket object is obtained, the method reads all of the data from the socket
using the readAll() method. The readAll() method reads all of the data that is currently
available to be read from the socket.

The next step is to convert the data from a QByteArray object to a QString object.
A QByteArray object is a sequence of bytes, while a QString object is a sequence of characters.
The fromStdString() method can be used to convert a QByteArray object to a QString object.

Finally, the Message variable is appended to the text edit widget using the append() method.
The append() method adds the text to the end of the text edit widget.

In summary, the Read_data_from_the_Socket() method reads data from a client
connection and then displays the data in the text edit widget.
*/

void MainWindow::Read_data_from_the_Socket()
{
    QTcpSocket *socket = reinterpret_cast<QTcpSocket*>(sender());
    QByteArray Message_from_Server=socket->readAll();
    QString Message = "Client : " + QString::number(socket->socketDescriptor())+ " :: " +
                      QString::fromStdString(Message_from_Server.toStdString());

    ui->textEdit->append((Message));
}




//this function is use for store all new client connections and assign its signals and slots
/*
 * the code you are referring to is the Add_new_Client_Connection() method in the MainWindow class.
 * This method is called whenever a new client connects to the server. The method does the following:

Adds the QTcpSocket object to a list of client connections.
Connects the readyRead() signal of the QTcpSocket object to the Read_data_from_the_Socket()
slot in the MainWindow class.
Adds the socket descriptor of the QTcpSocket object to the combo box.
Displays a message in the text edit widget indicating that the client has connected.
Let me explain each of these steps in more detail:

The Client_connection_list is a list of QTcpSocket objects that represent the current client connections.
The append() method is used to add the new QTcpSocket object to the list.

The readyRead() signal is emitted by a QTcpSocket object when there is data available to be read from
the socket. The connect() function is used to connect the readyRead() signal of the new QTcpSocket
object to the Read_data_from_the_Socket() slot in the MainWindow class. This means that whenever
the readyRead() signal is emitted, the Read_data_from_the_Socket() slot will be called.

The comboBox is a combo box widget that displays a list of the current client connections. The addItem()
method is used to add the socket descriptor of the new QTcpSocket object to the combo box. This allows the
user to select a specific client connection to send data to.

The textEdit is a text edit widget that displays messages from the clients. The append() method is
used to add a message to the text edit widget indicating that the client has connected.
*/


void MainWindow::Add_new_Client_Connection(QTcpSocket *socket)
{
    Client_connection_list.append(socket);
    connect(socket, SIGNAL(readyRead()), this,SLOT(Read_data_from_the_Socket()));
    ui->comboBox->addItem((QString::number(socket->socketDescriptor())));
    QString Client= "Client : "+QString::number(socket->socketDescriptor()) + " Connected with the Server ";
    ui->textEdit->append(Client);
}




/*
 * the code you are referring to is the on_pushButton_released() method in the MainWindow class.
 * This method is called when the user clicks the "Send" button. The method does the following:

Gets the message that the user wants to send from the line edit widget.

Gets the socket descriptor of the client that the user wants to send the message to from the combo box widget.

If the user wants to send the message to all clients, the method iterates through the list of client
connections and sends the message to each client.

If the user wants to send the message to a specific client, the method iterates through the list
of client connections and sends the message to the client whose socket descriptor matches the
socket descriptor that the user selected.

Let me explain each of these steps in more detail:

The lineEdit is a line edit widget that allows the user to enter a message. The text() method is
used to get the text that the user has entered.

The comboBox is a combo box widget that allows the user to select a specific client connection.
The currentText() method is used to get the socket descriptor of the client connection that the
user has selected.

The foreach() loop iterates through the list of client connections. The socket variable is a
reference to each QTcpSocket object in the list.
The write() method is used to send the message to the QTcpSocket object. The toStdString()
method is used to convert the QString object to a QByteArray object, which is the format that
the write() method expects.


*/


void MainWindow::on_pushButton_released()
{
    QString Message_for_client=ui->lineEdit->text();
    QString Recever=ui->comboBox->currentText();
    if(ui->comboBox_SEND_MESSAGE_TYPE->currentText()=="All"){
        foreach (QTcpSocket *socket, Client_connection_list) {
            socket->write(Message_for_client.toStdString().c_str());
        }
    }else{
        foreach (QTcpSocket *socket, Client_connection_list) {
            if(socket->socketDescriptor()==Recever.toLongLong()){
                socket->write(Message_for_client.toStdString().c_str());
            }
        }
    }
}

