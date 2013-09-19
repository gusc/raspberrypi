/*

GCC helper library
==================

This file contains some missing instruction replacements for GCC on ARM.

* signed integer division
* signed integer modulo
* unsigned integer division
* unsigned integer modulo

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

typedef struct { int quot; int rem; } idiv_return;
typedef struct { unsigned quot; unsigned rem; } uidiv_return;

/** 
* GCC ARM division and modulo for signed integer
* @param n - numerator
* @param d - denumerator
* @return quotient and reminder
*/
idiv_return __aeabi_idivmod(int n, int d){
	idiv_return ret = {0, 0};
	// If one of them is 0 return 0
	if (n == 0){
		return ret;
	} else if (d == 0){
		// I know it's not correct for denumerator,
		// it should rise some exception, but we can not do this now.
		ret.rem = n;
		return ret;
	}
	// Calculate sign for reminder
	int sr = (n & 0x80000000);
	// Calculate sign for quotient
	int sq = sr ^ (d & 0x80000000);
	// Remove sign from numerator
	ret.rem &= n & 0x7FFFFFFF;
	// Calculate division
	while (ret.rem >= d){
		ret.rem -= d;
		ret.quot ++;
	}
	// Add signs
	ret.quot |= sq;
	ret.rem |= sr;
	return ret;
}
/** 
* GCC ARM division and modulo for unsigned integer
* @param n - numerator
* @param d - denumerator
* @return quotient and reminder
*/
uidiv_return __aeabi_uidivmod(unsigned n, unsigned d){
	uidiv_return ret = {0, 0};
	// Calculate division
	while (ret.rem >= d){
		ret.rem -= d;
		ret.quot ++;
	}
	return ret;
}
/** 
* GCC ARM divide for signed integer
* @param n - numerator
* @param d - denominator
* @return quotient
*/
int __aeabi_idiv(int n, int d){
	return __aeabi_idivmod(n, d).quot;
}
/** 
* GCC ARM divide for unsigned integer
* @param n - numerator
* @param d - denominator
* @return quotient
*/
unsigned __aeabi_uidiv(unsigned n, unsigned d){
	return __aeabi_uidivmod(n, d).quot;
}
