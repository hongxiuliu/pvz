#include "ennemy.h"
#include<QMovie>
#include<QPainter>
#include<QPixmap>
#include<QDebug>
#define PICTURESIZE 50
ennemy::ennemy(int level)
{   setVisible(true);
    canmove=true;
    nowposition=0;
     if(level==1){
      setPos(QPoint(880,160));
      moveway.push_back({640,160});
      moveway.push_back({640,80});
      moveway.push_back({240,80});
      moveway.push_back({240,240});
      moveway.push_back({0,240});
      maxposition=5;
      damage=3;
      this->movespeed=1;
      this->hp=10;
  }
}
void ennemy::move(){
    if(!canmove) return;
    if(nowposition<maxposition){
        int x=moveway[nowposition].x()-scenePos().x();
        int y=moveway[nowposition].y()-scenePos().y();
        if(x<0&&y==0){
           setX(scenePos().x()-5*movespeed);
        }
        if(x==0&&y<0){
             setY(scenePos().y()-5*movespeed);
        }
        if(x==0&&y>0){
            setY(scenePos().y()+5*movespeed);
        }
        if(x==0&&y==0){
            nowposition+=1;
        }
    }
   else{
        enemysucceed();
    }
}
bool ennemy::enemy_out_of_map(){
    return nowposition==maxposition;
}
void ennemy::enemysucceed(){
   emit over_map();
}
bool ennemy::enemyisdead(){
    if(hp<=0) return true;
    return false;
}
QRectF ennemy::boundingRect() const{
    //qDebug()<<position.x();
    return QRectF(0, 0, 100,100);
}
void ennemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

   painter->drawPixmap(0,0,80,80,pix);
}
void ennemy::loadpicture(){

}
ennemy::ennemy(QObject *parent)
{

}
