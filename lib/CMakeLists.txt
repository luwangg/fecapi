# Copyright 2011 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

########################################################################
# Setup library
########################################################################

add_library(fec SHARED
  generic_decoder.cc
  generic_encoder.cc
  cc_decoder_impl.cc
  cc_encoder_impl.cc
)

target_link_libraries(fec 
  ${Boost_LIBRARIES} 
  volk_fecapi
)
set_target_properties(fec PROPERTIES DEFINE_SYMBOL "fec_EXPORTS")

IF(${CAN_HAS_GNURADIO} STREQUAL 'YESS!')
  include(GrPlatform) #define LIB_SUFFIX
  include(GrPython)
  GR_PYTHON_CHECK_MODULE("PyQt4" PyQt4 True PYQT4_FOUND)

  add_library(gr-fec SHARED
    libbertools.cc
    fec_encoder_impl.cc
    fec_decoder_impl.cc
    fec_ber_bf_impl.cc
    fec_corr_bb_impl.cc
    fec_deinterleave_impl.cc
    fec_interleave_impl.cc
    fec_puncture_ff_impl.cc
    fec_random_gen_b_impl.cc
    fec_reinflate_bb_impl.cc
    ber_sink_b_impl.cc
    )

  target_link_libraries(gr-fec 
    ${Boost_LIBRARIES} 
    ${VOLK_LIBRARIES}
    ${QT_LIBRARIES}
    ${QWT_LIBRARIES}
    ${GNURADIO_RUNTIME_LIBRARIES}
    ${GNURADIO_QTGUI_LIBRARIES}
    ${GNURADIO_FFT_LIBRARIES}
    volk_fecapi
    fec
    )
  set_target_properties(gr-fec PROPERTIES DEFINE_SYMBOL "fec_EXPORTS")
    
ENDIF()

########################################################################
# Install info files for Python
########################################################################
install(FILES 
  DESTINATION ${GR_PYTHON_DIR}/fec
)

########################################################################
# Install built library files
########################################################################
install(TARGETS fec
    LIBRARY DESTINATION lib${LIB_SUFFIX} # .so/.dylib file
    ARCHIVE DESTINATION lib${LIB_SUFFIX} # .lib file
    RUNTIME DESTINATION bin              # .dll file
)

IF(${CAN_HAS_GNURADIO} STREQUAL 'YESS!')
    install(TARGETS gr-fec
        LIBRARY DESTINATION lib${LIB_SUFFIX} # .so/.dylib file
        ARCHIVE DESTINATION lib${LIB_SUFFIX} # .lib file
        RUNTIME DESTINATION bin              # .dll file
        )
ENDIF()

########################################################################
# Build and register unit test
########################################################################
find_package(Boost COMPONENTS unit_test_framework)

IF(${CAN_HAS_GNURADIO} STREQUAL 'YESS!')
    include(GrTest)
    set(GR_TEST_TARGET_DEPS gr-fec)
ENDIF()
#turn each test cpp file into an executable with an int main(t) function
add_definitions(-DBOOST_TEST_DYN_LINK -DBOOST_TEST_MAIN)

