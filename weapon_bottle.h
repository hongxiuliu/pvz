#ifndef WEAPON_BOTTLE_H
#define WEAPON_BOTTLE_H

#include <QObject>
#include"weapon.h"
class weapon_bottle : public Weapon
{
    //Q_OBJECT
public:
    static int uplevel;
    explicit weapon_bottle();
    void loadpicture() override;
    void shootbullets() override;
//signals:

};

#endif // WEAPON_BOTTLE_H
