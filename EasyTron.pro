#-------------------------------------------------
#
# Project created by QtCreator 2016-01-04T16:57:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EasyTron
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += easyTron.cpp\
        frontend/MainFrame.cpp \
    backend/Bike.cpp \
    backend/BikeUpdater.cpp \
    frontend/game/PlayArea.cpp \
    frontend/menu/MainMenu.cpp \
    frontend/menu/IngameMenu.cpp \
    backend/KeyboardGrabber.cpp \
    backend/Player.cpp \
    frontend/LayeredWidget.cpp \
    backend/GameManager.cpp \
    frontend/game/CountdownWidget.cpp \
    backend/Ticker.cpp \
    frontend/game/PlayingField.cpp \
    frontend/game/GameOverScreen.cpp

HEADERS  += frontend/MainFrame.h \
    backend/Bike.h \
    backend/Position.h \
    backend/BikeUpdater.h \
    frontend/game/PlayArea.h \
    frontend/menu/MainMenu.h \
    frontend/menu/IngameMenu.h \
    backend/KeyboardGrabber.h \
    backend/Player.h \
    frontend/LayeredWidget.h \
    backend/GameManager.h \
    frontend/game/CountdownWidget.h \
    backend/Refreshable.h \
    backend/Ticker.h \
    frontend/game/PlayingField.h \
    frontend/game/GameOverScreen.h \
    backend/BikeList.h

FORMS    += frontend/MainFrame.ui \
    frontend/menu/MainMenu.ui \
    frontend/menu/IngameMenu.ui \
    frontend/game/GameOverScreen.ui
