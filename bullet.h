#ifndef BULLET_H
#define BULLET_H

#include <QWidget>
#include<QGraphicsItem>
#include"QPixmap"
#include"QPainter"
#include<cmath>
#include<QVector2D>
class bullet :public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit bullet(double rotate,int type,QPointF pos,int dam);
    int types;

    QPixmap pix;
    int damage;
    QPointF position;
    double move_x;
    double move_y;
    double rotate_angle;
    double move_speed;
    //QVector2D m_velocity;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
    void move();
signals:
    void over_map(bullet* bull);

};

#endif // BULLET_H
