#include "grid.h"
#include<QPainter>
grid::grid()
{
  isplanted=false;
  setAcceptHoverEvents(true);
}
// 在 grid 类中安装事件过滤器
//void grid::installEventFilter() {
//    // 安装事件过滤器，将事件过滤器设置为 grid 对象本身
//    this->installEventFilter();
//}

//// 重写事件过滤器的事件处理函数
//bool grid::eventFilter(QObject *watched, QEvent *event) {
//    if (watched == this && event->type() == QEvent::MouseButtonPress) {
//        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
//        qDebug() << "grid mousePressEvent at position:" << mouseEvent->pos();
//        qDebug() << "Clicked grid object:" << this;
//        qDebug() << "Address:" << reinterpret_cast<quintptr>(this);

//        // 其他事件处理逻辑

//        // 返回 false 表示事件未被过滤，将继续传递
//        return false;
//    }
//    // 其他事件不做处理，返回 false 表示未被过滤
//    return false;
//}

void grid::mousePressEvent(QGraphicsSceneMouseEvent *ev){
    if(ev->button()==Qt::RightButton){
        qDebug()<<"yes";
        qDebug()<<ev->pos();
        qDebug()<<this;
        //qDebug()<<reinterpret_cast<quintptr>(static_cast<const void*>(this));
    }
}
void grid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(0,0,80,80,pix);
}
QRectF grid::boundingRect() const{
    return QRectF(0,0,80,80);
}
