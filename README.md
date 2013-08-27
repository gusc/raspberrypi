RaspberryPi Bare Metal Tests
===========================

This is my take on Raspberry Pi Bare Metal programming

video_fb
--------

Frame Buffer test. Draw a square using VideoCore frame buffer
using 640x480 resolution and 32bits per pixel. Colors are in RGBA order, just little endian reversed order, so: 
0xFFAACC44 means Alpha: 0xFF, Blue: 0xAA, Green: 0xCC, Red: 0x44

Build Requirements
------------------

You'll need:
* SysProgs Raspbery Pi GNU Toolchain: http://gnutoolchains.com/raspberry/
* Microsoft Visual Studio Express 2010
