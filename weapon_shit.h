#ifndef WEAPON_SHIT_H
#define WEAPON_SHIT_H

#include <QWidget>
#include"weapon.h"
class weapon_shit : public Weapon
{
    Q_OBJECT
public:
    static int uplevel;
    explicit weapon_shit();
    void loadpicture();
    void shootbullets();

signals:

};

#endif // WEAPON_SHIT_H
