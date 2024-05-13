#ifndef MAPP_H
#define MAPP_H

#include <QWidget>
#include"grid.h"
#include<QVector>
class mapp
{

public:
    QVector<QVector<grid*>> map;
    QVector<QVector<char>> map1;
    mapp(int index);
};

#endif // MAPP_H
