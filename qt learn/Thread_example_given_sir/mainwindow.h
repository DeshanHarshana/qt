#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <dowork.h>
#include <QMainWindow>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    DoWork *doWork;
    QThread *qRampingThread;
    void QSWRampStart();


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




public slots:
    void on_pushButton_clicked();
    void OnDoWorkUpdateEvents(int x);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
