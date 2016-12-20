#! /usr/bin/env python
# -*- coding: utf-8 -*-

###
#
# @file blas.py
#
#  netlib is a software package provided by Univ. of Tennessee,
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

class Blas:
    blasurl      = "http://netlib.org/blas/blas.tgz"

    """ This class takes care of the BLAS installation. """
    def __init__(self, config, netlib):
        print "\n","="*40
        print "  BLAS installation/verification"
        print "="*40

        self.config  = config
        self.downcmd = netlib.downcmd
        self.prefix  = netlib.prefix
        downblas = netlib.downblas;

        # Checking if the LAPACK provided contains BLAS
        # If this is the case we need to switch the linking order to make sure we take the user BLAS
        if config.lapacklib:
            sauveblaslib=self.config.blaslib
            self.config.blaslib=self.config.lapacklib
            print "Checking if the provided LAPACK ("+self.config.lapacklib+") contains BLAS"
            if self.check_blas()==0:
              self.config.BLAS_in_LAPACK="yes"
              if sauveblaslib!="" or downblas>0:
                if downblas > 1 :
                  blaslib_requested="Download Reference BLAS"
                else:
                  blaslib_requested=sauveblaslib
                print """Which BLAS library do you want to use ?
    - b : the BLAS library you requested: """+blaslib_requested+"""
    - l : the LAPACK library you provided: """+self.config.lapacklib
                answer = raw_input(">[l] ")
                if answer == "b":
                      self.config.blaslib=sauveblaslib
                else:
                    self.config.blaslib=self.config.lapacklib
                    print "Using the BLAS library contained in LAPACK library "+self.config.lapacklib
                    self.config.blaslib=""
                    return;
              else:
                    print "Using the BLAS library contained in LAPACK library "+self.config.lapacklib
                    self.config.blaslib=""
                    return;
              

              
            else:
              self.config.BLAS_in_LAPACK="no"
              self.config.blaslib=sauveblaslib

        if config.blaslib:
            self.check_blas()
        else:
            if downblas==1:
               print "We will take the Reference BLAS provided by the Reference LAPACK library"
            elif downblas==2:
                self.down_install_blas()
            else:
                print """
Please provide a working BLAS library. If a BLAS library
is not present on the system, the reference BLAS library it can be
automatically downloaded and installed by adding the --downblas flag.
Be aware that a reference BLAS library will be installed with the --downblas
flag so don't expect good performance.
You can specify the optimized BLAS library **installed** on your machine using the --blaslib option
For instance
    --blaslib="-lessl" for IBM BLAS,
    --blaslib="-framework veclib" for Mac OS/X,
    --blaslib="-lgoto" for GOTO BLAS
    --blaslib="-lf77blas -lcblas -latlas" for ATLAS
    --blaslib="-lmkl_em64t -lguide" for MKL on emt64 architecture (remember to set environment variable MKL_NUM_THREADS=1)
    --blaslib="-lmkl_intel_lp64 -lmkl_sequential -lmkl_core" for single threaded MKL on 64-bit architectures using Intel compilers
    --blaslib="-lmkl_intel -lmkl_sequential -lmkl_core" for single threaded MKL on 32-bit architectures using Intel compilers
    --blaslib="-lmkl_gf -lmkl_sequential -lmkl_core" for single threaded MKL on 32-bit architectures using GNU Fortran compilers
    etc...
.'
The BLAS library is not needed in the case where testing is disabled
by means of the --notesting flag.
                """
                sys.exit()
                

    def check_blas(self):

        print "BLAS library is set to "+self.config.blaslib
        print "Checking if provided BLAS works...",
        # This function simply generates a FORTRAN program
        # that contains few calls to BLAS routine and then
        # checks if compilation, linking and execution are succesful

        sys.stdout.flush()
        writefile('tmpf.f',"""
      program ftest
      double precision da, dx(1)
      dx(1)=1
      da = 2
      call dscal(1,da,dx,1)
      stop
      end\n""")

        fcomm = self.config.fc+' -o tmpf '+'tmpf.f '+self.config.blaslib+' '+self.config.ldflags_fc+' -lm'
        (output, error, retz) = runShellCommand(fcomm)

        if(retz != 0):
            print '\n\nBLAS: provided BLAS cannot be used! aborting...'
            print 'error is:\n','*'*40,'\n',fcomm,'\n',error,'\n','*'*40
            sys.exit()

        comm = './tmpf'
        (output, error, retz) = runShellCommand(comm)
        if(retz != 0):
            print '\n\nBLAS: provided BLAS cannot be used! aborting...'
            print 'error is:\n','*'*40,'\n',comm,'\n',error,'\n','*'*40
            sys.exit()

        killfiles(['tmpf.f','tmpf'])
        print 'yes'

        return 0;


    def down_install_blas(self):

        print """The reference BLAS library is being installed.
Don't expect high performance from this reference library!
If you want performance, you need to use an optimized BLAS library and,
to avoid unnecessary complications, if you need to compile this optimized BLAS
library, use the same compiler you're using here."""
        sys.stdout.flush()

        savecwd = os.getcwd()

        # creating the build,lib and log dirs if don't exist
        if not os.path.isdir(os.path.join(self.prefix,'lib')):
            os.mkdir(os.path.join(self.prefix,'lib'))

        if not os.path.isdir(os.path.join(os.getcwd(),'log')):
            os.mkdir(os.path.join(os.getcwd(),'log'))

        # Check if blas.tgz is already present in the working dir
        # otherwise download it
        if not os.path.isfile(os.path.join(os.getcwd(),getURLName(self.blasurl))):
            print "Downloading reference BLAS...",
            downloader(self.blasurl,self.downcmd)
            print "done"

        # unzip and untar
        print 'Unzip and untar reference BLAS...',
        comm = 'gunzip -f blas.tgz'
        (output, error, retz) = runShellCommand(comm)
        if retz:
            print '\n\nBLAS: cannot unzip blas.tgz'
            print 'stderr:\n','*'*40,'\n',comm,'\n',error,'\n','*'*40
            sys.exit()

        comm = 'tar xf blas.tar'
        (output, error, retz) = runShellCommand(comm)
        if retz:
            print '\n\nBLAS: cannot untar blas.tgz'
            print 'stderr:\n','*'*40,'\n',comm,'\n',error,'\n','*'*40
            sys.exit()
        os.remove('blas.tar')
        print 'done'

        # change to BLAS dir
        os.chdir(os.path.join(os.getcwd(),'BLAS'))

        # compile and generate library
        print 'Compile and generate reference BLAS...',
        sys.stdout.flush()
        comm = self.config.fc+' '+self.config.fcflags+" -c *.f"
        (output, error, retz) = runShellCommand(comm)
        if retz:
            print "\n\nBLAS: cannot compile blas"
            print "stderr:\n","*"*40,"\n",comm,'\n',error,"\n","*"*40
            sys.exit()

        log = output+error

        comm = "ar cr librefblas.a *.o"
        (output, error, retz) = runShellCommand(comm)
        if retz:
            print "\n\nBLAS: cannot create blas library"
            print "stderr:\n","*"*40,"\n",comm,'\n',error,"\n","*"*40
            sys.exit()

        log = log+output+error

        comm = self.config.ranlib+' librefblas.a'
        (output, error, retz) = runShellCommand(comm)
        if retz:
            print "\n\nBLAS: problem with ranlib"
            print "stderr:\n","*"*40,"\n",comm,'\n',error,"\n","*"*40
            sys.exit()
        print "done"

        # write the log on a file
        log = log+output+error
        fulllog = os.path.join(savecwd,'log/blaslog')
        writefile(fulllog, log)
        print 'Installation of reference BLAS successful.'
        print '(log is in ',fulllog,')'

        # move librefblas.a to the lib directory
        shutil.copy('librefblas.a',os.path.join(self.prefix,'lib/librefblas.a'))

        # set framework variables to point to the freshly installed BLAS library
        self.config.blaslib  = '-L'+os.path.join(self.prefix,'lib')+' -lrefblas '
        os.chdir(savecwd)
