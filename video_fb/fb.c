/*

Frame Buffer driver
===================


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

#include "font\vincent.h"

#include "common.h"
#include "config.h"
#include "fb.h"
#include "mailbox.h"
#include "lib.h"

// Frame buffer info structure
typedef struct {
	uint32 width;		// Frame Buffer Pixel Width
	uint32 heigth;		// Frame Buffer Pixel Height
	uint32 v_width;		// Frame Buffer Virtual Pixel Width
	uint32 v_height;	// Frame Buffer Virtual Pixel Height
	uint32 pitch;		// Frame Buffer Pitch (Set By GPU)
	uint32 bpp;			// Frame Buffer Bits Per Pixel
	uint32 off_x;		// Frame Buffer Offset In X Direction
	uint32 off_y;		// Frame Buffer Offset In Y Direction
	uint32 fb_ptr;		// Frame Buffer Address (Set By GPU)
	uint32 fb_size;		// Frame Buffer Size (Set By GPU)
} PACKED fb_info_t;

// Frame Buffer information structure
fb_info_t fb_info ALIGN(16) = {SCREEN_W, SCREEN_H, SCREEN_W, SCREEN_H, 0, SCREEN_BPP, 0, 0, 0, 0};
// Pointer to frame buffer
uint32 *fb;

void fb_init(){
	uint32 fb_info_addr = (((uint32)(&fb_info)) + BUS_ADDRESSES_l2CACHE_DISABLED);
	uint32 fb_ok = 0;
	uint32 x;
	uint32 y;
	
	// Initialize frame buffer
	while (fb_info.fb_ptr == 0){
		mailbox_write(MAIL_FB, fb_info_addr);
		fb_ok = mailbox_read(MAIL_FB) - BUS_ADDRESSES_l2CACHE_DISABLED;
	}
	fb = (uint32 *)fb_info.fb_ptr;
	
	//TODO: tell page manager and heap manager that ther's this region called frame buffer

	// Fill whole screen with one color
	for (x = 0; x < SCREEN_W; x ++){
		for (y = 0; y < SCREEN_H; y ++){
			// Access each pixel by it's x and y coordinates
			fb[x + (y * SCREEN_W)] = RGBHEX(BASE_COLOR);
		}
	}
}

void fb_pixel(uint32 x, uint32 y, uint32 color){
	if (x < SCREEN_W && y < SCREEN_H){
		fb[x + (y * SCREEN_W)] = color;
	}
}
void fb_line(uint32 x, uint32 y, uint32 x2, uint32 y2, uint32 color){
	
}
void fb_printf(uint32 x, uint32 y, const char *format, va_list args){
	
}