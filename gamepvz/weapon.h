#ifndef WEAPON_H
#define WEAPON_H

#include <QWidget>
#include<QGraphicsItem>
#include"bullet.h"
#include<QVector>
#include<QPixmap>
#include<QPainter>
#include<QGraphicsSceneMouseEvent>
class Weapon:public QGraphicsItem
{
public:
    int hp;
    int damage;
    QPixmap pix;
    QVector<bullet*> bullets;
    Weapon();
    Weapon* copyweapon();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};
class card :public QGraphicsItem
{
    //Q_OBJECT
public:
    explicit card(QString n);
    void setcoins(int coins);
    bool canbuycard(int coins);
    QString name;
    int needcoins;
    QPixmap pix;
    //Weapon* nowweapon;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
signals:

};
#endif // WEAPON_H
