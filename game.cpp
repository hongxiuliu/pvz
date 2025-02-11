#include "game.h"
#include "ui_game.h"
#include<QMovie>
game::game():
    ui(new Ui::game)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 900, 800);
    setScene(scene);
    setStyleSheet("background:transparent");
    game_coins=1500;
    numof_wave=0;
    now_weapon=nullptr;
    manager.file.setFileName("D:/qtcode/gamepvz/map/game_state.dat.txt");
    manager.cin.setDevice(&manager.file);
    if(manager.file.open(QIODevice::ReadOnly|QIODevice::Text)){
        manager.cin>>manager.state;
        int nowrow=0;
        while(nowrow++<2) manager.cin.readLine();
        weapon_shit::uplevel=manager.cin.readLine().toInt();
        weapon_bottle::uplevel=manager.cin.readLine().toInt();
        qDebug()<<weapon_shit::uplevel;
    }
    manager.file.close();
    connect(this,&game::succeed,this,&game::game_succeed);
    connect(this,&game::lose,this,&game::game_lose);
    connect(this,&game::use_buff,this,&game::send_buff);
}
void game::gameinit(int level){
    timecount=0;
    enemystart=false;
    switch (level) {
    case 1:wave_of_enemy=4;break;
    case 2:wave_of_enemy=8;break;
    case 3:wave_of_enemy=10;break;
    }
   QPixmap p1(":/pic/pictures for project/floor.png");
   p1.scaled(80,80);
   QPixmap p2(":/pic/pictures for project/grass.png");
   p2.scaled(80,80);
   m=new mapp(level);
   ennemy::column=m->map1[0].size();
   ennemy::row=m->map1.size();
   for(int i=0;i<m->map1.size();i++){
       for(int j=0;j<m->map1[i].size();j++){
           ennemy::map[i][j]=m->map1[i][j]-48;
           m->map[i][j]=new grid;
           m->map[i][j]->setPos(80*j,100+80*i);
           scene->addItem(m->map[i][j]);
           if(m->map1[i][j]=='0'){
               m->map[i][j]->pix.load(":/pic/pictures for project/grass.png");
               m->map[i][j]->types=0;
           }
           else{
               m->map[i][j]->pix.load(":/pic/pictures for project/floor.png");
               m->map[i][j]->types=1;
           }

       }
   }
   ennemy::deal_moveway();
    card*card1=new card("bottle");
    card*card2=new card("shit");
    cards.push_back(card1);
    cards.push_back(card2);
    for(int i=0;i<cards.size();i++){
       cards[i]->setPos(80*i,0);
       scene->addItem(cards[i]);
   }
  this->resize(900,800);
   if(level==1){
       wholeblood=10;
   }
   else if(level==2){
       wholeblood=8;
   }
   else if(level==3){
       wholeblood=8;
   }
   card*buff1=new card("ice");
   card*buff2=new card("kill");
   card*buff3=new card("violent");
   cards.push_back(buff1);
   cards.push_back(buff2);
   cards.push_back(buff3);
   scene->addItem(buff1);
   scene->addItem(buff2);
   scene->addItem(buff3);
   buff1->setPos({600,0});
   buff2->setPos({700,0});
   buff3->setPos({800,0});
   buff1->setEnabled(false);
   buff2->setEnabled(false);
   buff3->setEnabled(false);

   for(int i=0;i<3;i++){
       buff_num[i]=0;
       QGraphicsTextItem* newText=new QGraphicsTextItem("0");
       scene->addItem(newText);
       buff_numbers.push_back(newText);
       newText->setPos({600.0+i*100,0});
   }
   game_coin="金币数量：%1";
   game_wave="关卡：%1/%2";
   game_life="血量：%1";
   game_life=game_life.arg(wholeblood);
   game_wave=game_wave.arg(numof_wave).arg(wave_of_enemy);
   game_coin=game_coin.arg(game_coins);
   display_life=new QGraphicsTextItem(game_life);
   display_wave=new QGraphicsTextItem(game_wave);
   display_coin=new QGraphicsTextItem(game_coin);
   scene->addItem(display_coin);
   scene->addItem(display_wave);
   scene->addItem(display_life);
   display_life->setPos(450,730);
   display_coin->setPos(50,730);
   display_wave->setPos(250,730);
   display_life->setDefaultTextColor(Qt::red);
   display_life->setFont(QFont("Arial", 12));
   display_wave->setDefaultTextColor(Qt::blue);
   display_wave->setFont(QFont("Arial", 12));
   display_coin->setDefaultTextColor(Qt::blue);
   display_coin->setFont(QFont("Arial", 12));
}
void game::gameprocess(){
    timer=new QTimer(this);
    timer->setInterval(150);
   // timer->start();
    connect(timer,&QTimer::timeout,[&](){
        timecount++;
    if(timecount==1){
        enemystart=true;
        //qDebug()<<level;
        numof_wave=1;
        game_wave="波数：1/%1";
        game_wave=game_wave.arg(wave_of_enemy);
        display_wave->setPlainText(game_wave);
        first_wave();
    }
    if(timecount==100){
        second_wave();
        numof_wave=2;
        game_wave="波数：2/%1";
         game_wave=game_wave.arg(wave_of_enemy);
        display_wave->setPlainText(game_wave);
    }
    if(timecount==200){
        third_wave();
        numof_wave=3;
        game_wave="波数：3/%1";
         game_wave=game_wave.arg(wave_of_enemy);
        display_wave->setPlainText(game_wave);
    }
    if(timecount==300){
        fourth_wave();
        numof_wave=4;
        game_wave="波数：4/%1";
         game_wave=game_wave.arg(wave_of_enemy);
        display_wave->setPlainText(game_wave);
    }
    if(level>=2&&timecount==600){
        fifth_wave();
        numof_wave=5;
        game_wave="波数：5/%1";
         game_wave=game_wave.arg(wave_of_enemy);
        display_wave->setPlainText(game_wave);
    }
    if(level>=2&&timecount==750){
        sixth_wave();
        numof_wave=6;
        game_wave="波数：6/%1";
         game_wave=game_wave.arg(wave_of_enemy);
        display_wave->setPlainText(game_wave);
    }
    if(level>=2&&timecount==900){
        seventh_wave();
        numof_wave=7;
        game_wave="波数：7/%1";
         game_wave=game_wave.arg(wave_of_enemy);
        display_wave->setPlainText(game_wave);
    }
    if(level>=2&&timecount==1050){
        eighth_wave();
        numof_wave=8;
        game_wave="波数：8/%1";
         game_wave=game_wave.arg(wave_of_enemy);
        display_wave->setPlainText(game_wave);
    }
    if(level>=3&&timecount==1200){
        ninth_wave();
        numof_wave=9;
        game_wave="波数：9/%1";
         game_wave=game_wave.arg(wave_of_enemy);
        display_wave->setPlainText(game_wave);
    }
    if(level>=3&&timecount==1400){
        tenth_wave();
        numof_wave=10;
        game_wave="波数：10/%1";
         game_wave=game_wave.arg(wave_of_enemy);
        display_wave->setPlainText(game_wave);
    }
    } );
    connect(timer,&QTimer::timeout,[&]()mutable{
       if(wholeblood<=0) emit lose();
       dealcollide();
       enemy_oversee();
        for(int i=0;i<monsters.size();i++){
            monsters[i]->loadpicture();
            monsters[i]->move();
        }
        for(int i=0;i<weapons.size();i++){
          weapons[i]->oversee();
          weapons[i]->loadpicture();
        }

        for(int i=0;i<weapons.size();i++){
            if(weapons[i]->havebullets){
                 weapons[i]->shootbullets();
                if(((timecount*weapons[i]->damage_speed)%6)==0&&monsters.size()>0&&weapons[i]->attack)create_new_bullet(weapons[i]);

            }
        }
    } );

}
void game::game_succeed(){
    timer->stop();
    manager.file.setFileName(":/files/map/game_state.dat.txt");
    manager.cout.setDevice(&manager.file);
    if(manager.file.open(QIODevice::WriteOnly | QIODevice::Text)){
       manager.cout<<manager.state.expeience<<endl<<manager.state.level<<endl;
       manager.cout<<weapon_shit::uplevel<<endl;
       manager.cout<<weapon_bottle::uplevel<<endl;
    }
    manager.file.close();
    qDebug()<<"you win the level 1!";

}
void game::game_lose(){
   timer->stop();
   qDebug()<<"you lose the game, Loser!";
}
void game::add_buff(int types){
    if(types==1){
       buff_num[0]++;
       emit use_buff();
       buff_string[0]=QString::number(buff_num[0]);
       buff_numbers[0]->setPlainText(buff_string[0]);
    }
    else if(types==2){
      buff_num[1]++;
      emit use_buff();
      buff_string[1]=QString::number(buff_num[1]);
      buff_numbers[1]->setPlainText(buff_string[1]);
    }
    else if(types==3){
      buff_num[2]++;
      emit use_buff();
      buff_string[2]=QString::number(buff_num[2]);
      buff_numbers[2]->setPlainText(buff_string[2]);
    }
}
void game::send_buff(){
    for(Weapon*weapon:weapons){
        weapon->ice_buff_num=buff_num[0];
        weapon->kill_buff_num=buff_num[1];
        weapon->violent_buff_num=buff_num[2];
    }
}
double game::rotateangle(ennemy *enemy, Weapon *weapon){
    QPointF pos1=enemy->pos();
    QPointF pos2=weapon->pos();
    QPointF vector=pos2-pos1;
    double angleRad = std::atan2(vector.y(), vector.x());
    double angleDeg = angleRad * (180.0 / M_PI); // 将弧度转换为度数
    return angleDeg;
}
double game::distance(ennemy *enemy, Weapon *weapon){
        QPointF pos1 = enemy->pos();
        QPointF pos2 = weapon->pos();

        // 使用欧几里得距离公式计算距离
        double dx = pos1.x() - pos2.x();
        double dy = pos1.y() - pos2.y();
        double distance = std::sqrt(dx * dx + dy * dy);

        return distance;
}
bool game::collide(ennemy*enemy,Weapon*weapon){
    if(enemy->pos().rx()==weapon->pos().rx()&&enemy->pos().ry()+80>=weapon->pos().ry()) return true;
    if(enemy->pos().rx()==weapon->pos().rx()&&enemy->pos().ry()-80<=weapon->pos().ry()) return true;
    if(enemy->pos().ry()==weapon->pos().ry()&&enemy->pos().rx()-80<=weapon->pos().rx()) return true;
    return false;

}
void game::enemy_oversee(){
    for(int i=0;i<monsters.size();i++){
        monsters[i]->canmove=true;
        for(int j=0;j<weapons.size();j++){
            if(collide(monsters[i],weapons[j])&&weapons[j]->types==1){
                monsters[i]->canmove=false;
                //if(!monsters[i]->flash) monsters[i]->canmove=false;
                weapons[j]->hp-=monsters[i]->damage;
                //monsters[i]->hp-=weapons[j]->damage;
                break;
            }
        }
    }
    for(int i=0;i<weapons.size();i++){
        if(weapons[i]->types==0||weapons[i]->types==1){
            if(monsters.size()>0){
                int min_index=0;
                double min_distance=distance(monsters[0],weapons[i]);
                for(int j=1;j<monsters.size();j++){
                    double temp=distance(monsters[j],weapons[i]);
                   if(temp<min_distance){
                       min_distance=temp;
                       min_index=j;
                   }
                }
                if(min_distance>weapons[i]->attack_range) {
                    weapons[i]->attack=false;
                    weapons[i]->rotate=0;
                    weapons[i]->setRotation(0);
                    continue;
                }
                weapons[i]->attack=true;
                weapons[i]->rotate=rotateangle(monsters[min_index],weapons[i])+180;
                if(weapons[i]->types==0)weapons[i]->setRotation(rotateangle(monsters[min_index],weapons[i])+180);

            }
            else{
                weapons[i]->rotate=0;
                weapons[i]->setRotation(0);
            }
        }
    }
}
void game::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        for(int i=0;i<cards.size();i++){
             QPointF pos1=cards[i]->mapFromScene(event->pos());
          if(cards[i]->contains(pos1)&&cards[i]->canbuycard(game_coins)){
              QString tep= cards[i]->getname();
              if(tep=="bottle"){
                now_weapon=new weapon_bottle;
                scene->addItem(now_weapon);
              }
              else if(tep=="shit"){
                  now_weapon=new weapon_shit;
                  scene->addItem(now_weapon);
              }

          }
      }
    }
    QGraphicsView::mousePressEvent(event);
}
void game::mouseMoveEvent(QMouseEvent *event){
     //QGraphicsView::mousePressEvent(event);
    if(now_weapon){
        now_weapon->setPos(event->pos());
    }
     QGraphicsView::mouseMoveEvent(event);
}
void game::mouseReleaseEvent(QMouseEvent *event){
     if(event->button()==Qt::LeftButton){
         if(now_weapon){
         for(int i=0;i<m->map.size();i++){
             for(int j=0;j<m->map[0].size();j++){
                 QPointF p=m->map[i][j]->mapFromScene(event->pos());
                 if(m->map[i][j]->contains(p)&&!m->map[i][j]->isplanted&&now_weapon->types==m->map[i][j]->types){
                     weapons.push_back(now_weapon);
                     now_weapon->setPos(m->map[i][j]->pos());
                     m->map[i][j]->isplanted=true;
                     now_weapon->planted=true;
                     now_weapon->p={i,j};
                     game_coins-=now_weapon->price;
                     game_coin="金币数量：%1";
                     game_coin=game_coin.arg(game_coins);
                     display_coin->setPlainText(game_coin);
                     now_weapon->window=this;
                     connect(now_weapon,&Weapon::use_ice,[this](){
                         buff_num[0]--;
                         emit use_buff();
                         buff_string[0]=QString::number(buff_num[0]);
                         buff_numbers[0]->setPlainText(buff_string[0]);
                     });
                     connect(now_weapon,&Weapon::use_kill,[this](){
                         buff_num[1]--;
                         emit use_buff();
                         buff_string[1]=QString::number(buff_num[1]);
                         buff_numbers[1]->setPlainText(buff_string[1]);
                     });
                     connect(now_weapon,&Weapon::use_violent,[this](){
                         buff_num[2]--;
                         emit use_buff();
                         buff_string[2]=QString::number(buff_num[2]);
                         buff_numbers[2]->setPlainText(buff_string[2]);
                     });
                     connect(now_weapon,&Weapon::weapondelete,this,&game::DeleteWeapon);
                     connect(now_weapon,&Weapon::weapondead,this,&game::DeleteDeadWeapon);
                     now_weapon=nullptr;
                     return;
                 }
             }
         }
         scene->removeItem(now_weapon);
         delete now_weapon;
         now_weapon=nullptr;
         }

     }
     QGraphicsView::mouseReleaseEvent(event);
}
void game::create_new_bullet(Weapon *weapon){
    bullet*newbullet=nullptr;
    if(weapon->bullet_type==1){
       if(!weapon->ice_bullet) newbullet=new bullet(weapon->rotate,1,weapon->pos(),weapon->damage);
       else     newbullet=new bullet(weapon->rotate,2,weapon->pos(),weapon->damage);
    }
    else if(weapon->bullet_type==2){
        newbullet=new bullet(weapon->rotate,3,weapon->pos(),weapon->damage);
    }
    scene->addItem(newbullet);
    weapon->bullets.push_back(newbullet);
    connect(newbullet,&bullet::over_map,[](bullet*bullet)mutable{
        //weapon->bullets.removeOne(bullet);
        bullet->deleteLater();
    });
}
void game::dealcollide(){
        for (int i = 0; i < weapons.size(); ++i) {
            for (int j = weapons[i]->bullets.size() - 1; j >= 0; --j) {
                bool bulletCollided = false;
                QRectF bulletRect = weapons[i]->bullets[j]->boundingRect().translated(weapons[i]->bullets[j]->pos());

                // Check if the bullet is out of the scene
                QRectF sceneRect = this->sceneRect();
                if (!sceneRect.intersects(bulletRect)) {
                    emit weapons[i]->bullets[j]->over_map(weapons[i]->bullets[j]);
                    weapons[i]->bullets.removeAt(j); // Remove the bullet from the vector
                    continue;
                }
                // Check for collision with monsters
                for (int k = 0; k < monsters.size(); ++k) {
                    QRectF enemyRect = monsters[k]->boundingRect().translated(monsters[k]->pos());
                    if (enemyRect.intersects(bulletRect)) {
                        monsters[k]->hp -= weapons[i]->bullets[j]->damage;
                        if(weapons[i]->continued_blood_deduction==true){
                            monsters[k]->timecnt=1;
                        }
                        if(weapons[i]->bullets[j]->types==2){
                            monsters[k]->movespeed=1;
                            monsters[k]->iced=true;
                        }
                        bulletCollided = true;
                        break; // Exit the loop after the first collision
                    }
                }

                if (bulletCollided) {
                    emit weapons[i]->bullets[j]->over_map(weapons[i]->bullets[j]);
                    weapons[i]->bullets.removeAt(j); // Remove the bullet from the vector
                }
            }
        }
}
void game::DeleteWeapon(Weapon*weapon){
    scene->removeItem(weapon);
    weapons.removeOne(weapon);
    for(int i=0;i<weapon->bullets.size();i++){
        weapon->bullets[i]->deleteLater();
    }
    weapon->bullets.clear();
    weapon->deleteLater();
}
void game::DeleteDeadWeapon(Weapon *weapon){
    if(!weapon->weapon_slots.empty()){
        for(int i=0;i<weapon->weapon_slots.size();i++){
            scene->removeItem(weapon->weapon_slots[i]);
            delete weapon->weapon_slots[i];
        }
       weapon->weapon_slots.clear();
    }
    for(int i=0;i<weapon->bullets.size();i++){
        weapon->bullets[i]->deleteLater();
    }
    weapon->bullets.clear();
    weapons.removeOne(weapon);
   m->map[weapon->p.i][weapon->p.j]->isplanted=false;
  if(weapon->types==1){
      if(!monsters.empty()){
          monsters[0]->add_buff(weapon->drop_buff());
      }
  }
   weapon->deleteLater();
}
void game::first_wave(){
   timecnt=0;
   now_monsters_in_wave[0]=0;
    connect(timer,&QTimer::timeout,[&]()mutable{
     if((timecnt%5==0)&&(now_monsters_in_wave[0]<5)){
           create_new_enemy(1,level,1);
           now_monsters_in_wave[0]++;
    }
     timecnt++;
    });
}
void game::second_wave(){
    timecnt=0;
    now_monsters_in_wave[1]=0;
     connect(timer,&QTimer::timeout,[&]()mutable{
         if(timecnt%5==0){
      if((now_monsters_in_wave[1]<5)){
            create_new_enemy(1,level,2);
            now_monsters_in_wave[1]++;
     }
      else if(now_monsters_in_wave[1]<10){
          create_new_enemy(2,level,2);
          now_monsters_in_wave[1]++;
      }

     }
         timecnt++;
     });
}
void game::third_wave(){
    timecnt=0;
    now_monsters_in_wave[2]=0;
     connect(timer,&QTimer::timeout,[&]()mutable{
         if(timecnt%5==0){
      if((now_monsters_in_wave[2]<5)){
            create_new_enemy(1,level,3);
            now_monsters_in_wave[2]++;
     }
      else if(now_monsters_in_wave[2]<10){
          create_new_enemy(2,level,3);
          now_monsters_in_wave[2]++;
      }
      else if(now_monsters_in_wave[2]<15){
          create_new_enemy(3,level,3);
          now_monsters_in_wave[2]++;
      }

     }
         timecnt++;
     });
}
void game::fourth_wave(){
    timecnt=0;
    now_monsters_in_wave[3]=0;
     connect(timer,&QTimer::timeout,[&]()mutable{
         if(timecnt%5==0){
      if((now_monsters_in_wave[3]<5)){
            create_new_enemy(1,level,4);
            now_monsters_in_wave[3]++;
     }
      else if(now_monsters_in_wave[3]<10){
          create_new_enemy(2,level,4);
          now_monsters_in_wave[3]++;
      }
      else if(now_monsters_in_wave[3]<15){
          create_new_enemy(3,level,4);
          now_monsters_in_wave[3]++;
      }
      else if(now_monsters_in_wave[3]<20){
          create_new_enemy(1,level,4);
          now_monsters_in_wave[3]++;
      }
      else if(now_monsters_in_wave[3]<25){
          create_new_enemy(2,level,4);
          now_monsters_in_wave[3]++;
      }

     }
         timecnt++;
      if(monsters.size()==0&&now_monsters_in_wave[3]==25&&level==1) emit succeed();
     });
}
void game::fifth_wave(){
    timecnt=0;
    now_monsters_in_wave[4]=0;
     connect(timer,&QTimer::timeout,[&]()mutable{
         if(timecnt%5==0){
      if((now_monsters_in_wave[4]<5)){
            create_new_enemy(1,level,5);
            now_monsters_in_wave[4]++;
     }
      else if(now_monsters_in_wave[4]<10){
          create_new_enemy(2,level,5);
          now_monsters_in_wave[4]++;
      }
      else if(now_monsters_in_wave[4]<15){
          create_new_enemy(3,level,5);
          now_monsters_in_wave[4]++;
      }
      else if(now_monsters_in_wave[4]<20){
          create_new_enemy(1,level,5);
          now_monsters_in_wave[4]++;
      }
      else if(now_monsters_in_wave[4]<25){
          create_new_enemy(2,level,5);
          now_monsters_in_wave[4]++;
      }

     }
         timecnt++;
});
}

void game::sixth_wave(){
    timecnt=0;
    now_monsters_in_wave[5]=0;
     connect(timer,&QTimer::timeout,[&]()mutable{
         if(timecnt%5==0){
      if((now_monsters_in_wave[5]<8)){
            create_new_enemy(1,level,6);
            now_monsters_in_wave[5]++;
     }
      else if(now_monsters_in_wave[5]<15){
          create_new_enemy(2,level,6);
          now_monsters_in_wave[5]++;
      }
      else if(now_monsters_in_wave[5]<25){
          create_new_enemy(3,level,6);
          now_monsters_in_wave[5]++;
      }
      else if(now_monsters_in_wave[5]<35){
          create_new_enemy(1,level,6);
          now_monsters_in_wave[5]++;
      }
      else if(now_monsters_in_wave[5]<45){
          create_new_enemy(2,level,6);
          now_monsters_in_wave[5]++;
      }

     }
         timecnt++;
});
}
void game::seventh_wave(){
    timecnt=0;
    now_monsters_in_wave[6]=0;
     connect(timer,&QTimer::timeout,[&]()mutable{
         if(timecnt%5==0){
      if((now_monsters_in_wave[6]<5)){
            create_new_enemy(1,level,7);
            now_monsters_in_wave[6]++;
     }
      else if(now_monsters_in_wave[6]<10){
          create_new_enemy(2,level,7);
          now_monsters_in_wave[6]++;
      }
      else if(now_monsters_in_wave[6]<15){
          create_new_enemy(3,level,7);
          now_monsters_in_wave[6]++;
      }
      else if(now_monsters_in_wave[6]<20){
          create_new_enemy(1,level,7);
          now_monsters_in_wave[6]++;
      }
      else if(now_monsters_in_wave[6]<25){
          create_new_enemy(2,level,7);
          now_monsters_in_wave[6]++;
      }
     }
         timecnt++;
});
}
void game::eighth_wave(){
    timecnt=0;
    now_monsters_in_wave[7]=0;
     connect(timer,&QTimer::timeout,[&]()mutable{
         if(timecnt%5==0){
      if((now_monsters_in_wave[7]<5)){
            create_new_enemy(1,level,8);
            now_monsters_in_wave[7]++;
     }
      else if(now_monsters_in_wave[7]<10){
          create_new_enemy(2,level,8);
          now_monsters_in_wave[7]++;
      }
      else if(now_monsters_in_wave[7]<15){
          create_new_enemy(3,level,8);
          now_monsters_in_wave[7]++;
      }
      else if(now_monsters_in_wave[7]<20){
          create_new_enemy(1,level,8);
          now_monsters_in_wave[7]++;
      }
      else if(now_monsters_in_wave[7]<25){
          create_new_enemy(2,level,8);
          now_monsters_in_wave[7]++;
      }

     }
         timecnt++;
});
}
void game::ninth_wave(){
    timecnt=0;
    now_monsters_in_wave[8]=0;
     connect(timer,&QTimer::timeout,[&]()mutable{
         if(timecnt%5==0){
      if((now_monsters_in_wave[8]<5)){
            create_new_enemy(1,level,9);
            now_monsters_in_wave[8]++;
     }
      else if(now_monsters_in_wave[8]<10){
          create_new_enemy(2,level,9);
          now_monsters_in_wave[8]++;
      }
      else if(now_monsters_in_wave[8]<15){
          create_new_enemy(3,level,9);
          now_monsters_in_wave[8]++;
      }
      else if(now_monsters_in_wave[8]<30){
          create_new_enemy(1,level,9);
          now_monsters_in_wave[8]++;
      }
      else if(now_monsters_in_wave[8]<45){
          create_new_enemy(2,level,9);
          now_monsters_in_wave[8]++;
      }

     }
         timecnt++;});
}
void game::tenth_wave(){
    timecnt=0;
    now_monsters_in_wave[9]=0;
     connect(timer,&QTimer::timeout,[&]()mutable{
         if(timecnt%5==0){
      if((now_monsters_in_wave[9]<10)){
            create_new_enemy(1,level,10);
            now_monsters_in_wave[9]++;
     }
      else if(now_monsters_in_wave[9]<20){
          create_new_enemy(2,level,10);
          now_monsters_in_wave[9]++;
      }
      else if(now_monsters_in_wave[9]<30){
          create_new_enemy(3,level,10);
          now_monsters_in_wave[9]++;
      }
      else if(now_monsters_in_wave[9]<40){
          create_new_enemy(1,level,10);
          now_monsters_in_wave[9]++;
      }
      else if(now_monsters_in_wave[9]<50){
          create_new_enemy(2,level,10);
          now_monsters_in_wave[9]++;
      }
     else if(now_monsters_in_wave[9]==50){
          boss();
      }
     }
         timecnt++;});
}
void game::boss(){

}
void game::create_new_enemy(int types,int level,int wave){
    ennemy*newEnemy=nullptr;
   if(types==1){
      newEnemy = new enemy1(level);
      newEnemy->hp+=10*wave;
      newEnemy->damage+=2*wave;
       monsters.push_back(newEnemy);
       scene->addItem(newEnemy);
   }
   else if(types==2){
       newEnemy = new enemy2(level);
       newEnemy->hp+=10*wave;
       newEnemy->damage+=2*wave;
        monsters.push_back(newEnemy);
        scene->addItem(newEnemy);
   }
   else if(types==3){
       newEnemy = new enemy3(level);
       newEnemy->hp+=10*wave;
       newEnemy->damage+=2*wave;
        monsters.push_back(newEnemy);
        scene->addItem(newEnemy);
   }
    // 接下来，我们连接ennemy对象的isdead信号到一个lambda槽函数
    connect(newEnemy, &ennemy::isdead,[this](ennemy*enemy)mutable {
        // 这个lambda函数会在某个ennemy对象发出isdead信号时被调用
        game_coins+=enemy->drop_money;
        manager.addexpeience(1);
        add_buff(enemy->drop_buff());
        game_coin="金币数量：%1";
        game_coin=game_coin.arg(game_coins);
        display_coin->setPlainText(game_coin);
        monsters.removeOne(enemy);
        enemy->deleteLater();
    });
    connect(newEnemy,&ennemy::over_map,[this](ennemy*enemy)mutable{
        monsters.removeOne(enemy);
        wholeblood--;
        game_life="血量：%1";
        game_life=game_life.arg(wholeblood);
        display_life->setPlainText(game_life);
        enemy->deleteLater();
    });
}
void game::saveAll(){
    manager.file.setFileName("D:/111.txt");
    manager.cout.setDevice(&manager.file);
    if(!manager.file.exists()){
        bool res2 = manager.file.open(QIODevice::WriteOnly | QIODevice::Text );
         qDebug() << "新建文件是否成功" << res2;
    }
    if(manager.file.open(QIODevice::WriteOnly | QIODevice::Text)){
        for(int i=0;i<monsters.size();i++){
            manager.cout<<(*monsters[i]);
        }
        for(int i=0;i<weapons.size();i++){
            manager.cout<<(*weapons[i]);
        }
        for(int i=0;i<weapons.size();i++){
            for(int j=0;j<weapons[i]->bullets.size();j++){
                manager.cout<<(*weapons[i]->bullets[j]);
            }
        }
        for(int i=0;i<m->map.size();i++){
            for(int j=0;j<m->map[0].size();j++){
                manager.cout<<(m->map[i][j]->isplanted)<<" ";
            }
            manager.cout<<endl;
        }
        manager.cout<<timecount<<" "<<game_coins<<" "<<wholeblood<<" "<<numof_wave<<endl;
    }
    manager.file.close();

    manager.file.setFileName(":/files/map/game_state.dat.txt");
    manager.cout.setDevice(&manager.file);
    if(manager.file.open(QIODevice::WriteOnly | QIODevice::Text)){
       manager.cout<<manager.state;
       manager.cout<<weapon_shit::uplevel<<endl;
       manager.cout<<weapon_bottle::uplevel<<endl;
    }
    manager.file.close();
    emit save();
}
void game::loadAll(){
   QVector<QVector<QString>>temp= manager.LoadAllFromFile();
   int now=0;
   for(int i=0;i<temp.size();i++){
       if(temp[i][0]=="ennemy"){
           ennemy*newenemy;
          int enemytype=temp[i][3].toInt();
          switch (enemytype) {
          case 1: newenemy=new enemy1(manager.state.level);break;
          case 2: newenemy=new enemy2(manager.state.level);break;
          case 3: newenemy=new enemy3(manager.state.level);break;
          }
          newenemy->hp=temp[i][1].toInt();
          newenemy->damage=temp[i][2].toInt();
          newenemy->setPos(temp[i][4].toInt(),temp[i][5].toInt());
          newenemy->movespeed=temp[i][6].toInt();
          newenemy->nowposition=temp[i][7].toInt();
          scene->addItem(newenemy);
          monsters.push_back(newenemy);
          connect(newenemy, &ennemy::isdead,[this](ennemy*enemy)mutable {
              // 这个lambda函数会在某个ennemy对象发出isdead信号时被调用
              game_coins+=enemy->drop_money;
              manager.addexpeience(1);
              add_buff(enemy->drop_buff());
              game_coin="金币数量：%1";
              game_coin=game_coin.arg(game_coins);
              display_coin->setPlainText(game_coin);
              monsters.removeOne(enemy);
              enemy->deleteLater();

          });
          connect(newenemy,&ennemy::over_map,[this](ennemy*enemy)mutable{
              monsters.removeOne(enemy);
              wholeblood--;
              game_life="血量：%1";
              game_life=game_life.arg(wholeblood);
              display_life->setPlainText(game_life);
              enemy->deleteLater();
          });
       }
       else if(temp[i][0]=="weapon"){
           Weapon*newweapon;
           int weapontype=temp[i][4].toInt();
           switch (weapontype) {
           case 0:newweapon=new weapon_bottle;break;
           case 1:newweapon=new weapon_shit;break;
           }
           newweapon->planted=true;
           newweapon->hp=temp[i][1].toInt();
           newweapon->damage=temp[i][2].toInt();
           newweapon->damage_speed=temp[i][3].toInt();
           newweapon->p.i=temp[i][7].toInt();
           newweapon->p.j=temp[i][8].toInt();
           newweapon->setPos(temp[i][5].toInt(),temp[i][6].toInt());
           scene->addItem(newweapon);
           weapons.push_back(newweapon);
           connect(newweapon,&Weapon::use_ice,[this](){
               buff_num[0]--;
               emit use_buff();
               buff_string[0]=QString::number(buff_num[0]);
               buff_numbers[0]->setPlainText(buff_string[0]);
           });
           connect(newweapon,&Weapon::use_kill,[this](){
               buff_num[1]--;
               emit use_buff();
               buff_string[1]=QString::number(buff_num[1]);
               buff_numbers[1]->setPlainText(buff_string[1]);
           });
           connect(newweapon,&Weapon::use_violent,[this](){
               buff_num[2]--;
               emit use_buff();
               buff_string[2]=QString::number(buff_num[2]);
               buff_numbers[2]->setPlainText(buff_string[2]);
           });
           connect(now_weapon,&Weapon::weapondelete,this,&game::DeleteWeapon);
           connect(now_weapon,&Weapon::weapondead,this,&game::DeleteDeadWeapon);
       }
       else if(temp[i][0]=="bullet"){
           bullet*newbullet;
           newbullet=new bullet(temp[i][5].toInt(),temp[i][4].toInt(),QPointF(temp[i][2].toInt(),temp[i][3].toInt()),temp[i][1].toInt());
           weapons[0]->bullets.push_back(newbullet);
           scene->addItem(newbullet);
           connect(newbullet,&bullet::over_map,[](bullet*bullet)mutable{
               //weapon->bullets.removeOne(bullet);
               bullet->deleteLater();
           });
       }
       else if(temp[i][0].toInt()==0||temp[i][0].toInt()==1){
           for(int j=0;j<temp[temp.size()-2].size()-1;j++){
               m->map[now][j]->isplanted=temp[i][j].toInt();
           }
           now++;
       }
       else{
           timecount=temp[i][0].toInt();
           game_coins=temp[i][1].toInt();
           wholeblood=temp[i][2].toInt();
           numof_wave=temp[i][3].toInt();
           game_coin="金币数量：%1";
           game_wave="关卡：%1/%2";
           game_life="血量：%1";
           game_wave=game_wave.arg(numof_wave).arg(wave_of_enemy);
           game_life=game_life.arg(wholeblood);
           game_coin=game_coin.arg(game_coins);
           display_wave->setPlainText(game_wave);
           display_coin->setPlainText(game_coin);
           display_life->setPlainText(game_life);

       }
   }
   timer->start();
}
game::~game()
{
    delete ui;
}
