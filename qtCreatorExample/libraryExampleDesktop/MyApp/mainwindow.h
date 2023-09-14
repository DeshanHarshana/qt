#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "libraray.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    int emitRandomValue(int value);
public slots:
    void on_pushButton_released();
    void catchLevel(QString level);
public:
    Libraray *myLib;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
