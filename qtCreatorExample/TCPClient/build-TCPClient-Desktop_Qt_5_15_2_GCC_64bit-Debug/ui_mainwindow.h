/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *ipaddress;
    QLineEdit *port;
    QPushButton *connect;
    QVBoxLayout *verticalLayout;
    QTextEdit *server_response;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *message;
    QPushButton *send;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(802, 622);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ipaddress = new QLineEdit(centralwidget);
        ipaddress->setObjectName(QString::fromUtf8("ipaddress"));
        QFont font;
        font.setPointSize(16);
        ipaddress->setFont(font);

        horizontalLayout->addWidget(ipaddress);

        port = new QLineEdit(centralwidget);
        port->setObjectName(QString::fromUtf8("port"));
        QFont font1;
        font1.setPointSize(15);
        port->setFont(font1);
        port->setInputMethodHints(Qt::ImhNone);

        horizontalLayout->addWidget(port, 0, Qt::AlignLeft);

        connect = new QPushButton(centralwidget);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setFont(font);

        horizontalLayout->addWidget(connect);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        server_response = new QTextEdit(centralwidget);
        server_response->setObjectName(QString::fromUtf8("server_response"));

        verticalLayout->addWidget(server_response);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        message = new QLineEdit(centralwidget);
        message->setObjectName(QString::fromUtf8("message"));
        message->setFont(font);

        horizontalLayout_2->addWidget(message);

        send = new QPushButton(centralwidget);
        send->setObjectName(QString::fromUtf8("send"));
        send->setFont(font);

        horizontalLayout_2->addWidget(send);


        verticalLayout_2->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ipaddress->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ip Address", nullptr));
        port->setPlaceholderText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        message->setPlaceholderText(QCoreApplication::translate("MainWindow", "Your Message", nullptr));
        send->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
