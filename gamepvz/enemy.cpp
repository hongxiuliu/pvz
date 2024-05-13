#include "enemy.h"
#include<QMovie>
#include<QPainter>
#include<QPixmap>
#define PICTURESIZE 50
enemy::enemy(int level)
{
    nowposition=0;
//  movie=new QMovie(":/gif/game_gif/enemy1.gif");
//  movie->start();
     if(level==1){
      position={880,160};
      moveway.push_back({800,160});
      moveway.push_back({640,160});
      moveway.push_back({640,80});
      moveway.push_back({240,80});
      moveway.push_back({240,240});
      moveway.push_back({0,240});
      maxposition=5;
      damage=3;
      this->movespeed=10;
      this->hp=20;
  }
}
void enemy::move(){
    if(nowposition<=maxposition){
        int x=moveway[nowposition].x()-position.x();
        int y=moveway[nowposition].y()-position.y();
        if(x<0&&y==0){
            position.rx()-=10;
        }
        if(x==0&&y<0){
            position.ry()-=10;
        }
        if(x==0&&y>0){
            position.ry()+=10;
        }
        if(x==0&&y==0){
            nowposition+=1;
        }
    }
   else{
        enemysucceed();
    }
}
void enemy::enemysucceed(){

}
QRectF enemy::boundingRect() const{
    return QRectF(position.x(), position.y(), position.x()+PICTURESIZE,position.y()+PICTURESIZE);
}
void enemy::enemyisdead(){
    if(hp<=0) emit isdead();
}
void enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    //if (movie && movie->state() == QMovie::Running)
   painter->drawPixmap(position,pix);
}
