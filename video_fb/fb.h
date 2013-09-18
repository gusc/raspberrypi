/*

Frame Buffer driver
===================

Some macros to help with colors

License (BSD-2)
===============

Copyright (c) 2013, Gusts 'gusC' Kaksis <gusts.kaksis@gmail.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

  Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

  Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef __fb_h
#define __fb_h

#include "common.h"

#define RGBA32(red, green, blue, alpha) (red | (green << 8) | (blue << 16) | alpha << 24)
#define RGB32(red, green, blue) (red | (green << 8) | (blue << 16) | 0xFF000000)
#define RGBHEX(hex) (((hex & 0xFF0000) >> 16) | (hex & 0xFF00) | ((hex & 0xFF) << 16) | 0xFF000000)
#define RGBHEXA(hex) (((hex & 0xFF000000) >> 24) | ((hex & 0xFF0000) >> 16) | ((hex & 0xFF00) << 16) | ((hex & 0xFF) << 24))

void fb_init();
void fb_pixel(uint32 x, uint32 y, uint32 color);
void fb_line(uint32 x, uint32 y, uint32 x2, uint32 y2, uint32 color);

#endif
