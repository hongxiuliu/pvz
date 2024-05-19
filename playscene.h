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
    QPushButton*stop;
    QPushButton*save;
    void init(int level);
signals:

};

#endif // PLAYSCENE_H
