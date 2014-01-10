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

#define FEC_API

%include "gnuradio.i"        // the common stuff

// the .i files
%include <fec_encoder.i>
%include <fec_decoder.i>
%include <ber_sink_b.i>

%{
#include "cc_encoder.h"
#include "cc_decoder.h"
#include "fec_ber_bf.h"
#include "fec_corr_bb.h"
#include "fec_deinterleave.h"
#include "fec_interleave.h"
#include "fec_puncture_ff.h"
#include "fec_random_gen_b.h"
#include "fec_reinflate_bb.h"
%}

%include "cc_encoder.h"
%include "cc_decoder.h"
%include "fec_ber_bf.h"
%include "fec_corr_bb.h"
%include "fec_deinterleave.h"
%include "fec_interleave.h"
%include "fec_puncture_ff.h"
%include "fec_random_gen_b.h"
%include "fec_reinflate_bb.h"

GR_SWIG_BLOCK_MAGIC2(fec, ber_bf);
GR_SWIG_BLOCK_MAGIC2(fec, corr_bb);
GR_SWIG_BLOCK_MAGIC2(fec, deinterleave);
GR_SWIG_BLOCK_MAGIC2(fec, interleave);
GR_SWIG_BLOCK_MAGIC2(fec, puncture_ff);
GR_SWIG_BLOCK_MAGIC2(fec, random_gen_b);
GR_SWIG_BLOCK_MAGIC2(fec, reinflate_bb);
