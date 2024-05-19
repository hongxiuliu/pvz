#ifndef LONG_RANGE_WEAPON_H
#define LONG_RANGE_WEAPON_H

#include <QObject>
#include"weapon.h"
class long_range_weapon : public Weapon
{
   //Q_OBJECT
public:
    qreal angle;
    explicit long_range_weapon();

//signals:

};

#endif // LONG_RANGE_WEAPON_H
