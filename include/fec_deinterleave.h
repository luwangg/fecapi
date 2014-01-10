/* -*- c++ -*- */
/*
 * Copyright 2012-2013 Free Software Foundation, Inc.
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

#ifndef INCLUDED_FEC_DEINTERLEAVE_H
#define INCLUDED_FEC_DEINTERLEAVE_H

#include <fec_api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace fec {

    /*!
     * \brief deinterleave signal input to N coding blocks
     */
    class FEC_API deinterleave : virtual public block
    {
    public:
      // gr::fec::deinterleave::sptr
      typedef boost::shared_ptr<deinterleave> sptr;

      static sptr make(size_t itemsize, unsigned int blocksize);
    };

  } /* namespace fec */
} /* namespace gr */

#endif /* INCLUDED_FEC_DEINTERLEAVE_H */
