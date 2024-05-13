#ifndef GRID_H
#define GRID_H
#include<QMouseEvent>
#include <QObject>
#include<QDebug>
#include<QGraphicsPixmapItem>
#include<QGraphicsSceneMouseEvent>
class grid:public QGraphicsPixmapItem
{
public:
    bool isplanted;
    grid();
    void mousePressEvent(QGraphicsSceneMouseEvent*ev);

};

#endif // GRID_H
