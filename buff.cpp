#include "buff.h"
#include<QDebug>
buff::buff(int ob_type,int spe_type)
{
   object_type=ob_type;
   specific_type=spe_type;
}




card_slot::card_slot(int type){
    card_type=type;
    switch (type) {
    case 0:pix.load(":/pic/pictures for project/ice.png");break;
    case 1:pix.load(":/pic/pictures for project/kill.png");break;
    case 2:pix.load(":/pic/pictures for project/violent.png");break;
    case 3:pix.load("");break;
    }
}
void card_slot::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(card_type==0){
        emit isclicked(":/pic/pictures for project/ice.png");
    }
    else if(card_type==1){
        emit isclicked(":/pic/pictures for project/kill.png");
    }
    else if(card_type==2){
        emit isclicked(":/pic/pictures for project/violent.png");
    }
}
void card_slot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
  painter->drawPixmap(0,0,60,60,pix);
}
QRectF card_slot::boundingRect() const{
    return QRectF(0,0,60,60);
}
