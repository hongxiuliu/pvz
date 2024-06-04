#ifndef CHOOSEGAME_H
#define CHOOSEGAME_H

#include <QWidget>
#include<QCloseEvent>
#include<QLabel>
#include"playscene.h"
namespace Ui {
class choosegame;
}

class choosegame : public QWidget
{
    Q_OBJECT
public:
    explicit choosegame(QWidget *parent = nullptr);
    ~choosegame();
    void onCloseButton1Closed();
    void onCloseButton2Closed();
    void onCloseButton3Closed();
    void onCloseButton4Closed();
    void show_the_interface();
signals:
    void back_to_start();
private:
    Ui::choosegame *ui;
    QPixmap pix;
    Gamemanager manager;
    Gamemanager state;
    playscene*s;
    QLabel*label;

};

#endif // CHOOSEGAME_H
