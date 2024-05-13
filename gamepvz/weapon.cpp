#include "weapon.h"

Weapon::Weapon()
{

}
QRectF Weapon::boundingRect() const{
  return QRectF(0,0,100,100);
}
void Weapon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
  painter->drawPixmap(0,0,80,80,pix);
}
void Weapon::mouseMoveEvent(QGraphicsSceneMouseEvent *event){

}
void Weapon::mousePressEvent(QGraphicsSceneMouseEvent *event){

}
void Weapon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

}
Weapon* Weapon::copyweapon(){
    Weapon* NewWeapon=new Weapon;
    return NewWeapon;
}




card::card(QString n)
{
   name=n;
   if(name=="bottle"){

       //setPos()
   }
}
void card::setcoins(int coins){
    needcoins=coins;
}
bool card::canbuycard(int coins){
    return needcoins<=coins;
}
