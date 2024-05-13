#ifndef ENEMY_H
#define ENEMY_H

#include<QWidget>
#include<QGraphicsItem>
#include<QVector>

class enemy:public QGraphicsItem
{
     //Q_OBJECT
public:
    int hp;
    int damage;
    int movespeed;
    int nowposition;
    int maxposition;
    QPointF position;
    QPixmap pix;
    QMovie*movie;
    QVector<QPointF> moveway;

    enemy(int level);
    void enemyisdead();
    virtual void loadpicture();
    void move();
    void enemysucceed();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

signals:
    void isdead();
};

#endif // ENEMY_H
