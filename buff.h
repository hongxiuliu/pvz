#ifndef BUFF_H
#define BUFF_H

#include <QObject>
#include<QGraphicsItem>
#include<QPainter>
#include<QGraphicsSceneMouseEvent>
class buff {
public:
    int object_type;
    int specific_type;
    explicit buff(int ob_type,int spe_type);
};
class card_slot:public QObject,public QGraphicsItem
{
  Q_OBJECT
private:
    QPixmap pix;
public:
    card_slot(int type);
    int card_type;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
signals:
    void isclicked(QString s);

};

#endif // BUFF_H
