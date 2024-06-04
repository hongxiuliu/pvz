#ifndef BULLET_H
#define BULLET_H

#include <QWidget>
#include<QGraphicsItem>
#include"QPixmap"
#include"QPainter"
#include<cmath>
#include<QTextStream>
class bullet :public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
     QPixmap pix;
     QPointF position;
     double move_x;
     double move_y;
     double rotate_angle;
     double move_speed;

public:
    explicit bullet(double rotate,int type,QPointF pos,int dam);
    int types;
    int damage;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
    void move();
    friend QTextStream& operator<<(QTextStream& out, bullet& myStruct) {
            out<<"bullet"<<" "<<myStruct.damage<<" "<<(int)myStruct.pos().x()<<" "<<(int)myStruct.pos().y()<<" ";
            out<<myStruct.types<<" "<<(int)myStruct.rotate_angle;
            out<<endl;
            return out;
        }
signals:
    void over_map(bullet* bull);

};

#endif // BULLET_H
