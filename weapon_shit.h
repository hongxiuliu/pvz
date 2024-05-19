#ifndef WEAPON_SHIT_H
#define WEAPON_SHIT_H

#include <QWidget>
#include"short_range_weapon.h"
class weapon_shit : public short_range_weapon
{
    Q_OBJECT
public:
    explicit weapon_shit();
    void loadpicture();

signals:

};

#endif // WEAPON_SHIT_H
