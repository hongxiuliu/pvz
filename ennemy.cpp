#include "ennemy.h"
#include<QMovie>
#include<QPainter>
#include<QPixmap>
#include<QDebug>
#include <QRandomGenerator>
#include<QGraphicsScene>
#define PICTURESIZE 50
int ennemy::row=0;
int ennemy::maxposition=0;
int ennemy::column=0;
int ennemy::begin_row=0;
int ennemy::map[20][20]={{0}};
QVector<int> ennemy::moveway;

ennemy::ennemy(int level)
{   setVisible(true);
    canmove=true;
    flash=false;
    nowposition=0;
    timecnt=0;
    setPos(column*80.0,100+begin_row*80);
     if(level==1||level==0){
      damage=3;
      this->movespeed=1;
      max_hp=hp=10;
  }
     else if(level==2){
         damage=4;
         this->movespeed=1;
         max_hp=hp=15;
     }
     else if(level==3){
         damage=6;
         this->movespeed=1;
         max_hp=hp=20;
     }
}
void ennemy::move(){
    if(hp<=0) {
        emit isdead(this);
        return;
    }
    if(timecnt!=0){
        timecnt=(timecnt+1)%5;
        hp-=2;
    }
    if(!canmove) return;
    if(nowposition<maxposition){
        if(moveway[nowposition]==1){
            setX(scenePos().x()-5*movespeed);
            if((int)(scenePos().x())%80==0&&(int)scenePos().x()!=column*80){
                nowposition++;
            }
        }
        else if(moveway[nowposition]==2){
           setY(scenePos().y()-5*movespeed);
           if((int)(scenePos().y()-20)%80==0){
               nowposition++;
           }
        }
        else if(moveway[nowposition]==3){
            setY(scenePos().y()+5*movespeed);
            if(((int)scenePos().y()-20)%80==0){
                nowposition++;
            }
        }
    }
   else{
        enemysucceed();
    }
}
void ennemy::deal_moveway(){
    for(int i=0;i<row;i++){
      if(map[i][column-1]==1){
          begin_row=i;
          moveway.push_back(1);
          moveway.push_back(1);
          break;
      }
    }
    int now_row=begin_row;
    int now_column=column-2;
    while(now_column>=0){
        moveway.push_back(map[now_row][now_column]);
        if(map[now_row][now_column]==2){//上移
            now_row--;
        }
        else if(map[now_row][now_column]==3){//下移
            now_row++;
        }
        else if(map[now_row][now_column]==1){//左移
            now_column--;
        }
    }
    maxposition=moveway.size();
}
bool ennemy::enemy_out_of_map(){
    return nowposition==maxposition;
}
void ennemy::enemysucceed(){
   emit over_map(this);
}
bool ennemy::enemyisdead(){
    if(hp<=0) return true;
    return false;
}
QRectF ennemy::boundingRect() const{
    return QRectF(0, 0, 80,80);
}
void ennemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
   painter->fillRect(0,0,(hp*1.0/max_hp)*80,10,Qt::red);
   painter->drawPixmap(0,10,80,70,pix);
}
void ennemy::loadpicture(){}
int ennemy::drop_buff(){
    int randomNumber = QRandomGenerator::global()->bounded(10);
    if(randomNumber==1) return 1;
    if(randomNumber==2) return 2;
    if(randomNumber==3) return 3;
    else return 0;
}
void ennemy::add_buff(int i){
    if(i==1) flash=true;
    if(i==2) movespeed*=2;
}
ennemy::ennemy(QObject *parent)
{

}
ennemy::~ennemy(){

}
