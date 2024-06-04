#ifndef WEAPON_H
#define WEAPON_H

#include <QWidget>
#include<QObject>
#include<QGraphicsItem>
#include"bullet.h"
#include<QVector>
#include<QPixmap>
#include<QPainter>
#include"buff.h"
#include<QTextStream>
struct position{
    int i;
    int j;
};

class Weapon:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:
     QVector<buff> weapon_buffs;
public:
    int hp;
    struct position p;
    int price;
    int damage;
    int damage_speed;
    QWidget* window;
    QPixmap pix;
    QVector<bullet*> bullets;
    bool planted;
    bool attack;
    int types;
    int bullet_type;
    bool havebullets;
    double rotate;
    double attack_range;
    bool ice_bullet;
    bool state_violent;
    bool state_kill;
    bool continued_blood_deduction;
    int ice_buff_num;
    int kill_buff_num;
    int violent_buff_num;
    QVector<card_slot*> weapon_slots;
    Weapon();
    virtual void loadpicture();
    bool isplanted();
    bool isdead();
    virtual void shootbullets();
    void oversee();
    void add_buff(QString s);
    int drop_buff();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    friend QTextStream& operator<<(QTextStream& out, Weapon& myStruct) {
            out<<"weapon"<<" "<<myStruct.hp<<" "<<myStruct.damage<<" "<<myStruct.damage_speed<<" ";
            out<<myStruct.types<<" "<<myStruct.pos().x()<<" "<<myStruct.pos().y()<<" ";
            out<<myStruct.p.i<<" "<< myStruct.p.j;
            out<<endl;
            return out;
        }
signals:
    void weapondead(Weapon*weapon);
    void weapondelete(Weapon*weapon);
    void shoot();
    void use_ice();
    void use_violent();
    void use_kill();
};
class card :public QGraphicsItem
{
    //Q_OBJECT
private:
    QPixmap pix;
public:
    explicit card(QString n);
    void setcoins(int coins);
    bool canbuycard(int coins);
    QString getname();
    QString name;
    int needcoins;
    int numbers;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
//signals:

};
#endif // WEAPON_H
