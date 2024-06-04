#include "gamestatemanager.h"
#include"weapon_bottle.h"
#include"weapon_shit.h"
#include<QDebug>
Gamemanager::Gamemanager(){
//    file.setFileName(":/files/map/game_state.dat.txt");
//    cin.setDevice(&file);
//    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
//        cin>>state;
//    }
//    file.close();
}
void Gamemanager::addexpeience(int i){
    state.expeience+=i;
}
void Gamemanager::spendexpeience(int i){
    state.expeience-=i;
}
void Gamemanager::saveStateToFile(const QString& filename) {
    QFile outFile(filename);
    if (!outFile.open( QIODevice::WriteOnly|QIODevice::Text )) {
        qDebug() << "Failed to open file for writing.";
        return;
    }
    QTextStream out(&outFile);
    //out.setVersion(QDataStream::Qt_5);
    out << state;
    out<<weapon_shit::uplevel<<endl;
    out<<weapon_bottle::uplevel<<endl;
    outFile.close();
}
void Gamemanager::loadStateFromFile(const QString& filename) {
    QFile inFile(filename);
    if (!inFile.exists()) { // 检查文件是否存在
           qDebug() << "File does not exist. Creating a new file.";
           saveStateToFile(filename); // 如果文件不存在，调用 saveToFile() 来创建文件并写入数据
           return;
       }

    if (!inFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return;
    }
    QTextStream in(&inFile);
    //in.setVersion(QDataStream::Qt_5);
    in >> state; // 从数据流中读取状态
    inFile.close();
}
QVector<QVector<QString>> Gamemanager::LoadAllFromFile(){
    QString path=QFileDialog::getOpenFileName(nullptr,"选择存档文件","D:/", "Text Files (*.txt)");
    QVector<QVector<QString>> result;
    QVector<QString> word;
    file.setFileName(path);
    cin.setDevice(&file);
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"fail to open the file";
        return result;
    }
    while(!cin.atEnd()){
        QString line=cin.readLine();
        QStringList parts=line.split(" ");
       for(int i=0;i<parts.size();i++){
           word.push_back(parts.value(i));
       }
       result.push_back(word);
       word.clear();
    }
    return result;
}
