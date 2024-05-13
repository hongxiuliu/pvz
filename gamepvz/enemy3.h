#ifndef ENEMY3_H
#define ENEMY3_H

#include <QWidget>
#include"ennemy.h"
class enemy3 : public ennemy
{
    Q_OBJECT
public:
    explicit enemy3(int level);
    int piccnt;
    void loadpicture() override;
signals:

};

#endif // ENEMY3_H
