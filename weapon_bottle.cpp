#include "weapon_bottle.h"

weapon_bottle::weapon_bottle()
{   hp=10;
    damage=10;
    havebullets=true;
    bullet_type=1;
    price=100;
  this->loadpicture();
}
void weapon_bottle::loadpicture(){
 pix.load(":/pic/pictures for project/ID1_5.png");
}
//void weapon_bottle::
void weapon_bottle::shootbullets(){
    for(int i=0;i<bullets.size();i++){
        bullets[i]->move();
    }
}
