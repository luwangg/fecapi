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

#ifndef INCLUDED_FEC_RANDOM_GEN_B_H
#define INCLUDED_FEC_RANDOM_GEN_B_H

#include <fec/fec_api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace fec {

    /*!
     * \brief Random number generator block in FECAPI
     * \ingroup error_coding_blk
     *
     * \details
     *
     * What does this block do?
     */
    class FEC_API random_gen_b : virtual public sync_block
    {
    public:
      // gr::fec::random_gen_b::sptr
      typedef boost::shared_ptr<random_gen_b> sptr;

      static sptr make(long int randseed = 0);
    };

  } /* namespace fec */
} /* namespace gr */

#endif /* INCLUDED_FEC_RANDOM_GEN_B_H */
