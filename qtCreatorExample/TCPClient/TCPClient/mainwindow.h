#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
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
    void on_connect_clicked();
    void Read_data_from_socket();

    void on_send_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *TCPSocket;
};
#endif // MAINWINDOW_H
