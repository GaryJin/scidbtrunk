#! /usr/bin/env python
# -*- coding: utf-8 -*-

class Config:
	# set default values

# PLASMA
  blaslib     = ""                # the BLAS library
  cblaslib    = ""                # the CBLAS library
  lapacklib   = ""                # the Lapack library
  lapclib     = ""                # the Lapack C interface
  lapackinc   = ""                # the Lapack headers
  cc          = "cc"              # the C compiler for plasma
  fc          = "gfortran"        # the Fortran compiler for core_lapack
  ranlib      = ""                # Ranlib
  arflags     = "rc"              # ar flags
  ldflags_c   = ""                # loader flags when main program is in C
  ldflags_fc  = ""                # loader flags when main program is in Fortran
  ccflags     = "-O2"
  fcflags     = "-O2"
  noopt       = "-O0"

# ScaLAPACK
  mpibindir = ''                           # directory containing mpicc and mpif77
  mpiincdir = ''                           # directory containing mpi.h
  mpicc, mpif90 = ['', '']                 # the mpicc and mpif77 commands
  mpirun       = ''                        # the command for running mpi programs
  scalapacklib = ''                        # scalapack library

  def __init__(self, version):
    self.version = version
