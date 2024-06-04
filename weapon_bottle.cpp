#include "weapon_bottle.h"
int weapon_bottle::uplevel=0;
weapon_bottle::weapon_bottle()
{   types=0;
    hp=10;
    damage=8+uplevel;
    havebullets=true;
    bullet_type=1;
    price=100;
    attack_range=400;
    ice_bullet=false;
    state_kill=false;
    state_violent=false;
  this->loadpicture();
}
void weapon_bottle::loadpicture(){
 pix.load(":/pic/pictures for project/ID1_5.png");
 if(ice_bullet){
     pix.load(":/pic/pictures for project/ID1_8.png");
 }
 if(state_kill){
     pix.load(":/pic/pictures for project/ID1_9.png");
 }
 if(state_violent){
     pix.load(":/pic/pictures for project/ID1_10.png");
 }
}
void weapon_bottle::shootbullets(){
    for(int i=0;i<bullets.size();i++){
        bullets[i]->move();
    }
}
