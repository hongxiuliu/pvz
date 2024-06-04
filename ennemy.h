#ifndef ENNEMY_H
#define ENNEMY_H

#include <QObject>
#include<QWidget>
#include<QGraphicsItem>
#include<QVector>
#include<QTextStream>
class ennemy :public QObject ,public QGraphicsItem
{
    Q_OBJECT
private:
    void enemysucceed();
public:
    int nowposition;
    static int map[20][20];
    static int column;
    static int row;
    static int begin_row;
    static int maxposition;
    static void deal_moveway();
    static QVector<int> moveway;
    explicit ennemy(QObject *parent = nullptr);
    bool canmove;
    int drop_money;
    int max_hp;
    int hp;
    QPixmap pix;
    int damage;
    int movespeed;
    int type;
    bool iced;
    bool flash;
    int timecnt;//weapon使用持续扣血技能
    ennemy(int level);
    ~ennemy();
    bool enemyisdead();
    bool enemy_out_of_map();
    virtual void loadpicture();
    void move();
    void add_buff(int i);
    int drop_buff();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    friend QTextStream& operator<<(QTextStream& out, ennemy& myStruct) {
            out<<"ennemy"<<" "<<myStruct.hp<<" "<<myStruct.damage<<" "<<myStruct.type<<" ";
            out<<myStruct.pos().x()<<" "<<myStruct.pos().y()<<" "<<myStruct.movespeed<<" "<<myStruct.nowposition;
            out<<endl;
            return out;
        }
signals:
    void isdead(ennemy* enemy);
    void over_map(ennemy*enemy);

};

#endif // ENNEMY_H
