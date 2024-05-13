#include "enemy3.h"

enemy3::enemy3(int level) : ennemy(level)
{
    hp+=20*level;
    //movespeed+=1;
    damage+=3*level;

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
