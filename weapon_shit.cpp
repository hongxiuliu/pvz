#include "weapon_shit.h"
int weapon_shit::uplevel=0;
weapon_shit::weapon_shit()
{   types=1;
    hp=200;
  damage=2+uplevel;
  price=120;
  havebullets=true;
  bullet_type=2;
  attack_range=80;
  damage_speed=2;
this->loadpicture();
}
void weapon_shit::loadpicture(){
    pix.load(":/pic/pictures for project/ID2_37.png");
}
void weapon_shit::shootbullets(){
    for(int i=0;i<bullets.size();i++){
        bullets[i]->move();
    }
}
