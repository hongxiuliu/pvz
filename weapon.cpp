#include "weapon.h"
#include<QDebug>
#include<QGraphicsScene>
#include<QMouseEvent>
#include<QRandomGenerator>

Weapon::Weapon()
{
    planted=false;
    continued_blood_deduction=false;
    rotate=0;
    damage_speed=1;
    ice_buff_num=0;
    kill_buff_num=0;
    violent_buff_num=0;
    attack=true;
    QPointF center = boundingRect().center();
            setTransformOriginPoint(center);
}
bool Weapon::isdead(){
    return hp<=0;
}
bool Weapon::isplanted(){
    return planted;
}
void Weapon::oversee(){
 if(hp<=0) emit weapondead(this);
}
QRectF Weapon::boundingRect() const{
  return QRectF(0,0,80,80);
}
void Weapon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
  painter->drawPixmap(0,0,80,80,pix);
}

void Weapon::add_buff(QString s){
  if(s==":/pic/pictures for project/ice.png"){
     for(int i=weapon_buffs.size()-1;i>=0;i--){
         if(weapon_buffs[i].specific_type==1){
             ice_bullet=false;
             weapon_buffs.erase(weapon_buffs.begin()+i);
             for(int i=0;i<3;i++){
                 scene()->removeItem(weapon_slots[i]);
                 delete weapon_slots[i];
                 weapon_slots[i]=nullptr;
             }
             weapon_slots.clear();
             return;
         }
     }
   if(weapon_buffs.size()>=2||ice_buff_num<=0) goto l;
     ice_bullet=true;
     weapon_buffs.push_back(buff(0,1));
     emit use_ice();
  }
  else if(s==":/pic/pictures for project/kill.png"){
      for(int i=weapon_buffs.size()-1;i>=0;i--){
          if(weapon_buffs[i].specific_type==2){
              damage/=2;
              continued_blood_deduction=false;
              state_kill=false;
              weapon_buffs.erase(weapon_buffs.begin()+i);
              for(int i=0;i<3;i++){
                  scene()->removeItem(weapon_slots[i]);
                  delete weapon_slots[i];
                  weapon_slots[i]=nullptr;
              }
              weapon_slots.clear();
              return;
          }
      }
     if(weapon_buffs.size()>=2||kill_buff_num<=0) goto l;
      damage*=2;
      continued_blood_deduction=true;
      state_kill=true;
      weapon_buffs.push_back(buff(0,2));
      emit use_kill();
  }
  else if (s==":/pic/pictures for project/violent.png") {
      for(int i=weapon_buffs.size()-1;i>=0;i--){
          if(weapon_buffs[i].specific_type==3){
              damage_speed=1;
              state_violent=false;
              weapon_buffs.erase(weapon_buffs.begin()+i);
              for(int i=0;i<3;i++){
                  scene()->removeItem(weapon_slots[i]);
                  delete weapon_slots[i];
                  weapon_slots[i]=nullptr;
              }
              weapon_slots.clear();
              return;
          }
      }
      if(weapon_buffs.size()>=2||violent_buff_num<=0) goto l;
     damage_speed=2;
     state_violent=true;
     weapon_buffs.push_back(buff(0,3));
     emit use_violent();
  }
 l: for(int i=0;i<weapon_slots.size();i++){
      scene()->removeItem(weapon_slots[i]);
      delete weapon_slots[i];
      weapon_slots[i]=nullptr;
  }
  weapon_slots.clear();
}
void Weapon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!planted) return;
    QPointF localPos = this->mapFromScene(event->scenePos());
        if(event->button() == Qt::LeftButton&&this->contains(localPos) ) {
            if(types==0){
              if(weapon_slots.empty()){
                for(int i=0;i<3;i++){
                    card_slot*s=new card_slot(i);
                    weapon_slots.push_back(s);
                    s->setPos(pos().x()+(i-1)*80,pos().y()+80);
                    scene()->addItem(s);
                    connect(s,&card_slot::isclicked,this,&Weapon::add_buff);
                }

                }
              else{
                  for(int i=0;i<3;i++){
                      scene()->removeItem(weapon_slots[i]);
                      delete weapon_slots[i];
                      weapon_slots[i]=nullptr;
              }
                  weapon_slots.clear();
            }
         }
            else if(types==1){
                if(weapon_slots.empty()){
                      card_slot*s=new card_slot(1);
                      weapon_slots.push_back(s);
                      s->setPos(pos().x(),pos().y()+80);
                      scene()->addItem(s);
                      connect(s,&card_slot::isclicked,this,&Weapon::add_buff);

                  }
                else{
                        scene()->removeItem(weapon_slots[0]);
                        delete weapon_slots[0];
                        weapon_slots[0]=nullptr;
                        weapon_slots.clear();
                }
            }
        }
        else if(event->button()==Qt::RightButton){
            emit weapondelete(this);
        }
}

int Weapon::drop_buff(){
    int randomNumber = QRandomGenerator::global()->bounded(10);
    if(randomNumber==1) return 1;
    if(randomNumber==2) return 2;
    else return 0;
}
void Weapon::loadpicture(){}
void Weapon::shootbullets(){}



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
   if(name=="ice"){
       numbers=0;
       pix.load(":/pic/pictures for project/ice.png");
   }
   if(name=="violent"){
       numbers=0;
       pix.load(":/pic/pictures for project/violent.png");
   }
   if(name=="kill"){
       numbers=0;
       pix.load(":/pic/pictures for project/kill.png");
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
