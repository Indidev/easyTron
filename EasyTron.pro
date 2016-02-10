#-------------------------------------------------
#
# Project created by QtCreator 2016-01-04T16:57:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EasyTron
TEMPLATE = app
LIBS += -lsfml-window
LIBS += -lsfml-system

QMAKE_CXXFLAGS += -std=c++11

SOURCES += easyTron.cpp\
    frontend/MainFrame.cpp \
    frontend/LayeredWidget.cpp \
    frontend/menu/MainMenu.cpp \
    frontend/menu/IngameMenu.cpp \
    frontend/game/PlayArea.cpp \
    frontend/game/CountdownWidget.cpp \
    frontend/game/PlayingField.cpp \
    frontend/game/GameOverScreen.cpp \
    backend/GameManager.cpp \
    backend/game/Bike.cpp \
    backend/game/controller/BikeController.cpp \
    backend/game/controller/LocalBikeController.cpp \
    backend/time/Ticker.cpp \
    backend/io/Input.cpp \
    backend/io/Output.cpp \
    backend/util/InputGrabber.cpp \
    backend/util/Options.cpp \
    backend/util/JoystickListener.cpp \
    backend/util/InputEvent.cpp \
    backend/game/Lobby.cpp \
    frontend/game/LobbyWidget.cpp \
    backend/util/InputMapping.cpp

HEADERS  += frontend/MainFrame.h \
    frontend/LayeredWidget.h \
    frontend/menu/MainMenu.h \
    frontend/menu/IngameMenu.h \
    frontend/game/PlayArea.h \
    frontend/game/CountdownWidget.h \
    frontend/game/PlayingField.h \
    frontend/game/GameOverScreen.h \
    backend/GameManager.h \
    backend/game/Bike.h \
    backend/game/Position.h \
    backend/game/BikeList.h \
    backend/game/controller/BikeController.h \
    backend/game/controller/LocalBikeController.h \
    backend/time/Ticker.h \
    backend/io/Input.h \
    backend/io/Output.h \
    backend/util/Options.h \
    backend/util/InputGrabber.h \
    backend/util/InputInterface.h \
    backend/util/JoystickListener.h \
    backend/util/InputEvent.h \
    backend/game/Lobby.h \
    frontend/game/LobbyWidget.h \
    backend/util/InputMapping.h \
    EasyTronDef.h

FORMS    += frontend/MainFrame.ui \
    frontend/menu/MainMenu.ui \
    frontend/menu/IngameMenu.ui \
    frontend/game/GameOverScreen.ui \
    frontend/game/LobbyWidget.ui

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
