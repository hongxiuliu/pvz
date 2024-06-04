#include "grid.h"
#include<QPainter>
grid::grid()
{
  isplanted=false;
  setAcceptHoverEvents(true);
}

void grid::mousePressEvent(QGraphicsSceneMouseEvent *ev){
    if(ev->button()==Qt::RightButton){

    }
}
void grid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(0,0,80,80,pix);
}
QRectF grid::boundingRect() const{
    return QRectF(0,0,80,80);
}
