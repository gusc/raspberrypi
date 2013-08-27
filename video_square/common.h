/*

Common data types
=================

This file contains type definitions and helper structures.

The idea of this file is to keep a precise control over data type sizes, so 
instead of int and long, we should have int32 or int64.

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

#ifndef __common_h
#define __common_h

#if defined _MSC_VER
#define __attribute__(x)
#endif

#define NOINLINE  __attribute__((noinline))
#define INLINE	__attribute__((always_inline))
#define REGPARM   __attribute__((regparm(3)))
#define NORETURN  __attribute__((noreturn))
#define PACKED	__attribute__((packed))
#define ALIGN(x)	__attribute__((aligned(x)))
// type = IRQ, FIQ, SWI, ABORT and UNDEF.
#define INTERRUPT(type)	__attribute__((interrupt(type)))

#define HANG() while(true){}

// Default types
typedef unsigned char	uchar;

typedef unsigned char	uint8;
typedef unsigned short	uint16;
typedef unsigned int	uint32;
typedef unsigned long long uint64;

typedef char			int8;
typedef short			int16;
typedef int				int32;
typedef long long		int64;

#define null 0
#define true 1
#define false 0
#define bool uint64

// Variadic funciton arguments
#define va_list			__builtin_va_list
#define va_start(v, f)	__builtin_va_start(v, f)
#define va_end(v)		__builtin_va_end(v)
#define va_arg(v, a)	__builtin_va_arg(v, a)

typedef struct {
	uint32 low;
	uint32 high;
} split_uint64_t;

#endif /* __common_h */
