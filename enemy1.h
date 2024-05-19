#ifndef ENEMY1_H
#define ENEMY1_H

#include <QObject>
#include"ennemy.h"
class enemy1:public ennemy
{
public:
    int count;
    enemy1(int level);
    void loadpicture();
};

#endif // ENEMY1_H
