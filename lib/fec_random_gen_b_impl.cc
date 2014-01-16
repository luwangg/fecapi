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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "fec_random_gen_b_impl.h"
#include <gnuradio/io_signature.h>
#include <fec/libbertools.h>
#include <math.h>
#include <time.h>

namespace gr {
  namespace fec {

    random_gen_b::sptr
    random_gen_b::make(long int randSeed)
    {
      return gnuradio::get_initial_sptr
        (new random_gen_b_impl(randSeed));
    }

    random_gen_b_impl::random_gen_b_impl(long int randSeed)
      : sync_block("random_gen_b",
                   io_signature::make(0,0,0),
                   io_signature::make(1, 1, sizeof(unsigned char)))
    {
      if(randSeed == 0) {
	d_randSeed = 0xfff & (long int)time(NULL);
	srand48(randSeed);
      }
      else {
	d_randSeed = randSeed;
      }
    }

    random_gen_b_impl::~random_gen_b_impl()
    {
    }

    int
    random_gen_b_impl::work(int noutput_items,
                            gr_vector_const_void_star &input_items,
                            gr_vector_void_star &output_items)
    {
      unsigned char *outBuffer = (unsigned char *)output_items[0];

      randBuffer(outBuffer, noutput_items, 1);

      return noutput_items;
    }

  } /* namespace fec */
} /* namespace gr */
