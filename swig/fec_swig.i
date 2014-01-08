/* -*- c++ -*- */

#define FEC_API

%include "gnuradio.i"			// the common stuff

// the .i files
%include <fec_random_gen_b.i>
%include <fec_encoder.i>
%include <fec_decoder.i>
%include <fec_interleave.i>
%include <fec_deinterleave.i>
%include <cc_decoder.i>
%include <cc_encoder.i>
%include <fec_corr_bb.i>
%include <fec_reinflate_bb.i>
%include <ber_sink_b.i>

%{
#include "fec_ber_bf.h"
#include "fec_puncture_ff.h"
%}

%include "fec_ber_bf.h"
%include "fec_puncture_ff.h"

GR_SWIG_BLOCK_MAGIC2(fec, ber_bf);
GR_SWIG_BLOCK_MAGIC2(fec, puncture_ff);
