#ifndef CHOOSEGAME_H
#define CHOOSEGAME_H

#include <QWidget>
#include<QCloseEvent>
#include"game.h"
namespace Ui {
class choosegame;
}

class choosegame : public QWidget
{
    Q_OBJECT

public:
    explicit choosegame(QWidget *parent = nullptr);
    ~choosegame();
    game*g;
    void onCloseButton1Closed();
private:
    Ui::choosegame *ui;
};

#endif // CHOOSEGAME_H
