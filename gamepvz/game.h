#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include"mapp.h"
#include"newview.h"
#include"ennemy.h"
#include"enemy1.h"
#include"enemy2.h"
#include"enemy3.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QGraphicsItem>
//#include<QGraphicsView>
#include<QVector>
#include<memory>
#include<algorithm>
namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    int level;
    int timecnt;
    int now_monsters_in_wave[10];
    int wholeblood;
    int enemyoutmap;
    int enemyisdead;
    int wave_of_enemy;
    qlonglong timecount;
    QGraphicsScene*scene;
    newview*view;
    QTimer* timer;
    bool enemystart;
    //QVector<card*> cards;
    //Weapon*now_weapon;
    QVector<ennemy*> monsters;

    explicit game(QWidget *parent = nullptr);
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
    void remove_dead_enemy();
    void remove_out_of_map_enemy();
private:
    Ui::game *ui;
};

#endif // GAME_H
