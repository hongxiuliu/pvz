#include "enemy3.h"

enemy3::enemy3(int level) : ennemy(level)
{
    hp+=40*level;
    max_hp=hp;
    type=3;
    damage+=3*level;
    drop_money=20;
    piccnt=0;
    pix.load(":/pic/pictures for project/huge01-1.png");
}
void enemy3::loadpicture(){
    piccnt=(piccnt+1)%2;
    switch (piccnt) {
    case 0:pix.load(":/pic/pictures for project/huge01-1.png"); break;
    case 1:pix.load(":/pic/pictures for project/huge01-2.png");break;
    }
}
