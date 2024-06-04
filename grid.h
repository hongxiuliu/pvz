#ifndef GRID_H
#define GRID_H
#include<QMouseEvent>
#include <QObject>
#include<QDebug>
#include<QGraphicsItem>
#include<QGraphicsSceneMouseEvent>
class grid:public QObject ,public QGraphicsItem
{
    Q_OBJECT
private:
public:
    QPixmap pix;
    bool isplanted;
    int types;

    grid();
    void mousePressEvent(QGraphicsSceneMouseEvent*ev) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;

};

#endif // GRID_H
