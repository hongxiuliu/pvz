#include "weapon.h"
#include<QDebug>
#include<QMouseEvent>
Weapon::Weapon()
{
    planted=false;
    rotate=0;
    QPointF center = boundingRect().center();
            setTransformOriginPoint(center);
    //connect(this,&Weapon::shoot,this,&Weapon::shootbullets);

}
bool Weapon::isdead(){
    return hp<=0;
}
bool Weapon::isplanted(){
    return planted;
}
void Weapon::oversee(){
 if(hp<=0)
     emit weapondead(this);
}
QRectF Weapon::boundingRect() const{
  return QRectF(0,0,80,80);
}
void Weapon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
  painter->drawPixmap(0,0,80,80,pix);
}
//void Weapon::mouseMoveEvent(QGraphicsSceneMouseEvent *event){

//}
//void Weapon::mousePressEvent(QGraphicsSceneMouseEvent *event){
//    QPointF localPos = this->mapFromScene(event->scenePos());
//       qDebug()<< "Clicked on Weapon at:" << event->scenePos();
//       qDebug()<<reinterpret_cast<quintptr>(static_cast<const void*>(this));
//        if(event->button() == Qt::RightButton&&this->contains(localPos) ) {
//            qDebug()<< "Clicked on Weapon at:" << event->scenePos();

//        } else {

//        }
//}
//void Weapon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

////qDebug()<<"yyds";
//}
Weapon* Weapon::copyweapon(){
    Weapon* NewWeapon=new Weapon;
    return NewWeapon;
}
void Weapon::loadpicture(){

}
void Weapon::shootbullets(){

}



card::card(QString n)
{
   name=n;
   if(name=="bottle"){
    pix.load(":/pic/pictures for project/bottle_CanClick1.png");
    setcoins(100);
   }
   if(name=="shit"){
       pix.load(":/pic/pictures for project/CanClick1.png");
       setcoins(120);
   }
}
QString card::getname(){
    return name;
}
void card::setcoins(int coins){
    needcoins=coins;
}
bool card::canbuycard(int coins){
    return needcoins<=coins;
}
void card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(0,0,80,80,pix);

}
QRectF card::boundingRect() const{
    return QRectF(0,0,80,80);
}
