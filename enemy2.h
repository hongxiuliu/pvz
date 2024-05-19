#ifndef ENEMY2_H
#define ENEMY2_H

#include <QWidget>
#include"ennemy.h"
class enemy2 : public ennemy
{
    Q_OBJECT
public:
    explicit enemy2(int level);
    int piccnt;
    void loadpicture();
signals:

};

#endif // ENEMY2_H
