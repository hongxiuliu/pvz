#include "choosegame.h"
#include "ui_choosegame.h"

choosegame::choosegame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choosegame)
{
    ui->setupUi(this);
    resize(500,500);
    label=new QLabel(this);
    label->setGeometry(0,0,this->width(),this->height());
    pix.load(":/pic/pictures for project/initial background.jpg");
    QPixmap actual=pix.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    label->setPixmap(actual);
    label->lower();
   connect(ui->btn1,&QPushButton::clicked,this,&choosegame::onCloseButton1Closed);
   connect(ui->btn2,&QPushButton::clicked,this,&choosegame::onCloseButton2Closed);
   connect(ui->btn3,&QPushButton::clicked,this,&choosegame::onCloseButton3Closed);
   connect(ui->btn4,&QPushButton::clicked,this,&choosegame::onCloseButton4Closed);
   connect(ui->btn5,&QPushButton::clicked,[this](){
      emit back_to_start();
   });
}
void choosegame::show_the_interface(){
    this->show();
    s->close();
}
void choosegame::onCloseButton1Closed(){
    s=new playscene;
    s->level=1;
    s->init(1);
   this->close();
    connect(s,&playscene::back_to_chooselevelscene,this,&choosegame::show_the_interface);
    connect(s->g,&game::save,this,&choosegame::show_the_interface);
    s->show();
}
void choosegame::onCloseButton2Closed(){
    s=new playscene;
    s->level=2;
    s->init(2);
   this->close();
    connect(s,&playscene::back_to_chooselevelscene,this,&choosegame::show_the_interface);
    s->show();
}
void choosegame::onCloseButton3Closed(){
    s=new playscene;
    s->level=3;
    s->init(3);
   this->close();
    connect(s,&playscene::back_to_chooselevelscene,this,&choosegame::show_the_interface);
    s->show();
}
void choosegame::onCloseButton4Closed(){
   manager.file.setFileName("D:/qtcode/gamepvz/map/game_state.dat.txt");
   manager.cout.setDevice(&manager.file);
   if(manager.file.open(QIODevice::WriteOnly|QIODevice::Text)){
       for(int i=0;i<4;i++){
           manager.cout<<0<<endl;
       }
   }
   manager.file.close();
   qDebug()<<"已恢复初值！";
}
choosegame::~choosegame()
{
    delete ui;
}
