#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()), this, SLOT(abc()));
    timer.start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->progressBar->setValue(ui->progressBar->value() + 5);
}

void Widget::abc()
{
    ui->progressBar->setValue(ui->progressBar->value() - 1);
    if (ui->progressBar->value() == 0) {
        close();
    }
}
