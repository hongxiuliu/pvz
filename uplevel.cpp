#include "uplevel.h"
#include "ui_uplevel.h"
#include<QDebug>
Uplevel::Uplevel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Uplevel)
{
    ui->setupUi(this);
    this->resize(500,500);
    label=new QLabel(this);
    label->setGeometry(0,0,this->width(),this->height());
    pix.load(":/pic/pictures for project/initial background.jpg");
    label->setPixmap(pix);
    QPixmap actual=pix.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    label->setPixmap(actual);
    label->lower();

    manager.file.setFileName(":/files/map/game_state.dat.txt");
    manager.cin.setDevice(&manager.file);
    if(manager.file.open(QIODevice::ReadOnly | QIODevice::Text)){
        manager.cin>>manager.state;
        weapon_shit::uplevel=manager.cin.readLine().toInt();
        weapon_bottle::uplevel=manager.cin.readLine().toInt();
    }
    manager.file.close();
    connect(ui->back,&QPushButton::clicked,this,[this](){
        emit back_to_begin_interface();
    });
    ui->label3->setText(QString("经验值：%1").arg(manager.state.expeience));
    ui->label1->setText(QString("所需经验80"));
    ui->label2->setText(QString("所需经验80"));
    connect(ui->uplevel1,&QPushButton::clicked,this,&Uplevel::up_short_range_weapon);
    connect(ui->uplevel2,&QPushButton::clicked,this,&Uplevel::up_long_range_weapon);
}
void Uplevel::canbuy(){
        manager.state.expeience-=80;
        manager.file.setFileName("D:/qtcode/gamepvz/map/game_state.dat.txt");
        manager.cout.setDevice(&manager.file);
        if(manager.file.open(QIODevice::WriteOnly | QIODevice::Text)){
           manager.cout<<manager.state;
           manager.cout<<weapon_shit::uplevel<<endl;
           manager.cout<<weapon_bottle::uplevel<<endl;
        }
        manager.file.close();
        ui->label3->setText(QString("经验值：%1").arg(manager.state.expeience));    
}
void Uplevel::up_long_range_weapon(){
    if(manager.state.expeience>=80){
    weapon_bottle::uplevel++;
    canbuy();
    qDebug()<<weapon_bottle::uplevel<<"升级成功";
    }
    else{
        qDebug()<<"经验不足，升级失败";
    }
}
void Uplevel::up_short_range_weapon(){
    if(manager.state.expeience>=80){
    weapon_shit::uplevel++;
    canbuy();
    qDebug()<<weapon_shit::uplevel<<"升级成功";
    }
    else{
        qDebug()<<"经验不足，升级失败";
    }
}
Uplevel::~Uplevel()
{
    delete ui;
}
