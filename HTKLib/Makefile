# ----------------------------------------------------------- 
#                                                             
#                          ___                                
#                       |_| | |_/   SPEECH                    
#                       | | | | \   RECOGNITION               
#                       =========   SOFTWARE                  
#                                                             
#                                                             
# ----------------------------------------------------------- 
#         Copyright: Cambridge University
#          1995-2005 Engineering Department
#                    http://htk.eng.cam.ac.uk
#                    http://mi.eng.cam.ac.uk
#                 
#   Use of this software is governed by a License Agreement   
#    ** See the file License for the Conditions of Use  **    
#    **     This banner notice must not be removed      **    
#                                                             
# ----------------------------------------------------------- 
# File: HTKLib/Makefile.  Generated from Makefile.in by configure.
# ----------------------------------------------------------- 

#  *** THIS IS A MODIFIED VERSION OF HTK ***                        #
# ----------------------------------------------------------------- #
#           The HMM-Based Speech Synthesis System (HTS)             #
#           developed by HTS Working Group                          #
#           http://hts.sp.nitech.ac.jp/                             #
# ----------------------------------------------------------------- #
#                                                                   #
#  Copyright (c) 2001-2008  Nagoya Institute of Technology          #
#                           Department of Computer Science          #
#                                                                   #
#                2001-2008  Tokyo Institute of Technology           #
#                           Interdisciplinary Graduate School of    #
#                           Science and Engineering                 #
#                                                                   #
# All rights reserved.                                              #
#                                                                   #
# Redistribution and use in source and binary forms, with or        #
# without modification, are permitted provided that the following   #
# conditions are met:                                               #
#                                                                   #
# - Redistributions of source code must retain the above copyright  #
#   notice, this list of conditions and the following disclaimer.   #
# - Redistributions in binary form must reproduce the above         #
#   copyright notice, this list of conditions and the following     #
#   disclaimer in the documentation and/or other materials provided #
#   with the distribution.                                          #
# - Neither the name of the HTS working group nor the names of its  #
#   contributors may be used to endorse or promote products derived #
#   from this software without specific prior written permission.   #
#                                                                   #
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND            #
# CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,       #
# INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF          #
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE          #
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS #
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,          #
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED   #
# TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     #
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON #
# ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,   #
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY    #
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           #
# POSSIBILITY OF SUCH DAMAGE.                                       #
# ----------------------------------------------------------------- #

SHELL = /bin/sh
srcdir = .
top_srcdir = ..

prefix = /home/jy.yang/bin/HTS-2.1.1
exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec
datadir = ${prefix}/share
sysconfdir = ${prefix}/etc
sharedstatedir = ${prefix}/com
localstatedir = ${prefix}/var
libdir = ${exec_prefix}/lib
infodir = ${prefix}/info
mandir = ${prefix}/man
includedir = ${prefix}/include
oldincludedir = /usr/include

hlib = .
HLIBS = ${exec_prefix}/lib/HTKLib.a

CC     = gcc
FC     = 
CFLAGS := $(CFLAGS) -I. -ansi -D_SVID_SOURCE -DOSS_AUDIO -D'ARCH="x86_64"' -Wall -Wno-switch -g -O2
FFLAGS := $(FFLAGS) -I.  
RANLIB = ranlib
AR     = ar
INSTALL= /usr/bin/install -c
target = HTKLib.a
objects = HGraf.o esig_asc.o \
	esig_edr.o \
	esignal.o \
	esig_nat.o \
	HAdapt.o \
	HArc.o \
	HAudio.o \
	HDict.o \
	HExactMPE.o \
	HFB.o \
	HFBLat.o \
	HGen.o \
	HLabel.o \
	HLat.o \
	HLM.o \
	HMap.o \
	HMath.o \
	HMem.o \
	HModel.o \
	HNet.o \
	HParm.o \
	HRec.o \
	HShell.o \
	HSigP.o \
	HTrain.o \
	HUtil.o \
	HVQ.o \
	HWave.o \
	strarr.o \
	 \

lvobjects = $(basename HGraf.o).lv.o esig_asc.lv.o \
	esig_edr.lv.o \
	esignal.lv.o \
	esig_nat.lv.o \
	HAdapt.lv.o \
	HArc.lv.o \
	HAudio.lv.o \
	HDict.lv.o \
	HExactMPE.lv.o \
	HFB.lv.o \
	HFBLat.lv.o \
	HLabel.lv.o \
	HLat.lv.o \
	HLM.lv.o \
	HMap.lv.o \
	HMath.lv.o \
	HMem.lv.o \
	HModel.lv.o \
	HNet.lv.o \
	HParm.lv.o \
	HRec.lv.o \
	HShell.lv.o \
	HSigP.lv.o \
	HTrain.lv.o \
	HUtil.lv.o \
	HVQ.lv.o \
	HWave.lv.o \
	strarr.lv.o 

all:	HTKLib.a 

# This is the library used by HTKTools and HLMTools
HTKLib.a: $(objects)
	if [ -f $@ ] ; then  /bin/rm $@ ; fi
	$(AR) rv $@ $^
	$(RANLIB) $@

# This version is used by HDecode (HTKLVRec)
HTKLiblv.a: $(lvobjects)
	if [ -f $@ ] ; then  /bin/rm $@ ; fi
	$(AR) rv $@ $^
	$(RANLIB) $@

%.lv.o: %.c
	$(CC) -DNO_LAT_LM $(CFLAGS) -c -o $@ $<

.PHONY: clean cleanup depend mkinstalldir install

clean:
	-rm -f $(objects) $(lvobjects) HTKLib.a HTKLiblv.a

cleanup:
	-rm -f $(objects) $(lvobjects)

depend:
	-makedepend -Y *.c

distclean: clean
	-rm -f Makefile

install: HTKLib.a HTKLiblv.a  mkinstalldir 
	$(INSTALL) -m 755 HTKLib.a HTKLiblv.a $(libdir)

mkinstalldir:
	-mkdir -p $(libdir)
