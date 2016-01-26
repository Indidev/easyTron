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
    frontend/game/GameOverScreen.cpp \
    backend/Options.cpp \
    backend/io/Input.cpp \
    backend/io/Output.cpp

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
    backend/BikeList.h \
    backend/Options.h \
    backend/io/Input.h \
    backend/io/Output.h \
    backend/KeyboardInterface.h

FORMS    += frontend/MainFrame.ui \
    frontend/menu/MainMenu.ui \
    frontend/menu/IngameMenu.ui \
    frontend/game/GameOverScreen.ui

# Define copy command for linux and windows
QMAKE_COPY = cp -rf
Win32:QMAKE_COPY = copy /y

# cp(src, dest) returns the copy command
defineReplace(cp) {
    SDIR = $$PWD/$$1
    DDIR = $$OUT_PWD/$$2

    # Replace slashes in paths with backslashes for Windows
    win32:DDIR ~= s,/,\\,g
    win32:SDIR ~= s,/,\\,g

    return($$QMAKE_COPY $$SDIR $$DDIR;)
}
cpFiles.commands += $$cp(versionInfo, ./)

#Add dependencies to first
first.depends += cpFiles

#add dependencies to makefile
QMAKE_EXTRA_TARGETS += first cpFiles
