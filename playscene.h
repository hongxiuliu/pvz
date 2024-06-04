#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QWidget>
#include"game.h"
#include<QPushButton>
class playscene : public QWidget
{
    Q_OBJECT
public:
    explicit playscene(QWidget *parent = nullptr);
    int level;
    game*g;
    int stop_times;
    QPushButton*map;
    QPushButton*back;
    QPushButton*stop;
    QPushButton*save;
    QPushButton*load;
    QPushButton*begin;
    void init(int level);
    ~playscene();
signals:
   void back_to_chooselevelscene();
};

#endif // PLAYSCENE_H
