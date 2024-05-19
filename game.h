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
#include"short_range_weapon.h"
#include"long_range_weapon.h"
#include"weapon_bottle.h"
#include"weapon_shit.h"
#include<QGraphicsView>
#include<QGraphicsTextItem>
#include<QVector>
#include<memory>
#include<cmath>
#include<algorithm>
namespace Ui {
class game;
}

class game :public QGraphicsView
{
    Q_OBJECT

public:
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
    QString game_coin;
    QString game_wave;
    QGraphicsTextItem* display_coin;
    QGraphicsTextItem* display_wave;
    QVector<card*> cards;
    Weapon*now_weapon;
    QVector<Weapon*>weapons;
    QVector<ennemy*> monsters;

    explicit game();
    ~game();
    void gameinit(int i);
    void gameprocess();
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
    void gameend();

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

private:
    Ui::game *ui;
};

#endif // GAME_H
