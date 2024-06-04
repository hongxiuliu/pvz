#ifndef UPLEVEL_H
#define UPLEVEL_H

#include <QWidget>
#include<QLabel>
#include<weapon_bottle.h>
#include<weapon_shit.h>
#include<gamestatemanager.h>
namespace Ui {
class Uplevel;
}

class Uplevel : public QWidget
{
    Q_OBJECT
private:
    Gamemanager manager;
    QPixmap pix;
    QLabel* label;
public:
    explicit Uplevel(QWidget *parent = nullptr);
    void up_long_range_weapon();
    void up_short_range_weapon();
    void canbuy();
    ~Uplevel();
signals:
    void back_to_begin_interface();
private:
    Ui::Uplevel *ui;
};

#endif // UPLEVEL_H
