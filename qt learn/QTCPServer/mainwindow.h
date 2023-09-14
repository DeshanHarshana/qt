#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QByteArray>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void newConnection();
    void Read_data_from_the_Socket();
    void on_pushButton_released();

private:
    void Add_new_Client_Connection(QTcpSocket *socket);

private:
    Ui::MainWindow *ui;
    QTcpServer *TCP_server;
    QList<QTcpSocket*> Client_connection_list;
};
#endif // MAINWINDOW_H
