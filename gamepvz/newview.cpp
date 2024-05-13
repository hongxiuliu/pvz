#include "newview.h"

newview::newview(QWidget* widget)
{
    this->setParent(widget);
    nowweapon=nullptr;

}
void newview::mouseMoveEvent(QMouseEvent *event){
    if(nowweapon){
        nowweapon->setPos(event->pos());
    }

}
void newview::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        for(int i=0;i<cards.size();i++){
            if(cards[i]->contains(event->pos())&&cards[i]->canbuycard(coins)){
            nowweapon=new Weapon;
            nowweapon->setPos(event->pos());
            break;
            }
        }
    }
}
void newview::mouseReleaseEvent(QMouseEvent *event){
     if(event->button()==Qt::LeftButton&&nowweapon){

     }
}
