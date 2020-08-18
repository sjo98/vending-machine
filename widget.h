#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDesktopWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void Money(int coin);
    int total_money = 0;

private:
    Ui::Widget *ui;

signals:
    void signal1();
    void signal2();
    void signal3();
    void signal4();
    void signal5();
    void signal6();
    void signal7();
    void signal8();
    void signal9();
private slots:
    void coffee_clicked();
    void milk_clicked();
    void tea_clicked();
    void won10_clicked();
    void won50_clicked();
    void won100_clicked();
    void won500_clicked();
    void reset_clicked();

};
#endif // WIDGET_H
