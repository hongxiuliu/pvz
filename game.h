#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include"mapp.h"
#include"ennemy.h"
#include"enemy1.h"
#include"enemy2.h"
#include"enemy3.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include"weapon_bottle.h"
#include"weapon_shit.h"
#include<QGraphicsView>
#include<QGraphicsTextItem>
#include<QVector>
#include<memory>
#include<cmath>
#include<gamestatemanager.h>
#include<algorithm>
namespace Ui {
class game;
}

class game :public QGraphicsView
{
    Q_OBJECT
private:
    QString game_coin;
    QString game_wave;
    QString game_life;
    QGraphicsTextItem* display_coin;
    QGraphicsTextItem* display_wave;
    QGraphicsTextItem* display_life;
    QVector<card*> cards;
    Weapon*now_weapon;
    QVector<Weapon*>weapons;
    QVector<ennemy*> monsters;
    QVector<QGraphicsTextItem*> buff_numbers;
    int buff_num[3];
    QString buff_string[3];
    void Delete_Weapon(int i,int j);
    void first_wave();
    void second_wave();
    void third_wave();
    void fourth_wave();
    void fifth_wave();
    void sixth_wave();
    void seventh_wave();
    void eighth_wave();
    void ninth_wave();
    void tenth_wave();
    void game_lose();
    void game_succeed();
    void boss();
    void DeleteWeapon(Weapon*weapon);
    void DeleteDeadWeapon(Weapon*weapon);
public:
    Gamemanager manager;
    int level;
    int timecnt;
    int numof_wave;
    int now_monsters_in_wave[10];
    int wholeblood;
    int wave_of_enemy;
    mapp*m;
    qlonglong timecount;
    QGraphicsScene*scene;
    QTimer* timer;
    bool enemystart;
    int game_coins;
    explicit game();
    ~game();
    void gameinit(int i);
    void gameprocess();
    void create_new_enemy(int types,int level,int wave);
    void create_new_bullet(Weapon*weapon);
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent*event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void enemy_oversee();
    void dealcollide();
    bool collide(ennemy*enemy,Weapon*weapon);
    double rotateangle(ennemy*enemy,Weapon*weapon);
    double distance(ennemy*enemy,Weapon*weapon);
    void add_buff(int types);
    void send_buff();
    void saveAll();
    void loadAll();
private:
    Ui::game *ui;
signals:
    void succeed();
    void lose();
    void use_buff();
    void save();
};

#endif // GAME_H
