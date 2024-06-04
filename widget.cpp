#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
   label=new QLabel(this);
   //label->resize(this->size());
    pix.load(":/pic/pictures for project/initial background.jpg");
    label->setPixmap(pix);

    choosegame*choose =new choosegame;
    Uplevel*uplevel=new Uplevel;
    connect(ui->beginbut,&QPushButton::clicked,choose,[=]()mutable{
        choose->show();
        this->close();
    });
    connect(ui->setbtn,&QPushButton::clicked,[=]()mutable{
        uplevel->show();
        this->close();
    });
    connect(uplevel,&Uplevel::back_to_begin_interface,this,[=]()mutable{
        this->show();
        uplevel->close();
    });
    connect(choose,&choosegame::back_to_start,[=]()mutable{
       this->show();
       choose->close();
    });
}

Widget::~Widget()
{
    delete ui;
}

