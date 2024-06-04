#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(1000,570);
    w.label->lower();
    w.show();
    return a.exec();
}
