#include "enemy2.h"

enemy2::enemy2(int level) : ennemy(level)
{
      hp+=10*level;
      movespeed+=1;
      damage+=4*level;
      drop_money=10;
      piccnt=0;
      pix.load(":/pic/pictures for project/normal01-1.png");
}
void enemy2::loadpicture(){
    piccnt=(piccnt+1)%2;
    switch (piccnt) {
    case 0:pix.load(":/pic/pictures for project/normal01-1.png"); break;
    case 1:pix.load(":/pic/pictures for project/normal01-2.png");break;
    }
}
