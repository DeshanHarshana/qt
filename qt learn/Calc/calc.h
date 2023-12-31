#ifndef CALC_H
#define CALC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calc; }
QT_END_NAMESPACE

class Calc : public QMainWindow
{
    Q_OBJECT

public:
    Calc(QWidget *parent = nullptr);
    ~Calc();

private slots:
    void NumPressed();
    void MathButtonPress();
    void EqualButton();
    void ChangeNumberSign();
    void clearButtonPressed();


private:
    Ui::Calc *ui;
};
#endif // CALC_H
