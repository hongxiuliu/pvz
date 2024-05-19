#ifndef WEAPON_BOTTLE_H
#define WEAPON_BOTTLE_H

#include <QObject>
#include"long_range_weapon.h"
class weapon_bottle : public long_range_weapon
{
    //Q_OBJECT
public:
    //int bullet_type;
    explicit weapon_bottle();
    void loadpicture() override;
    void shootbullets() override;
//signals:

};

#endif // WEAPON_BOTTLE_H
