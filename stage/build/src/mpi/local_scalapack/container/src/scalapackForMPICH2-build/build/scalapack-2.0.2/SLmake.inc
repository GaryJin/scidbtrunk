
#
#  C preprocessor definitions:  set CDEFS to one of the following:
#
#     -DNoChange (fortran subprogram names are lower case without any suffix)
#     -DUpCase   (fortran subprogram names are upper case without any suffix)
#     -DAdd_     (fortran subprogram names are lower case with "_" appended)

CDEFS         = -DAdd_

#
#  The fortran and C compilers, loaders, and their flags
#

FC            = /opt/scidb/15.7/3rdparty/mpich2/bin/mpif90
CC            = /opt/scidb/15.7/3rdparty/mpich2/bin/mpicc
NOOPT         = -fPIC -g -O0
FCFLAGS       = -O2
CCFLAGS       = -O2
SRCFLAG       =
FCLOADER      = $(FC)
CCLOADER      = $(CC)
FCLOADFLAGS   = 
CCLOADFLAGS   = 

#
#  The archiver and the flag(s) to use when building archive (library)
#  Also the ranlib routine.  If your system has no ranlib, set RANLIB = echo
#

ARCH          = ar
ARCHFLAGS     = cr
RANLIB        = /usr/bin/ranlib

#
#  The name of the ScaLAPACK library to be created
#

SCALAPACKLIB  = libscalapack.a

#
#  BLAS, LAPACK (and possibly other) libraries needed for linking test programs
#

BLASLIB       = 
LAPACKLIB     = /usr/lib64/liblapack.so /usr/lib64/libblas.so /usr/lib64/libblas.so 
LIBS          = $(LAPACKLIB) $(BLASLIB)
        