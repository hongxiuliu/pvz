#include "enemy1.h"

enemy1::enemy1(int level):ennemy(level)
{ hp+=30*level;
  type=1;
  max_hp=hp;
  movespeed+=1;
  damage+=3*level;
  drop_money=15;
  count=0;
  iced=false;
  pix.load(":/pic/pictures for project/fast01-1.png");
}
void enemy1::loadpicture(){
    count=(count+1)%2;
    if(!iced){
    switch (count) {
    case 0:pix.load(":/pic/pictures for project/fast01-1.png"); break;
    case 1:pix.load(":/pic/pictures for project/fast01-2.png");break;
    }
    }
    else{
        switch (count) {
        case 0:pix.load(":/pic/pictures for project/ice_fast_1.png");break;
        case 1:pix.load(":/pic/pictures for project/ice_fast_2.png");break;
        }
    }

}
