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

#ifndef INCLUDED_FEC_ENCODER_H
#define INCLUDED_FEC_ENCODER_H

#include <fec_api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace fec {

    class FEC_API generic_encoder
    {
    public:
      friend class encoder;
      virtual void generic_work(void *inBuffer, void *outBuffer) = 0;
    public:
      typedef boost::shared_ptr<generic_encoder> sptr;

      virtual int get_input_size() = 0;
      virtual int get_output_size() = 0;
      generic_encoder(void) {};
      virtual ~generic_encoder();
    };

    FEC_API int get_encoder_output_size(generic_encoder::sptr my_encoder);
    FEC_API int get_encoder_input_size(generic_encoder::sptr my_encoder);

    class FEC_API encoder : virtual public block
    {
    public:
      typedef boost::shared_ptr<encoder> sptr;

      static sptr make(generic_encoder::sptr my_encoder,
                       size_t input_item_size,
                       size_t output_item_size);

      virtual int general_work(int noutput_items,
                               gr_vector_int& ninput_items,
                               gr_vector_const_void_star &input_items,
                               gr_vector_void_star &output_items) = 0;
      virtual int fixed_rate_ninput_to_noutput(int ninput) = 0;
      virtual int fixed_rate_noutput_to_ninput(int noutput) = 0;
      virtual void forecast(int noutput_items,
                            gr_vector_int& ninput_items_required) = 0;
    };

  } /* namespace fec */
} /* namespace gr */

#endif /* INCLUDED_FEC_ENCODER_H */
