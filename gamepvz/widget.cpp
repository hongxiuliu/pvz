#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    choosegame*s =new choosegame;
    connect(ui->beginbut,&QPushButton::clicked,s,[=]()mutable{
        s->show();
        this->close();
    });
}

Widget::~Widget()
{
    delete ui;
}

