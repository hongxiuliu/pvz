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
    game_coins=500;
    numof_wave=0;
    now_weapon=nullptr;
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
   if(level==1){
       wholeblood=10;
       m=new mapp(1);
       for(int i=0;i<m->map1.size();i++){
           for(int j=0;j<m->map1[i].size();j++){
               m->map[i][j]=new grid;
               m->map[i][j]->setPos(80*j,100+80*i);
               //qDebug()<<m->map[i][j];
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
    card*card1=new card("bottle");
    card*card2=new card("shit");
    cards.push_back(card1);
    cards.push_back(card2);
    for(int i=0;i<cards.size();i++){
       cards[i]->setPos(80*i,0);
       scene->addItem(cards[i]);
    }
    this->resize(900,800);
   }
   else if(level==2){

   }
   else if(level==3){

   }
   game_coin="金币数量：%1";
   game_wave="关卡：%1";
   game_wave=game_wave.arg(numof_wave);
   game_coin=game_coin.arg(game_coins);
   display_wave=new QGraphicsTextItem(game_wave);
   display_coin=new QGraphicsTextItem(game_coin);
   scene->addItem(display_coin);
   scene->addItem(display_wave);
   display_coin->setPos(50,730);
   display_wave->setPos(250,730);
   display_wave->setDefaultTextColor(Qt::blue);
   display_wave->setFont(QFont("Arial", 12));
   display_coin->setDefaultTextColor(Qt::blue);
   display_coin->setFont(QFont("Arial", 12));
}
void game::gameprocess(){
    timer=new QTimer(this);
    timer->setInterval(200);
    timer->start();
    connect(timer,&QTimer::timeout,[&](){
        timecount++;
    if(timecount==1){
        enemystart=true;
        //qDebug()<<level;
        numof_wave=1;
        game_wave="波数：1";
        display_wave->setPlainText(game_wave);
        first_wave();
    }
    if(timecount==100){
        second_wave();
        numof_wave=2;
        game_wave="波数：2";
        display_wave->setPlainText(game_wave);
    }
    if(timecount==200){
        third_wave();
        numof_wave=3;
        game_wave="波数：3";
        display_wave->setPlainText(game_wave);
    }
    if(timecount==450){
        fourth_wave();
        numof_wave=4;
        game_wave="波数：4";
        display_wave->setPlainText(game_wave);
    }
    if(level>=2&&timecount==600){
        fifth_wave();
        numof_wave=5;
        game_wave="波数：5";
        display_wave->setPlainText(game_wave);
    }
    if(level>=2&&timecount==750){
        sixth_wave();
        numof_wave=6;
        game_wave="波数：6";
        display_wave->setPlainText(game_wave);
    }
    if(level>=2&&timecount==900){
        seventh_wave();
        numof_wave=7;
        game_wave="波数：7";
        display_wave->setPlainText(game_wave);
    }
    if(level>=2&&timecount==1050){
        eighth_wave();
        numof_wave=8;
        game_wave="波数：8";
        display_wave->setPlainText(game_wave);
    }
    if(level>=3&&timecount==1200){
        ninth_wave();
        numof_wave=9;
        game_wave="波数：9";
        display_wave->setPlainText(game_wave);
    }
    if(level>=3&&timecount==1400){
        tenth_wave();
        numof_wave=10;
        game_wave="波数：10";
        display_wave->setPlainText(game_wave);
    }
    } );
    connect(timer,&QTimer::timeout,[&]()mutable{
       dealcollide();
       enemy_oversee();
        for(int i=0;i<monsters.size();i++){
            monsters[i]->loadpicture();
            monsters[i]->move();
        }
        for(int i=0;i<weapons.size();i++){
          weapons[i]->oversee();
        }

        for(int i=0;i<weapons.size();i++){
            if(weapons[i]->havebullets){
                weapons[i]->shootbullets();
                if(timecount%5==0&&monsters.size()>0)create_new_bullet(weapons[i]);

            }
        }
    } );

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
                weapons[j]->hp-=monsters[i]->damage;
                monsters[i]->hp-=weapons[j]->damage;
                break;
            }
        }
    }
    for(int i=0;i<weapons.size();i++){
        if(weapons[i]->types==0){
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
                weapons[i]->rotate=rotateangle(monsters[min_index],weapons[i])+180;
                weapons[i]->setRotation(rotateangle(monsters[min_index],weapons[i])+180);
            }
            else{
                weapons[i]->rotate=0;
                weapons[i]->setRotation(0);
            }
        }
    }
}
void game::mousePressEvent(QMouseEvent *event){
    QPointF scenePos = mapToScene(event->pos());
        // 获取与点击位置相关的 QGraphicsItem
    QGraphicsItem *item = scene->itemAt(scenePos, transform());
    qDebug()<<item->pos();
    qDebug()<<item;
        // 如果 item 不为空，表示鼠标点击位置有 QGraphicsItem

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
    if(now_weapon){
        now_weapon->setPos(event->pos());
    }
}
void game::mouseReleaseEvent(QMouseEvent *event){
     if(event->button()==Qt::LeftButton){
         if(now_weapon){
         for(int i=0;i<m->map.size();i++){
             for(int j=0;j<m->map[0].size();j++){
                 QPointF p=m->map[i][j]->mapFromScene(event->pos());
                 if(m->map[i][j]->contains(p)&&!m->map[i][j]->isplanted&&now_weapon->types==m->map[i][j]->types){
                     weapons.push_back(now_weapon);
                    ///qDebug()<<reinterpret_cast<quintptr>(static_cast<const void*>(now_weapon));
                     now_weapon->setPos(m->map[i][j]->pos());
                     m->map[i][j]->isplanted=true;
                     now_weapon->planted=true;
                     now_weapon->p={i,j};
                     game_coins-=now_weapon->price;
                     game_coin="金币数量：%1";
                     game_coin=game_coin.arg(game_coins);
                     display_coin->setPlainText(game_coin);
                     connect(now_weapon,&Weapon::weapondead,[this](Weapon*weapon)mutable{
                         weapons.removeOne(weapon);
                        m->map[weapon->p.i][weapon->p.j]->isplanted=false;
                        weapon->deleteLater();
                     });
                    // connect(weapons.back(),&Weapon::shoot,weapons.back(),&Weapon::shootbullets);
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
}
void game::create_new_bullet(Weapon *weapon){
    bullet*newbullet=nullptr;
    if(weapon->bullet_type==1){
        newbullet=new bullet(weapon->rotate,1,weapon->pos(),weapon->damage);

    }
    scene->addItem(newbullet);
    weapon->bullets.push_back(newbullet);
    connect(newbullet,&bullet::over_map,[weapon](bullet*bullet)mutable{
        weapon->bullets.removeOne(bullet);
        bullet->deleteLater();
    });
}
void game::dealcollide(){
    QVector<int> temp;//临时vector，确定要被删去的子弹
    for(int i=0;i<weapons.size();i++){
        for(int j=weapons[i]->bullets.size()-1;j>=0;j--){
            bool add=true;
        QRectF bulletBoundingRect = weapons[i]->bullets[j]->boundingRect().translated(weapons[i]->bullets[j]->pos());
          QRectF viewRect = this->sceneRect();
        // 检查子弹的边界矩形是否与视图的边界有交集
        if (!viewRect.intersects(bulletBoundingRect)) {
            // 子弹完全超出了视图的边界
            // 处理超出边界的情况
            weapons[i]->bullets[j]->emit over_map(weapons[i]->bullets[j]);
        }
        for(int k=0;k<monsters.size();k++){
            QRectF enemyRect=monsters[k]->boundingRect().translated(monsters[k]->pos());//子弹和敌人碰撞
            if(enemyRect.intersects(bulletBoundingRect)){
                 monsters[k]->hp-=weapons[i]->bullets[j]->damage;
                 for(int p=0;p<temp.size();p++){//确保每个要删去子弹只出现一次
                     if(temp[p]==j) add=false;
                 }
                 if(add) temp.push_back(j);//防止因为一个子弹和多个敌人碰撞而导致越界
            }
        }
       }
        for(int p=0;p<temp.size();p++){
            weapons[i]->bullets[temp[p]]->emit over_map( weapons[i]->bullets[temp[p]]);//删去子弹
        }
        temp.clear();
    }

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
     });
}
void game::fifth_wave(){

}
void game::sixth_wave(){

}
void game::seventh_wave(){

}
void game::eighth_wave(){

}
void game::ninth_wave(){

}
void game::tenth_wave(){

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
        game_coin="金币数量：%1";
        game_coin=game_coin.arg(game_coins);
        display_coin->setPlainText(game_coin);
        monsters.removeOne(enemy);
        enemy->deleteLater();

    });
    connect(newEnemy,&ennemy::over_map,[this](ennemy*enemy)mutable{
        monsters.removeOne(enemy);
        enemy->deleteLater();
    });
}
game::~game()
{
    delete ui;
}
