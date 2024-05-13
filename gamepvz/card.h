#ifndef CARD_H
#define CARD_H

#include <QWidget>
//#include<QPixmap>
#include<QGraphicsItem>
class card : public QWidget,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit card(QString n);
    QString name;
    //QPixmap pix;

signals:

};

#endif // CARD_H
