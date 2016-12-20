#! /usr/bin/env python
# -*- coding: utf-8 -*-

###
#
# @file lapack.py
#
#  LAPACK is a software package provided by Univ. of Tennessee,
#  Univ. of California Berkeley and Univ. of Colorado Denver
#
# @version 2.3.1
# @author Julie Langou
# @author Mathieu Faverge
# @date 2010-11-15
#
###

from utils import writefile, runShellCommand, killfiles, downloader, getURLName
import sys
import os
import shutil
import framework

class Lapack(framework.Framework):
    lapackurl = "http://www.netlib.org/lapack/lapack.tgz"

    """ This class takes care of the LAPACK installation. """
    def __init__(self, config, netlib):
        print "\n","="*40
        print "  Lapack installation/verification"
        print "="*40

        self.config     = config
        self.downblas = netlib.downblas;
        self.downlapack = netlib.downlapack
        self.downcmd    = netlib.downcmd
        self.prefix     = netlib.prefix
        self.netlib     = netlib

        if self.downblas==1:
           self.config.blaslib=os.path.join(self.prefix,'lib/librefblas.a')

        if self.downlapack == 2:
            self.down_install_lapack()

        ret = self.check_lapack()

        if ret != 0:
            if self.downlapack == 1:
                self.down_install_lapack()
            else:
                print """
Please provide a working LAPACK library. If a LAPACK library is not
present on the system, the netlib LAPACK library can be automatically
downloaded and installed by adding the --downlapack flag.
Most used BLAS implementations already include the LAPACK library as
MKL, ACML, Goto, Goto2 or ATLAS. If you want to use one of these
libraries, you just have to specify correctly the --blaslib option or
you can specify where is located your own LAPACK library by using the
--lapacklib option.

With LAPACK, netlib require also the tmglib from LAPACK which is only
included in MKL and netlib LAPACK (--lapacklib=-ltmg -llapack). For
other BLAS libraries, LAPACK will be automatically downloaded from
netlib.

The LAPACK library is not needed in the case where testing is disabled
by means of the --notesting flag.


What do you want to do ?
    - d : download the netlib LAPACK
    - q : quit and try with another BLAS library or define the
      lapacklib parameter.
                """
                answer = raw_input(">[q] ")
                if answer == "d":
                    self.down_install_lapack()
                else:
                    sys.exit()

    def check_lapack(self):

        if (self.config.lapacklib == ""):
           print "LAPACK library is set to "+self.config.blaslib
        else:
           print "LAPACK library is "+self.config.lapacklib
        print "Checking if provided LAPACK works...",
        # This function simply generates a Fortran program
        # that contains few calls to LAPACK routine and then
        # checks if compilation, linking and execution are succesful

        sys.stdout.flush()
        writefile('tmpf.f',"""

      program ftest
      integer  N
      parameter (N = 1)
      double precision A(N, N), B(N)
      integer  I(N)
      integer  INFO
      B(:)   = 1
      A(:,:) = 2
      I(:)   = 0
      call cheevd( 'N', 'U', N, A, N, B, B, -1,
     $     B, -1, I, -1, INFO)
      stop
      end\n""")

        ldflg = self.config.lapacklib+' '+self.config.blaslib+' '+self.config.ldflags_fc+' -lm'
        ccomm = self.config.fc+' -o tmpf '+'tmpf.f '+ldflg
        (output, error, retz) = runShellCommand(ccomm)

        if(retz != 0):
            if self.netlib.verbose:
                print '\n\nLAPACK: provided LAPACK cannot be used! aborting...'
                print 'error is:\n','*'*40,'\n',ccomm,'\n',error,'\n','*'*40
            else:
                print "no"
            return -1;

        comm = './tmpf'
        (output, error, retz) = runShellCommand(comm)
        if(retz != 0):
            if self.netlib.verbose:
                print '\n\nLAPACK: provided LAPACK cannot be used! aborting...'
                print 'error is:\n','*'*40,'\n',comm,'\n',error,'\n','*'*40
            else:
                print "no"
            return -1;

        killfiles(['tmpf.f','tmpf'])
        print 'yes'

        print "Getting LAPACK version number...",
        # This function simply calls LAPACK ilaver routine and then
        # checks if compilation, linking and execution are succesful

        sys.stdout.flush()
        writefile('tmpf.f',"""

      PROGRAM LAPACK_VERSION
*
      INTEGER MAJOR, MINOR, PATCH
*
      CALL ILAVER ( MAJOR, MINOR, PATCH )
      WRITE(*,  FMT = 9999 ) MAJOR, MINOR, PATCH
*
 9999 FORMAT(I1,'.',I1,'.',I1)
      END\n""")

        ldflg = self.config.lapacklib+' '+self.config.blaslib+' '+self.config.ldflags_fc+' -lm'
        ccomm = self.config.fc+' -o tmpf '+'tmpf.f '+ldflg
        (output, error, retz) = runShellCommand(ccomm)

        if(retz != 0):
            if self.netlib.verbose:
                print 'error is:\n','*'*40,'\n',ccomm,'\n',error,'\n','*'*40
            killfiles(['tmpf.f'])
        else:
          comm = './tmpf'
          (output, error, retz) = runShellCommand(comm)
          if(retz != 0):
            print 'cannot get LAPACK version number.'
            if self.netlib.verbose:
                print 'error is:\n','*'*40,'\n',comm,'\n',error,'\n','*'*40
          else:
            print output,
          killfiles(['tmpf'])

        print "Checking if provided LAPACK contains functions for test works...",
        # This function simply generates a C program
        # that contains few calls to LAPACK routine and then
        # checks if compilation, linking and execution are succesful

        sys.stdout.flush()
        writefile('tmpf.f',"""
      program ftest
        double precision D(1), A(1:1), B(2)
        integer          ISEED( 4 )
        integer          INFO
        B(1)   = 1

        do  I = 1, 4
            ISEED( I ) = 1
        enddo
        call dlarnv( 1, ISEED, 1, D )
        call dlagsy( 1, 0, D, A, 1, ISEED, B, INFO )
        stop
      end\n""")

        ccomm = self.config.fc+' -o tmpf '+'tmpf.f '+ldflg
        (output, error, retz) = runShellCommand(ccomm)

        if(retz != 0):
            print 'no'
            self.netlib.needtmg = 1
        else:
            comm = './tmpf'
            (output, error, retz) = runShellCommand(comm)
            if(retz != 0):
                print 'no'
                self.netlib.needtmg = 1;
            else:
                self.netlib.needtmg = 0;
                print 'yes'
        killfiles(['tmpf.f','tmpf'])

        return 0;


    def down_install_lapack(self):

        print "The reference LAPACK library is being installed."
        sys.stdout.flush()

        savecwd = os.getcwd()

        # creating the build,lib and log dirs if don't exist
        if not os.path.isdir(os.path.join(self.prefix,'lib')):
            os.mkdir(os.path.join(self.prefix,'lib'))

        if not os.path.isdir(os.path.join(os.getcwd(),'log')):
            os.mkdir(os.path.join(os.getcwd(),'log'))

        # Check if lapack.tgz is already present in the working dir
        # otherwise download it
        if not os.path.isfile(os.path.join(os.getcwd(),getURLName(self.lapackurl))):
            print "Downloading reference LAPACK...",
            downloader(self.lapackurl,self.downcmd)
            print "done"

        # unzip and untar
        print 'Unzip and untar reference LAPACK...',
        comm = 'gunzip -f lapack.tgz'
        (output, error, retz) = runShellCommand(comm)
        if retz:
            print '\n\nLAPACK: cannot unzip lapack.tgz'
            print 'stderr:\n','*'*40,'\n',comm,'\n',error,'\n','*'*40
            sys.exit()

        comm = 'tar xf lapack.tar'
        (output, error, retz) = runShellCommand(comm)
        if retz:
            print '\n\nLAPACK: cannot untar lapack.tgz'
            print 'stderr:\n','*'*40,'\n',comm,'\n',error,'\n','*'*40
            sys.exit()
        os.remove('lapack.tar')
        print 'done'

#         # Overwrite [sd]lamch.f
#         shutil.copy(os.path.join(self.netlib.installerdir,'src/dlamch.f'),
#                     os.path.join(os.getcwd(),'lapack-3.3.0/INSTALL'))
#         shutil.copy(os.path.join(self.netlib.installerdir,'src/slamch.f'),
#                     os.path.join(os.getcwd(),'lapack-3.3.0/INSTALL'))

        # change to LAPACK dir
        os.chdir(os.path.join(os.getcwd(),'lapack-3.6.1'))

        # Write Makefile.in
        writefile('make.inc', """
# -*- Makefile -*-
####################################################################
#  LAPACK make include file.                                       #
#  LAPACK, Version 3.3.0                                           #
#  April 2009                                                      #
####################################################################
#
# See the INSTALL/ directory for more examples.
#
SHELL = /bin/sh
#
#  The machine (platform) identifier to append to the library names
#
PLAT = _LINUX
#
#  Modify the FORTRAN and OPTS definitions to refer to the
#  compiler and desired compiler options for your machine.  NOOPT
#  refers to the compiler options desired when NO OPTIMIZATION is
#  selected.  Define LOADER and LOADOPTS to refer to the loader
#  and desired load options for your machine.
#
FORTRAN  = """+self.config.fc+"""
OPTS     = """+self.config.fcflags+"""
DRVOPTS  = $(OPTS)
NOOPT    = """+self.config.noopt+"""
LOADER   = """+self.config.fc+"""
LOADOPTS = """+self.config.ldflags_fc+"""
#
# Timer for the SECOND and DSECND routines
#
# Default : SECOND and DSECND will use a call to the EXTERNAL FUNCTION ETIME
# TIMER    = EXT_ETIME
# For RS6K : SECOND and DSECND will use a call to the EXTERNAL FUNCTION ETIME_
# TIMER    = EXT_ETIME_
# For gfortran compiler: SECOND and DSECND will use a call to the INTERNAL FUNCTION ETIME
# TIMER    = INT_ETIME
# If your Fortran compiler does not provide etime (like Nag Fortran Compiler, etc...)
# SECOND and DSECND will use a call to the Fortran standard INTERNAL FUNCTION CPU_TIME
TIMER    = INT_CPU_TIME
# If neither of this works...you can use the NONE value... In that case, SECOND and DSECND will always return 0
# TIMER     = NONE
#
#  The archiver and the flag(s) to use when building archive (library)
#  If you system has no ranlib, set RANLIB = echo.
#
ARCH     = ar
ARCHFLAGS= """+self.config.arflags+"""
RANLIB   = """+self.config.ranlib+"""
#
#  The location of BLAS library for linking the testing programs.
#  The target's machine-specific, optimized BLAS library should be
#  used whenever possible.
#
BLASLIB      = """+self.config.blaslib+"""
#
#  Location of the extended-precision BLAS (XBLAS) Fortran library
#  used for building and testing extended-precision routines.  The
#  relevant routines will be compiled and XBLAS will be linked only if
#  USEXBLAS is defined.
#
# USEXBLAS    = Yes
XBLASLIB     =
# XBLASLIB    = -lxblas
#
#  Names of generated libraries.
#
LAPACKLIB    = libreflapack.a
TMGLIB       = libtmg.a
EIGSRCLIB    = libeigsrc.a
LINSRCLIB    = liblinsrc.a
""")

        log = " *******  LOG LAPACK *******"
        # compile and generate Reference BLAS library
        if self.downblas==1:
          print 'Compile and generate Reference BLAS...',
          sys.stdout.flush()
          comm = self.make+' blaslib'
          (output, error, retz) = runShellCommand(comm)
          if retz:
            print "\n\nLAPACK: cannot compile Reference BLAS"
            print "stderr:\n","*"*40,"\n",comm,'\n',error,"\n","*"*40
            sys.exit()
          log += output+error
          self.config.blaslib  = '-L'+os.path.join(self.prefix,'lib')+' -lrefblas'
          print 'done'
        
        # compile and generate LAPACK library
        print 'Compile and generate LAPACK...',
        sys.stdout.flush()
        comm = self.make+' lapacklib tmglib'
        (output, error, retz) = runShellCommand(comm)
        if retz:
            print "\n\nLAPACK: cannot compile LAPACK"
            print "stderr:\n","*"*40,"\n",comm,'\n',error,"\n","*"*40
            sys.exit()
        log += output+error
        print 'done'

        # write the log on a file
        fulllog = os.path.join(savecwd,'log/lapacklog')
        writefile(fulllog, log)
        print 'Installation of libreflapack.a successful.'
        print '(log is in ',fulllog,')'

        # move lib to the lib directory
        shutil.copy('libreflapack.a',os.path.join(self.prefix,'lib/libreflapack.a'))
        shutil.copy('libtmg.a',os.path.join(self.prefix,'lib/libtmg.a'))

        # set framework variables to point to the freshly installed LAPACK library
        self.config.lapacklib  = '-L'+os.path.join(self.prefix,'lib')+' -ltmg -lreflapack'

        if(self.netlib.testing == 1):
           print 'Compiling and Running LAPACK test suite (this will take several minutes)...',
           sys.stdout.flush()
           comm = self.make+' lapack_testing'
           (output, error, retz) = runShellCommand(comm)
           if(retz != 0):
               print '\n\nLAPACK: error running LAPACK TESTING SUITE'
               print 'stderr:\n','*'*40,'\n',error,'\n','*'*40
               sys.exit()
           log = output+error
           fulllog = os.path.join(savecwd,'log/lapack_testing')
           writefile(fulllog, log)
           print 'done'
           print '(log is in ',fulllog,')'

        os.chdir(savecwd)

        # Check if the installation is successful
        self.netlib.verbose = 1
        ret = self.check_lapack()
        self.netlib.verbose = 0
        if ret != 0:
            sys.exit()


