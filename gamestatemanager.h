#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <QWidget>
#include<QFile>
#include<weapon.h>
#include<ennemy.h>
#include<bullet.h>
#include<QFileDialog>
#include<QTextStream>
#include"mapp.h"
struct gamestate{
    int expeience;
    int level;
    friend QTextStream& operator<<(QTextStream& out, const gamestate& myStruct) {
            out << myStruct.expeience <<endl;
            out<<  myStruct.level<<endl;
            return out;
        }
        friend QTextStream& operator>>(QTextStream& in, gamestate& myStruct) {
            int cnt=0;
            while(cnt<2){
                QString line = in.readLine();
                int value = line.toInt();
                if(cnt==0) myStruct.expeience=value;
                if(cnt==1)myStruct.level=value;
                cnt++;
            }
            return in;
        }
};

class Gamemanager : public QWidget
{
    Q_OBJECT
public:
    gamestate state;
    QTextStream cout;
    QTextStream cin;
    QFile file;
    explicit Gamemanager();
    void addexpeience(int i);
    void spendexpeience(int i);
    void saveStateToFile(const QString& filename);
    void loadStateFromFile(const QString&filename);
    QVector<QVector<QString>> LoadAllFromFile();
signals:

};

#endif // GAMESTATEMANAGER_H
