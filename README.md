PumpITApp Emulator
==================

First prototype to implement an emulator for the Zentorio OS!

Features
--------
For the moment, it can just pop a window and create surfaces as well as fill these with a color, pretty basic.
The lua code is taken is input from the stdin. 

Installation
------------
For the moment, the only available platform is OS X.

* OS X
  1. Make sure you have installed SDL2 Runtime binaries from https://www.libsdl.org/download-2.0.php
  2. Make sure you have installed LUA (v5.2.3) from http://www.lua.org/download.html. (Dropping the SDL2.framework file into /Library/Frameworks)
  3. cd src/
  4. make all
  5. ./pemu
  6. A new window should appear and you can write your LUA code in the stdin of your terminal !

* Linux
  TODO ! We should update the Makefile

* Windows
  Not sure how to support Windows for the moment.

Example
-------
1. Launch ./pemu, after the window has popped, the stdin wait for LUA code to be entered.
2. Then type in the stdin :
    gfx = require "gfx"
    gfx.screen:fill({r=255, g=0, b=0, a=0}, {x=0, y=0, w=640, h=480})
    gfx.update()
3. Get back to the window, it should have popped a red surface ;)

How it works ?
--------------
Pretty easy, just read the code and give him some love :).
