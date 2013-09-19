/*

MMU Page manager
================


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
#include "config.h"
#include "pages.h"
#include "lib.h"

/**
* Translation table base
*/
typedef struct {
	uint32 addr	:16;
} PACKED page_ttbr_t;
/**
* First-level descriptor entry
* for coarse tables
*/
typedef union {
	struct {
		uint32 type			:2;		// Descriptor type (always=1)
		uint32 sbz			:3;		// Should be 0
		uint32 domain		:4;		// Domain
		uint32 ecc			:1;		// ECC enabled
		uint32 coarse_base	:22;	// Coarse page table base address
	} bits;
	uint32 val;
} PACKED page_fld_t;
/**
* Second-level descriptor entry
* for small pages (4KB)
*/
typedef struct {
	struct {
		uint32 xn			:1;		// Disable code execution from this page
		uint32 sbo			:1;		// Should be 1
		uint32 buffered		:1;		// Can this page be buffered
		uint32 cached		:1;		// Can this page be cached
		uint32 ap			:2;		// Access permission bits
		uint32 tex			:3;		// Type extension bits
		uint32 apx			:1;		// Extended access permissions enable
		uint32 shared		:1;		// Is this page shared
		uint32 nglobal		:1;		// Is this page NOT global
		uint32 addr_base	:20;	// Physical base address
	} bits;
	uint32 val;
} PACKED page_sld_t;

page_fld_t *ttbr0 ALIGN(0x4000);
page_fld_t *ttbr1 ALIGN(0x4000);

void pages_init(){
	uint32 i;
	// Page tables go at the beginning of the kernel base memory
	ttbr1 = (page_fld_t *)MEM_KBASE;
	// We use N=2 on TTBR0, so it has to be only 4KB aligned
	ttbr0 = (page_fld_t *)MEM_KBASE + 0x1000;
	// Clear first level tables
	mem_fill((uint8 *)MEM_KBASE, 0x2000, 0);
	// So it seems that we can have 256 entries in each table
	for (i = 0; i < 256; i ++){
		//TODO: build page tables
		//TODO: identity map all the memory	
	}
	//TODO: enable paging
}
