/*

Main programm
=============

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

#include "common.h"
#include "rpi.h"
#include "arm.h"
#include "mailbox.h"

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

fb_info_t fb_info ALIGN(16) = {640, 480, 640, 480, 0, 32, 0, 0, 0, 0};

void kmain(void){
	uint32 fb_info_addr = (((uint32)(&fb_info)) + BUS_ADDRESSES_l2CACHE_DISABLED);
	uint32 fb_ok = 0;
	uint32 i;
	uint32 b;
	// Initialize frame buffer
	while (fb_info.fb_ptr == 0){
		mailbox_write(MAIL_FB, fb_info_addr);
		fb_ok = mailbox_read(MAIL_FB) - BUS_ADDRESSES_l2CACHE_DISABLED;
	}
	b = fb_info.fb_size / 4;
	for (i = 0; i < b; i ++){
		// Color bytes go as folows: Alpha, Blue, Green, Red, which becomes RGBA in little endian order
		((uint32 *)fb_info.fb_ptr)[i] = 0xFFFFFFFF;
	}
}

