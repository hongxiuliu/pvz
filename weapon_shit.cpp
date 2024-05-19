#include "weapon_shit.h"

weapon_shit::weapon_shit()
{  hp=150;
  damage=5;
  price=120;
  havebullets=false;
this->loadpicture();
}
void weapon_shit::loadpicture(){
    pix.load(":/pic/pictures for project/ID2_37.png");
}
