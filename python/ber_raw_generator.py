#!/usr/bin/env python
##################################################
# Gnuradio Python Flow Graph
# Title: BER Generator with no Coding
##################################################

from gnuradio import gr, blocks
import fec

class ber_raw_generator(gr.hier_block2):

    def __init__(self, esno=0, berminerrors=100, samp_rate=32000,
                 berlimit=-5.0):
        gr.hier_block2.__init__(
            self, "BER Generator",
            gr.io_signature(0, 0, 0),
            gr.io_signature(1, 1, gr.sizeof_float*1))

        ##################################################
        # Parameters
        ##################################################
        self.esno = esno
        self.berminerrors = berminerrors
        self.samp_rate = samp_rate
        self.berlimit = berlimit

        ##################################################
        # Blocks
        ##################################################
        self.random_gen_b_0 = fec.random_gen_b(0)
        self.gr_unpacked_to_packed_xx_0_0 = blocks.unpacked_to_packed_bb(1, gr.GR_LSB_FIRST)
        self.gr_unpacked_to_packed_xx_0 = blocks.unpacked_to_packed_bb(1, gr.GR_LSB_FIRST)
        self.gr_throttle_0 = blocks.throttle(gr.sizeof_char*1, samp_rate)
        self.gaussnoise_ff_0 = fec.gaussnoise_ff(esno)
        self.ber_bf_0_0 = fec.ber_bf(berminerrors, berlimit)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.gr_unpacked_to_packed_xx_0_0, 0), (self.ber_bf_0_0, 0))
        self.connect((self.gr_unpacked_to_packed_xx_0, 0), (self.ber_bf_0_0, 1))
        self.connect((self.gr_throttle_0, 0), (self.gr_unpacked_to_packed_xx_0, 0))
        self.connect((self.ber_bf_0_0, 0), (self, 0))
        self.connect((self.gaussnoise_ff_0, 0), (self.gr_unpacked_to_packed_xx_0_0, 0))
        self.connect((self.random_gen_b_0, 0), (self.gr_throttle_0, 0))
        self.connect((self.gr_throttle_0, 0), (self.gaussnoise_ff_0, 0))

    def get_esno(self):
        return self.esno

    def set_esno(self, esno):
        self.esno = esno

    def get_berminerrors(self):
        return self.berminerrors

    def set_berminerrors(self, berminerrors):
        self.berminerrors = berminerrors

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate

    def get_berlimit(self):
        return self.berlimit

    def set_berlimit(self, berlimit):
        self.berlimit = berlimit
