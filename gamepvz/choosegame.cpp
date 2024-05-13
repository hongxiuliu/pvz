#include "choosegame.h"
#include "ui_choosegame.h"

choosegame::choosegame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choosegame)
{
    ui->setupUi(this);
    connect(ui->btn1,&QPushButton::clicked,this,&choosegame::onCloseButton1Closed);
//    connect(ui->btn2,&QPushButton::clicked,g,[=]()mutable{
//        g->level=2;
//        this->close();
//        g->gameinit(2);

//        g->show();
//    });
//    connect(ui->btn3,&QPushButton::clicked,g,[=]()mutable{
//        g->level=3;
//        this->close();
//        g->gameinit(3);
//        g->show();
//        g->gameprocess(3);
//    });

}
void choosegame::onCloseButton1Closed(){
   g=new game;
   g->level=1;
   g->gameinit(1);
   g->gameprocess();
   g->show();
   this->close();
}

choosegame::~choosegame()
{
    delete ui;
}
