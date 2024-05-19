#ifndef WEAPON_H
#define WEAPON_H

#include <QWidget>
#include<QObject>
#include<QGraphicsItem>
#include"bullet.h"
#include<QVector>
#include<QPixmap>
#include<QPainter>
#include<QGraphicsSceneMouseEvent>
struct position{
    int i;
    int j;
};

class Weapon:public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    int hp;
    int damage;
    int price;
    QPixmap pix;
    struct position p;
    QVector<bullet*> bullets;
    bool planted;
    int types;
    int bullet_type;
    bool havebullets;
    double rotate;
    Weapon();
    virtual Weapon* copyweapon();
    virtual void loadpicture();
    bool isplanted();
    bool isdead();
    virtual void shootbullets();
    void oversee();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
//    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
signals:
    void weapondead(Weapon*weapon);
    void shoot();
};
class card :public QGraphicsItem
{
    //Q_OBJECT
public:
    explicit card(QString n);
    void setcoins(int coins);
    bool canbuycard(int coins);
    QString getname();
    QString name;
    int needcoins;
    QPixmap pix;


    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
//signals:

};
#endif // WEAPON_H
