#include "mapp.h"
#include<QFile>
#include<QTextStream>
#include<QPixmap>
mapp::mapp(int index)
{
    QFile* file1=new QFile(":/files/map/map1.txt");
    QFile* file2=new QFile(":/files/map/map2.txt");
    QPixmap p1(":/pic/pictures for project/floor.png");
    QPixmap p2(":/pic/pictures for project/grass.png");
    QFile* f;
    switch (index) {
    case 1:f=file1;break;
    case 2:f=file2;break;
    }
    if (f->open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(f);
            // 逐行读取地图文档的内容
            while (!in.atEnd()) {
                QString line = in.readLine();
                QVector<char> row;
                for (QChar c : line) {
                    // 将字符存储到行向量中
                    row.append(c.toLatin1());
                }
                // 将行向量存储到地图向量中
                map1.append(row);
            }
            f->close();
    }
   for(int i=0;i<map1.size();i++){
        QVector<grid*> p(map1[0].size());
        map.push_back(p);
   }

}
