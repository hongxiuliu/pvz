#include "playscene.h"

playscene::playscene(QWidget *parent) : QWidget(parent)
{
   resize(1000,1000);
   stop_times=0;
}
void playscene::init(int level){
    g=new game;
    stop=new QPushButton(this);
    save=new QPushButton(this);
    stop->setGeometry(920,100,50,50);
    save->setGeometry(920,200,50,50);
    stop->setText("暂停");
    save->setText("保存");
    connect(stop,&QPushButton::clicked,[this](){
        if(stop_times==0) g->timer->stop();
        else g->timer->start();
        stop_times=(stop_times+1)%2;
    });
    g->setParent(this);
    g->level=level;
    g->gameinit(level);
    g->gameprocess();
    show();
}
