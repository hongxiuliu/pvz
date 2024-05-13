#include "game.h"
#include "ui_game.h"
#include<QMovie>
game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 900, 800);
    view=new newview(this);
    view->setScene(scene);
    view->setStyleSheet("background:transparent");
    enemyisdead=0;
    enemyoutmap=0;
}
void game::gameinit(int level){
    timecount=0;
    enemystart=false;
    switch (level) {
    case 1:wave_of_enemy=4;break;
    case 2:wave_of_enemy=8;break;
    case 3:wave_of_enemy=10;break;
    }
   mapp*m;
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
               scene->addItem(m->map[i][j]);
               if(m->map1[i][j]=='0'){
               m->map[i][j]->setPixmap(p2);
               }
               else{
                   m->map[i][j]->setPixmap(p1);
               }

           }
       }
    card*card1=new card("bottle");
    card1->setPos(0,0);
    view->cards.push_back(card1);

    for(int i=0;i<view->cards.size();i++){
        scene->addItem(view->cards[i]);
    }
    this->resize(900,800);
   }
   else if(level==2){

   }
   else if(level==3){

   }
}
void game::gameprocess(){
    timer=new QTimer(this);
    timer->setInterval(200);
    timer->start();
    connect(timer,&QTimer::timeout,[&](){
        timecount++;
    if(timecount==1){
        enemystart=true;
        qDebug()<<level;
        first_wave();
    }
    if(timecount==100){
        second_wave();
    }
    if(timecount==200){
        third_wave();
    }
    if(timecount==450){
        fourth_wave();
    }
    if(level>=2&&timecount==600){
        fifth_wave();
    }
    if(level>=2&&timecount==750){
        sixth_wave();
    }
    if(level>=2&&timecount==900){
        seventh_wave();
    }
    if(level>=2&&timecount==1050){
        eighth_wave();
    }
    if(level>=3&&timecount==1200){
        ninth_wave();
    }
    if(level>=3&&timecount==1400){
        tenth_wave();
    }
    } );
    connect(timer,&QTimer::timeout,[&]()mutable{
        //qDebug()<<monsters.size();
        for(int i=0;i<monsters.size();i++){
            monsters[i]->move();
            monsters[i]->loadpicture();
        }
        while(enemyisdead){
            remove_dead_enemy();
            enemyisdead--;
        }
        while(enemyoutmap){
            remove_out_of_map_enemy();
            enemyoutmap--;
        }
    } );

}
void game::remove_dead_enemy(){
    auto it = std::find_if(monsters.begin(), monsters.end(),
                           []( ennemy* ptr) {
                               return ptr->enemyisdead(); // 检查敌人是否已死
                           });

    // 检查我们是否找到了一个已死的敌人
    if (it != monsters.end()) {
        delete *it; // 删除敌人并重置unique_ptr
        monsters.erase(it); // 从vector中删除unique_ptr
    }
}
void game::remove_out_of_map_enemy(){
    auto it = std::find_if(monsters.begin(), monsters.end(),
                           []( ennemy* ptr) {
                               return ptr->enemy_out_of_map(); // 检查敌人是否已死
                           });

    if (it != monsters.end()) {
        delete *it;
        monsters.erase(it);
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
   if(types==1){
      ennemy* newEnemy = new enemy1(level);
      newEnemy->hp+=10*wave;
      newEnemy->damage+=2*wave;
       monsters.push_back(newEnemy);
       scene->addItem(newEnemy);
   }
   else if(types==2){
       ennemy* newEnemy = new enemy2(level);
       newEnemy->hp+=10*wave;
       newEnemy->damage+=2*wave;
        monsters.push_back(newEnemy);
        scene->addItem(newEnemy);
   }
   else if(types==3){
       ennemy* newEnemy = new enemy3(level);
       newEnemy->hp+=10*wave;
       newEnemy->damage+=2*wave;
        monsters.push_back(newEnemy);
        scene->addItem(newEnemy);
   }
    // 接下来，我们连接ennemy对象的isdead信号到一个lambda槽函数
    connect(monsters.back(), &ennemy::isdead, this, [&]()mutable {
        // 这个lambda函数会在某个ennemy对象发出isdead信号时被调用
        enemyisdead++;

    });
    connect(monsters.back(),&ennemy::over_map,this,[&]()mutable{
        enemyoutmap++;
    });
}
game::~game()
{
    delete ui;
}
