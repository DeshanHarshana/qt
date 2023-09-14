#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dowork.h"
#include <QThread>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    DoWork *doWork1;
    DoWork *doWork2;
    DoWork *doWork3;
    DoWork *doWork4;
    DoWork *doWorkTimer;

    QThread *myThread1;
    QThread *myThread2;
    QThread *myThread3;
    QThread *myThread4;
    QThread *myThreadTimer;

    void myThreads_Start();
public:
    void colorChangepb1(int x);
    void colorChangepb2(int x);
    void colorChangepb3(int x);
    void colorChangepb4(int x);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void on_pushButton_released();
    void OnDoWorkUpdateProgressBar1(int x);
    void OnDoWorkUpdateProgressBar2(int x);
    void OnDoWorkUpdateProgressBar3(int x);
    void OnDoWorkUpdateProgressBar4(int x);
    void updateTime(QString time);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
