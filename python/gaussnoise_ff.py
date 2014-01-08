#!/usr/bin/env python

from gnuradio import gr, blocks, analog
import numpy

class gaussnoise_ff(gr.hier_block2):
    def __init__(self, esno, seed=0):
        gr.hier_block2.__init__(
            self, "Gaussian Noise Adder",
            gr.io_signature(1, 1, gr.sizeof_float),
            gr.io_signature(1, 1, gr.sizeof_float))
                
        self.esno = esno
        self.seed = seed
        self.sigma = 10.0**(-esno/10.0)
        self.sigma = numpy.sqrt(self.sigma/2.0)

        self.noise_source = analog.fastnoise_source_f(analog.GR_GAUSSIAN, 
                                                      self.sigma, self.seed)
        self.adder = blocks.add_ff()

        self.connect((self, 0), (self.adder, 0))
        self.connect(self.noise_source, (self.adder, 1))
        self.connect((self.adder, 0), (self,0))

    def set_esno(self, esno):
        self.esno = esno
        self.sigma = 10.0**(-esno/10.0)
        self.sigma = numpy.sqrt(self.sigma/2.0)
        self.noise_source.set_amplitude(self.sigma)

    def esno(self):
        return self.esno

    def stddev(self):
        return self.sigma

