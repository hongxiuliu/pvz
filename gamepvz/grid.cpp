#include "grid.h"

grid::grid()
{
  isplanted=false;
}
void grid::mousePressEvent(QGraphicsSceneMouseEvent *ev){
    if(ev->button()==Qt::LeftButton){
        qDebug()<<"yes";
    }
}
