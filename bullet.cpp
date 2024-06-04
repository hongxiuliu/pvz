#include "bullet.h"

bullet::bullet(double rotate,int type,QPointF pos,int dam)
{
  rotate_angle=rotate;
  position=pos;
  position+={40,40};
  setPos(position);
  setRotation(rotate);
  types=type;
  if(type==1){
    pix.load(":/pic/pictures for project/ID1_7.png");
    move_speed=10;
    damage=dam;
  }
  else if(type==2){
   pix.load(":/pic/pictures for project/ice_bullet.png");
   move_speed=10;
   damage=dam;
  }
  else if(type==3){
      pix.load(":/pic/pictures for project/ID2_13.png");
      move_speed=10;
      damage=dam;
  }
  move_x=move_speed*std::cos((rotate/180.0)*M_PI);
  move_y=move_speed*std::sin((rotate/180.0)*M_PI);

}
void bullet::move(){
   position.setX(position.x()+move_x);
   position.setY(position.y()+move_y);
   setPos(position);
}
void bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
  painter->drawPixmap(0,0,30,30,pix);
}
QRectF bullet::boundingRect() const{
  return QRectF(0,0,30,30);
}
