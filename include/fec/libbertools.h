/* -*- c++ -*- */
/*
 * Copyright 2013-2014 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

/*
   Description: Include file for BERTOOLS Library
*/

#ifndef _LIBBERTOOLS_H
#define _LIBBERTOOLS_H

// ##################### Includes #########################  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 



// #################### Constants #########################
#define BERMINFRAMES (10000)   
#define BERMINERRORS  (100) 
#define BERMAXBITS    (1000000000)
#define CRCSIZE (16)
// #################### Function Declarations #########################

void char2bin(unsigned char *inbuffer,int buffSize);
void gaussnoise(float *inBuffer, int buffSize, float sigma);
int compBER(unsigned char *inBuffer1, unsigned char *inBuffer2,int buffSize);
void randBuffer(unsigned char *dataBuffer,int buffSize, int charOut);
#endif  // _LIBBERTOOLS_H


