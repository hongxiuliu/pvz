#ifndef GRID_H
#define GRID_H
#include<QMouseEvent>
#include <QObject>
#include<QDebug>
#include<QGraphicsItem>
#include<QGraphicsSceneMouseEvent>
class grid:public QGraphicsItem
{
public:
    bool isplanted;
    int types;
    QPixmap pix;
    void installEventFilter();
    bool eventFilter(QObject *watched, QEvent *event);
    grid();
    void mousePressEvent(QGraphicsSceneMouseEvent*ev) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // GRID_H
