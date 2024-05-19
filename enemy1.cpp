#include "enemy1.h"

enemy1::enemy1(int level):ennemy(level)
{ hp+=30*level;
  movespeed+=1;
  damage+=3*level;
  drop_money=15;
  count=0;
  pix.load(":/pic/pictures for project/fast01-1.png");
}
void enemy1::loadpicture(){
    count=(count+1)%2;
    switch (count) {
    case 0:pix.load(":/pic/pictures for project/fast01-1.png"); break;
    case 1:pix.load(":/pic/pictures for project/fast01-2.png");break;
    }

}
