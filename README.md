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
  1. Make sure you have installed SDL2 Runtime binaries from https://www.libsdl.org/download-2.0.php (Dropping the SDL2.framework file into /Library/Frameworks)
  2. Make sure you have installed SDL2\_image Runtime binaries from https://www.libsdl.org/projects/SDL\_image (Dropping the SDL2\_image.framework file into /Library/Frameworks)
  3. Make sure you have installed LUA (v5.2.3) from http://www.lua.org/download.html. (Compiled from the source is better ./configure && make macosx test && sudo make install) 
  4. make all
  5. ./pemu -h

* Linux (Only works for ubuntu right now. All other linuxbased have to find the source-files and install them seperately)

  1. ctrl + alt + T							//this will open a terminal
  2. mkdir workspace							//creates a folder called “workspace”
  3. cd workspace							//now you should be in your workspace folder
  4. git clone ssh://youid123@pumi-2.ida.liu.se/opt/git/pemu.git	//youid123 should be your liuid
									//During git clone you will be asked to write yes and your liuID-password.
									//now you should have a folder named “pemu” if you write the command ls
									//I now recommend you to copy this folder and put it somewhere else so you wont get any future problem with the repository. 
									//Open pemu in this new folder through the terminal. You have to be in the "pemu"-folder to continue!
  5. make
									//this will give you some errors that you dont have files like sdl2-main, sdl2_image
  6. sudo apt-get install libsdl2-image-dev
  7. sudo apt-get install liblua5.2-dev					//During sudo apt-get you will be asked to write in your computer password
  8. make								//You should now have no errors and a “pemu” file in your folder!
  9. cp pemu examples
  10. cd examples
  11. ./pemu -f lua.lua							//if ./pemu -f lua.lua errors and says something about you not having access rights, 
									//you could write chmod 755 pemu and then try ./pemu -f lua.lua again. 
									//You should now be seeing a bear with a red background on your screen. You now have the emulator!
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
