#!/usr/bin/env python
##################################################
# Gnuradio Python Flow Graph
# Title: FECTEST Generator with no coding
##################################################


from gnuradio import gr, blocks
import fec

class fec_raw_test(gr.hier_block2):

	def __init__(self, esno=0, samp_rate=3200000):
		gr.hier_block2.__init__(
			self, "FECTEST",
			gr.io_signature(1, 1, gr.sizeof_char*1),
			gr.io_signature(2, 2, gr.sizeof_char*1))
                
		##################################################
		# Parameters
		##################################################
		self.esno = esno
		self.samp_rate = samp_rate
		
		##################################################
		# Blocks
		##################################################
		self.gr_unpacked_to_packed_xx_0_0 = blocks.unpacked_to_packed_bb(1, gr.GR_LSB_FIRST)
		self.gr_unpacked_to_packed_xx_0 = blocks.unpacked_to_packed_bb(1, gr.GR_LSB_FIRST)
                self.char_to_float = blocks.char_to_float()
                self.float_to_char = blocks.float_to_char()
		self.gr_throttle_0 = blocks.throttle(gr.sizeof_char*1, samp_rate)
		self.gaussnoise_ff_0 = fec.gaussnoise_ff(esno)

		##################################################
		# Connections
		##################################################
		self.connect((self.gr_unpacked_to_packed_xx_0_0, 0), (self, 0))
		self.connect((self.gr_unpacked_to_packed_xx_0, 0), (self, 1))
		self.connect((self.gr_throttle_0, 0), (self.gr_unpacked_to_packed_xx_0, 0))
		self.connect((self.gaussnoise_ff_0, 0), (self.float_to_char, 0))
                self.connect((self.float_to_char, 0), (self.gr_unpacked_to_packed_xx_0_0, 0))
		self.connect(self, (self.gr_throttle_0, 0))
                self.connect((self.gr_throttle_0, 0), (self.char_to_float, 0))
                self.connect((self.char_to_float, 0), (self.gaussnoise_ff_0, 0))

	def get_generic_encoder(self):
		return None

	def set_generic_encoder(self, generic_encoder):
		pass

	def get_generic_decoder(self):
		return None

	def set_generic_decoder(self, generic_decoder):
                pass

	def get_esno(self):
		return self.esno

	def set_esno(self, esno):
		self.esno = esno

	def get_samp_rate(self):
		return self.samp_rate

	def set_samp_rate(self, samp_rate):
		self.samp_rate = samp_rate

	def get_threading(self):
		return None

	def set_threading(self, threading):
		pass

	def get_puncpat(self):
		return None

	def set_puncpat(self, puncpat):
                pass


