/* -*- c++ -*- */

%{
#include "fec_decoder.h"
%}

%include "fec_decoder.h"

%nodefaultctor gr::fec::generic_decoder;

GR_SWIG_BLOCK_MAGIC2(fec, decoder);

%template(generic_decoder_sptr) boost::shared_ptr<gr::fec::generic_decoder>;
%rename(get_decoder_output_size) fec_get_decoder_output_size(gr::fec::generic_decoder::sptr);
%rename(get_decoder_input_size) fec_get_decoder_input_size(gr::fec::generic_decoder::sptr);
%rename(get_decoder_output_item_size) fec_get_decoder_output_item_size(gr::fec::generic_decoder::sptr);
%rename(get_decoder_input_item_size) fec_get_decoder_input_item_size(gr::fec::generic_decoder::sptr);
%rename(get_conversion) fec_get_conversion(gr::fec::generic_decoder::sptr);
%rename(get_shift) fec_get_shift(gr::fec::generic_decoder::sptr);
%rename(get_output_conversion) fec_get_output_conversion(gr::fec::generic_decoder::sptr);
%rename(get_history) fec_get_history(gr::fec::generic_decoder::sptr);
