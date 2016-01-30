# easyTron

easyTron is a 2D clone of Armagetron, currently in **PRE-ALPHA**, so don't expect too much yet.

This project will have a focus on multiplayer gaming, including a mode, where multiple participants will share one display but can use their own (networkbased) input device (laptop, smartphone,...)


<!-- [toc] -->
## Table of Contents

   * [Compilation and dependencies](#compilation-and-dependencies)
     * [Dependencies](#dependencies)
       * [QT 4 / 5](#qt-4--5)
       * [SFML (optional)](#sfml-optional)
     * [Compilation](#compilation)
   * [Control](#control)
     * [Shortcuts](#shortcuts)
       * [Global](#global)
       * [Ingame](#ingame)

<!-- [toc] -->
## Compilation and dependencies

### Dependencies

#### QT 4 / 5
EasyTron depents on QT Version >= 4 so make sure at least QT4 or is installed (QT5 is recommended):

**Linux:** (run as root or via sudo)
 * QT5 (for QT4 replace 5 with 4):
``` bash
apt-get install qt5-default qt5-qmake
```

**Windows:**

Check http://www.qt.io/download/

#### SFML (optional)
SFML is needed for the Joystick support.
You can compile withoug SFML by appending ```DEFINES+=NO_SFML``` to your qmake command

### Compilation ###

Run following in your easyTron directory:
``` bash
mkdir build
cd build
qmake ..
make
```

You can now run easyTron via ```./easyTron``` in your build directory


## Control
In the pre-alpha there are only two bikes, player 1 and player 2, here are the controls:


| Player | Up | Down | Left | Right
|--------|----|------|------|--------
|1		| Up | Down | Left | Right
|2 		| W | S | A | D

So nothing special right now.

### Shortcuts

#### Global
 * Alt + Return: switch between Fullscreen and Window mode
 * ctrl + Q : Quit
 
#### Ingame
 * F10: Toggle player names
 * F11: Toggle frames per second
