#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->coffee100->setEnabled(false);
    ui->tea150->setEnabled(false);
    ui->milk200->setEnabled(false);

    connect(ui->won10,SIGNAL(signal1()),this,SLOT(won10_clicked()));
    connect(ui->won50,SIGNAL(clicked()),this,SLOT(won50_clicked()));
    connect(ui->won100,SIGNAL(clicked()),this,SLOT(won100_clicked()));
    connect(ui->won500,SIGNAL(clicked()),this,SLOT(won500_clicked()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::Money(int coin)
{
    this->total_money+=coin;
    ui->Money->display(total_money);
    if(total_money<100){
        ui->coffee100->setEnabled(false);
        ui->tea150->setEnabled(false);
        ui->milk200->setEnabled(false);
    }
    else if(this->total_money<150){
        ui->coffee100->setEnabled(true);
        ui->tea150->setEnabled(false);
        ui->milk200->setEnabled(false);
    }
    else if(this->total_money<200){
        ui->coffee100->setEnabled(true);
        ui->tea150->setEnabled(true);
        ui->milk200->setEnabled(false);
    }
    else{
        ui->coffee100->setEnabled(true);
        ui->tea150->setEnabled(true);
        ui->milk200->setEnabled(true);
    }

    connect(ui->won10,SIGNAL(signal1()),this,SLOT(won10_clicked()));
    connect(ui->won50,SIGNAL(clicked()),this,SLOT(won50_clicked()));
    connect(ui->won100,SIGNAL(clicked()),this,SLOT(won100_clicked()));
    connect(ui->won500,SIGNAL(clicked()),this,SLOT(won500_clicked()));
    connect(ui->milk200,SIGNAL(clicked()),this,SLOT(milk_clicked()));
    connect(ui->tea150,SIGNAL(clicked()),this,SLOT(tea_clicked()));
    connect(ui->coffee100,SIGNAL(clicked()),this,SLOT(coffee_clicked()));
    connect(ui->reset,SIGNAL(clicked()),this,SLOT(reset_clicked()));

}

void Widget::reset_clicked(){
    QString msg=QString::number(this->total_money);
    QMessageBox::information(this,"Left Money",msg);
    this->total_money=0;
    Money(0);

}
void Widget::coffee_clicked()
{
    Money(-100);
}

void Widget::tea_clicked()
{
    Money(-150);
}

void Widget::milk_clicked()
{
    Money(-200);
}

void Widget::won10_clicked()
{
    Money(10);
}

void Widget::won50_clicked()
{
    Money(50);
}

void Widget::won100_clicked()
{
    Money(100);
}

void Widget::won500_clicked()
{
    Money(500);
}




