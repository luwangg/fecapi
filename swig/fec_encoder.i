/* -*- c++ -*- */

%{
#include "fec_encoder.h"
%}

%include "fec_encoder.h"

%nodefaultctor gr::fec::generic_encoder;

GR_SWIG_BLOCK_MAGIC2(fec, encoder);

%template(generic_encoder_sptr) boost::shared_ptr<gr::fec::generic_encoder>;
%rename(get_encoder_output_size) fec_get_encoder_output_size(gr::fec::generic_encoder::sptr);
%rename(get_encoder_input_size) fec_get_encoder_input_size(gr::fec::generic_encoder::sptr);
