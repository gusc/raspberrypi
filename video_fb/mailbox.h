/*

Raspbery PI mailbox functions
=============================

mailbox_read - read from VC mailbox
mailbox_write - write to VC mailbox

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

#ifndef __mailbox_h
#define __mailbox_h

#include "common.h"
#include "rpi.h"

/**
* Write to VC mailbox
* @param channel - mailbox channel
* @param data - data to write
*/
static INLINE void mailbox_write(uint8 channel, uint32 data){
	volatile uint32 *status = (uint32 *)(PERIPHERAL_BASE + MAIL_BASE + MAIL_STATUS);
	volatile uint32 *mbox = (uint32 *)(PERIPHERAL_BASE + MAIL_BASE + MAIL_WRITE);
	// Wait until mailbox is NOT full
	while (((*status) & MAIL_FULL) != 0){}
	// Write data into mailbox
	(*mbox) = (data & (~0xF)) | channel;
}

/**
* Read from VC mailbox
* @param channel - mailbox channel
* @return data retrieved from mailbox
*/
static INLINE uint32 mailbox_read(uint8 channel){
	volatile uint32 *status = (uint32 *)(PERIPHERAL_BASE + MAIL_BASE + MAIL_STATUS);
	volatile uint32 *mbox = (uint32 *)(PERIPHERAL_BASE + MAIL_BASE + MAIL_READ);
	uint32 data = 0;
	uint8 in_channel = 0;
	// Wait for data from requested channel (everything else will be discarded)
	for (;;){
		// Wait until mailbox is NOT empty
		while (((*status) & MAIL_FULL) != 0){}
		// Read data
		data = (*mbox);
		in_channel = (uint8)(data & 0xF);
		if (in_channel == channel){
			return (data & (~channel));
		}
	}
	return 0;
}

#endif