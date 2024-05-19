#ifndef ENNEMY_H
#define ENNEMY_H

#include <QObject>
#include<QWidget>
#include<QGraphicsItem>
#include<QVector>

class ennemy :public QObject ,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit ennemy(QObject *parent = nullptr);
    bool canmove;
    int hp;
    int damage;
    int movespeed;
    int nowposition;
    int maxposition;
    int drop_money;
    QPixmap pix;
    QMovie*movie;
    QVector<QPointF> moveway;

    ennemy(int level);
    bool enemyisdead();
    bool enemy_out_of_map();
    virtual void loadpicture();
    void move();
    void collide();
    void oversee();
    void enemysucceed();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

signals:
    void isdead(ennemy* enemy);
    void over_map(ennemy*enemy);
};



#endif // ENNEMY_H
