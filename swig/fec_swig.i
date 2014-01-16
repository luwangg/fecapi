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

%nodefaultctor gr::fec::generic_encoder;
%template(generic_encoder_sptr) boost::shared_ptr<gr::fec::generic_encoder>;

%nodefaultctor gr::fec::generic_decoder;
%template(generic_decoder_sptr) boost::shared_ptr<gr::fec::generic_decoder>;

%{
#include "fec/generic_encoder.h"
#include "fec/generic_decoder.h"
#include "fec/cc_encoder.h"
#include "fec/cc_decoder.h"
#include "fec/fec_encoder.h"
#include "fec/fec_decoder.h"
#include "fec/fec_ber_bf.h"
#include "fec/fec_corr_bb.h"
#include "fec/fec_deinterleave.h"
#include "fec/fec_interleave.h"
#include "fec/fec_puncture_ff.h"
#include "fec/fec_random_gen_b.h"
#include "fec/fec_reinflate_bb.h"
#include "fec/ber_sink_b.h"
%}

%include "fec/generic_encoder.h"
%include "fec/generic_decoder.h"
%include "fec/cc_encoder.h"
%include "fec/cc_decoder.h"
%include "fec/fec_encoder.h"
%include "fec/fec_decoder.h"
%include "fec/fec_ber_bf.h"
%include "fec/fec_corr_bb.h"
%include "fec/fec_deinterleave.h"
%include "fec/fec_interleave.h"
%include "fec/fec_puncture_ff.h"
%include "fec/fec_random_gen_b.h"
%include "fec/fec_reinflate_bb.h"
%include "fec/ber_sink_b.h"

GR_SWIG_BLOCK_MAGIC2(fec, encoder);
GR_SWIG_BLOCK_MAGIC2(fec, decoder);
GR_SWIG_BLOCK_MAGIC2(fec, ber_bf);
GR_SWIG_BLOCK_MAGIC2(fec, corr_bb);
GR_SWIG_BLOCK_MAGIC2(fec, deinterleave);
GR_SWIG_BLOCK_MAGIC2(fec, interleave);
GR_SWIG_BLOCK_MAGIC2(fec, puncture_ff);
GR_SWIG_BLOCK_MAGIC2(fec, random_gen_b);
GR_SWIG_BLOCK_MAGIC2(fec, reinflate_bb);
GR_SWIG_BLOCK_MAGIC2(fec, ber_sink_b);
