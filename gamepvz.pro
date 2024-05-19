QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    choosegame.cpp \
    enemy1.cpp \
    enemy2.cpp \
    enemy3.cpp \
    ennemy.cpp \
    game.cpp \
    grid.cpp \
    long_range_weapon.cpp \
    main.cpp \
    mapp.cpp \
    playscene.cpp \
    short_range_weapon.cpp \
    weapon.cpp \
    weapon_bottle.cpp \
    weapon_shit.cpp \
    widget.cpp

HEADERS += \
    bullet.h \
    choosegame.h \
    enemy1.h \
    enemy2.h \
    enemy3.h \
    ennemy.h \
    game.h \
    grid.h \
    long_range_weapon.h \
    mapp.h \
    playscene.h \
    short_range_weapon.h \
    weapon.h \
    weapon_bottle.h \
    weapon_shit.h \
    widget.h

FORMS += \
    choosegame.ui \
    game.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc
