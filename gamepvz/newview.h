#ifndef NEWVIEW_H
#define NEWVIEW_H

#include <QWidget>
#include<QGraphicsView>
#include<QMouseEvent>
#include"weapon.h"
class newview : public QGraphicsView
{
public:
    int coins;
    Weapon* nowweapon;
    QVector<card*> cards;
    newview(QWidget* widget);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

};

#endif // NEWVIEW_H
