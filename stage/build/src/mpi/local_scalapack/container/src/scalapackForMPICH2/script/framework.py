#!/usr/bin/python

# -----------------------------------------
# ScaLAPACK installer
# University of Tennessee Knoxville
# October 16, 2007
# ----------------------------------------

from utils import runShellCommand, writefile, killfiles, fixpaths, getURLName
import sys
import os
import getopt
import string

class Framework:
    """ This class takes care of the ScaLAPACK installation. """
    
    # set default values
    prefix       = "./install"               # The install directory
    build        = "./build"                 # The build directory
    make         = 'make'                    # the "make" command
    plat         = 'LINUX'       
    mangling     = ''                        # sets the mangling type for Fortran to C calls
    proxy        = 0 
    downblas     = 0                         # whether or not to download reference blas
    downlapack   = 0                         # whether or not to download reference lapack
    testing      = 1                         # whether on not to compile and run LAPACK and ScaLAPACK test programs
    downcmd      = ''                        # the command used to download stuff
    blasurl      = 'http://netlib.org/blas/blas.tgz'
    lapackurl    = 'http://netlib.org/lapack/lapack.tgz'
    scalapackurl = 'http://netlib.org/scalapack/scalapack.tgz'
    ranlib       = ''                        # the ranlib command
    clean        = 0
    installerdir = ""
    verbose      = 0

    def __init__(self, argv, config):
        
        print '='*40
        print 'Setting up the framework'

        self.config = config
        print 'ScaLAPACK installer version',self.config.version

        # parse input arguments
        self.parse_args(argv)
        
        if self.clean:
            self.cleanup()
            sys.exit()

        if self.prefix == "" :
            self.prefix = "./"
        self.prefix = fixpaths(self.prefix)
        if(not os.path.isdir(self.prefix)):
            print"Creating directory", self.prefix
            os.mkdir(self.prefix)
        print 'Install directory is...', self.prefix
 
        if self.build == "":
            self.build = "./"
        self.build = fixpaths(self.build)
        if(not os.path.isdir(self.build)):
            print"Creating directory",self.build
            os.mkdir(self.build)
        print 'Build directory is...', self.build	

        self.installerdir = os.getcwd()
        os.chdir(self.build)

        if(self.config.mpicc=='' or self.config.mpif90==''):
            #  if no MPI compilers are provided, look for them in mpibindir or in PATH
            if(not self.look_for_mpibinaries()):
                print """
MPI C and Fortran77 compilers are needed  to complete
the installation. You can specify the using the --mpibindir
or the --mpicc and --mpif90 flags."""
                sys.exit()
                
        if((self.config.mpif90 == '') and (self.downlapack == 1)):
            #  if no Fortran compiler is provided, and lapack has to be compiled,
            #  raise an error
            print """
A Fortran compiler is required to install the LAPACK library.
You can specify it using the --mpif90 flag."""
            sys.exit()
                
        if(self.config.mpiincdir==''):
            # the path to the mpi.h file is needed
            if(not self.look_for_mpih()):
                print 'Please provide the location for mpi.h file using the --mpiincdir flag'
                sys.exit()	

        # if testing has to be done, BLAS and LAPACK are required
        if(self.testing == 1):
           if (self.downblas > 1) :
              print 'BLAS library is... REFERENCE BLAS ( To download )'
           elif self.downblas == 1:
              print 'BLAS library is... REFERENCE BLAS ( Taken from REFERENCE LAPACK )'
           else:
              print 'BLAS library is... ', self.config.blaslib

           if (self.downlapack == 2) :
              print 'LAPACK library is... REFERENCE LAPACK ( To download )'
           elif (self.config.lapacklib == ""):
              if (self.downlapack == 1):
                 print 'LAPACK library is... Check if included in Blas Library and dowload if it is not'
              else:
                 print 'LAPACK library is... Check if included in Blas library'
           else:
              print 'LAPACK library is... ', self.config.lapacklib

                 
        # CUSTOM CHECKS
    	self.check_mpicc()
        self.check_mpif90()
        if(self.downlapack>1):
            self.check_f90()
        self.set_mangling()
        self.set_download()
        self.set_ranlib()
        self.detect_compilers()
        self.check_linking()
        
        return


    def usage(self):
          print '='*40
          print """
          ScaLAPACK configuration script
          The script will try to figure out some of the features of your system
          like the mpi compiler and the location of few other tools required for
          the installation of the ScaLAPACK package and the other software
          packages that it requires.
          It is strongly recommended that you help the script by providing info 
          through the flags listed below

          
          -h or --help         : prints this message
 
          --prefix             : path where to create the libraries, build and log of the installer

          --mpibindir=[DIR]    : the path to where the mpi
                                 binaries (mpicc and mpif90)
                                 are contained

          --mpicc=[CMD]        : the mpicc command.
                                 (default: will take the first available mpicc in the path)

          --mpif90=[CMD]       : the mpif90 command.
                                 (default: will take the first available mpif90 in the path)

          --mpirun=[command]   : command to be used for running programs
                                 (default: will take the first available mpirun in the path)

          --mpiincdir=[DIR]    : the path to the directory containing mpi.h
                                 (default: will take the corresponding mpi.h to the mpicc/mpif90 found)

          --ccflags=[FLAGS]    : the flags for the C compiler
                                 (default -O3)

          --fcflags=[FLAGS]    : the flags for the FORTRAN compiler
                                 (default -O3)

          --noopt=[FLAGS]      : compilation flags to be used
                                 on machine dependent subroutines
                                 in LAPACK and ScaLAPACK.
                                 See LAPACK and ScaLAPACK documentation.

          --ldflags_c=[flags]  : loader flags when main program is in C. Some compilers (e.g. PGI) require 
                                 different options when linking C main programs to Fortran subroutines
                                 and vice-versa

          --ldflags_fc=[flags]: loader flags when main program is in Fortran 90/95. Some compilers (e.g. PGI) require 
                                 different options when linking Fortran main programs to C subroutines
                                 and vice-versa

          --makecmd=[CMD]      : the make command
                                 (make by default)

          --blaslib=[LIB]      : a BLAS library
                                 (path should be absolute if --prefix is used)

          --lapacklib=[LIB]    : a LAPACK library
                                 (path should be absolute if --prefix is used)

          --downblas           : if you do not want to provide a BLAS
                                 we can download and install it for you

          --downlapack         : if you do not want to provide a LAPACK
                                 we can download and install it for you

          --downall            : combine --downblas and --downlapack flag

          --notesting          : disables the ScaLAPACK testing. The
                                 BLAS, BLACS and LAPACK libraries are not
                                 required in this case.

          --clean              : cleans up the installer directory.

Note: If you want use a proxy for downloading, the http_proxy environment variable has to be set.
          """
          print '='*40
          sys.exit()
      


    def parse_args(self, argv):
        """ Parse input argument to get compilers etc. from command line. """

        if len(argv) == 1:
            self.usage()
            sys.exit(0)

        try:
          opts, args = getopt.getopt(sys.argv[1:], "h", ["help","prefix=", "build=",
          "ccflags=", "fcflags=", "f90flags=", "noopt=", "arflags=", "make=", "mpibindir=", "mpiincdir=",
          "blaslib=", "lapacklib=", "ldflags_c=", "ldflags_fc=","mpicc=","mpif90=",
          "mpirun=","f90=","downblas", "downlapack", "downall", "verbose", "notesting","clean"])
        except getopt.error, msg:
          print msg
          print "for help use --help"
          sys.exit(2)

        if len(args) > 0 :
            print 'Too many arguments : ', args
            print "for help use --help"
            sys.exit(2);

        # process options
        for o, a in opts:
          if o in ("-h", "--help"):
            self.usage()
            sys.exit(0)
          else:
            if(o == '--clean'):
                self.clean = 1
                return;
            elif o in ('-p', '--prefix'):
                self.prefix = a
            elif o in ('-b', '--build'):
                self.build = a
            elif(o == '--ccflags'):
                self.config.ccflags = a
                print 'C flags are ', a
            elif(o=='--fcflags'):
                self.config.fcflags = a
                print 'Fortran flags are ', a
            elif(o=='--noopt'):
                self.config.noopt = a
                print 'NOOPT flags are ', a
            elif(o=='--make'):
                self.make = a
            elif(o=='--mpibindir'):
                self.config.mpibindir = fixpaths(a)
                print 'MPI bin dir is ', self.config.mpibindir
            elif(o=='--mpiincdir'):
                self.config.mpiincdir = fixpaths(a)
                print 'MPI include dir is ', self.config.mpiincdir
            elif(o=='--mpicc'):
                self.config.mpicc = a
                print 'mpicc is ', a
            elif(o=='--mpif90'):
                self.config.mpif90 = a
                print 'mpif90 is ', a
            elif(o=='--mpirun'):
                self.config.mpirun = a
                print 'mpirun is ', a
            elif (o == '--blaslib'):
                self.config.blaslib = fixpaths(a)
            elif (o == '--lapacklib'):
                self.config.lapacklib = fixpaths(a)
            elif (o == '--downblas'):
                self.downblas = 2
            elif (o == '--downlapack'):
                self.downlapack = 2
            elif (o == '--notesting'):
                self.testing = 0
            elif (o == '--ldflags_c'):
                self.config.ldflags_c = a
            elif (o == '--ldflags_fc'):
                self.config.ldflags_fc = a
            elif o == '--downall':
                self.downblas   = max(1, self.downblas  )
                self.downlapack = max(1, self.downlapack)
            elif o == '--arflags':
                    self.config.arflags = a
            elif (o in ('-v', '--verbose')):
                self.verbose = 1
            else :
                print "Unknown option : ", o
                sys.exit() 

        # Set correctly downloads
        if (((self.config.blaslib == "") and (self.downblas > 0))
            or (self.config.blaslib == "download") ):
            self.config.blaslib = ""
            self.downblas = max(1, self.downblas)
        else :
            self.downblas = 0

        if (((self.config.lapacklib == "") and (self.downlapack > 0))
            or (self.config.lapacklib == "download" )):
            self.config.lapacklib = ""
            self.downlapack = max(1, self.downlapack)
        else :
            self.downlapack = 0

    # look for MPI
    def look_for_mpibinaries(self):
        """ looks for MPI compilers in mpibindir or in PATH """
        # This function is only able to find mpicc/mpif90. If the name of the 
        # compilers are different (like mpixlc or mpixlf) the user must explicitly provide them
        # with the related flags        
        if(self.config.mpibindir != ''):
            # look for mpicc and mpif90 in mpibindir  
            if(os.path.isfile(os.path.join(self.config.mpibindir,'mpicc'))):
                self.config.mpicc = os.path.join(self.config.mpibindir,'mpicc')
                print 'mpicc :',self.config.mpicc
            else:
                print 'Could not find mpif90 in ',self.config.mpibindir
            if(os.path.isfile(os.path.join(self.config.mpibindir,'mpif90'))):
                self.config.mpif90 = os.path.join(self.config.mpibindir,'mpif90')
                print 'mpif90 :',self.config.mpif90
            else:
                print 'Could not find mpif90 in ',self.config.mpibindir,'(user will need to provide a f90 compiler)'
            if(self.config.mpirun==''and os.path.isfile(os.path.join(self.config.mpibindir,'mpirun'))):
            # Check mpirun is in mpibinairies
               self.config.mpirun = os.path.join(self.config.mpibindir,'mpirun')
               print 'mpirun is ',self.config.mpirun
            else:
                print 'Could not find mpirun in ',self.config.mpibindir


        # is mpicc and mpif90 haven't been found
        if(self.config.mpicc=='' and self.config.mpif90==''):

            path=str(os.getenv('PATH')).split(os.pathsep)
            print 'Looking for MPI binaries...',
            sys.stdout.flush()
            for i in path:
                mpicc  = os.path.join(i,'mpicc')
                mpif90 = os.path.join(i,'mpif90')
                mpirun = os.path.join(i,'mpirun')
                if (self.config.mpicc == '' and os.path.isfile(mpicc)):
                    self.config.mpicc = mpicc
                if (self.config.mpif90 == '' and os.path.isfile(mpif90)):
                    self.config.mpif90 = mpif90
                if (self.config.mpirun == '' and os.path.isfile(mpirun)):
                    self.config.mpirun = mpirun
            if (self.config.mpicc!='' or self.config.mpif90!='' or self.config.mpirun!=''):
                print "mpicc, mpif90 and mpirun found.\nmpicc : "+self.config.mpicc+"\nmpif90 :"+self.config.mpif90+"\nmpirun :"+self.config.mpirun
                return 1;           
            elif (self.config.mpicc=='' or self.config.mpif90==''):
                print """
The information about the location of MPI commands is incomplete.
Please, either provide the path to the directory containing mpicc,
mpif90 and mpirun with the --mpibindir flag or the full path to both 
commands with the --mpicc AND --mpif90 flags. In case none of these
flags are provided, the installer will look for mpicc, mpif90 and mpirun
in the PATH environment variable.
"""
                return 0;

        return 1;




    def look_for_mpih(self):
        """ looks for mpi.h close to mpibindir """
      
        print 'Looking for mpi.h...',
        for i in [self.config.mpibindir[0:self.config.mpibindir.find('bin')], self.config.mpicc[0:self.config.mpicc.find('bin')], self.config.mpif90[0:self.config.mpif90.find('bin')]]:
            sys.stdout.flush()
            tmp = i+'include'
            if(os.path.isfile(os.path.join(tmp,'mpi.h'))):
                self.config.mpiincdir = tmp
                print 'found in '+i+'include'
                return 1;

        print 'not found'

        return 0;


            
    def check_mpicc(self):
        """ checks if mpicc works """
        # simply generates a C program containing a couple of calls
        # to MPI routines and checks if the compilation and execution
        # are succesful
        print 'Checking if mpicc works...',
        sys.stdout.flush()
        # generate
        writefile('tmpc.c',"""
            #include \"mpi.h\"
            #include <stdio.h>
            int main(int argc, char **argv){
            int iam;
            MPI_Init( &argc, &argv );
            MPI_Comm_rank( MPI_COMM_WORLD, &iam );
            if(iam==0){fprintf(stdout, \"success\" );fflush(stdout);}
            MPI_Finalize();
            return 0;
            }\n""")

        # compile
        ccomm = self.config.mpicc+' '+self.config.ccflags+' -o tmpc '+os.path.join(os.getcwd(),'tmpc.c')
        (output, error, retz) = runShellCommand(ccomm)
      
        if retz:
            print '\n\nCOMMON: mpicc not working! aborting...'
            print 'stderr:\n','*'*40,'\n',error,'\n','*'*40
            sys.exit()
        print 'yes'
        
        """ checks if mpirun works """
        print 'Checking if mpirun works...',
        sys.stdout.flush()
        # run
        #comm = self.config.mpirun + ' ./tmpc'
        #(output, error, retz) = runShellCommand(comm)
        #if retz:
        #    print '\n\nCOMMON: mpirun not working! aborting...'
        #    print 'error is:\n','*'*40,'\n',error,'\n','*'*40
        #    sys.exit()

        # cleanup
        killfiles(['tmpc.c','tmpc'])
        print 'yes'
        return 0;



    def check_mpif90(self):
        """ check if mpif90 works """
        # simply generates a f90 program containing a couple of calls
        # to MPI routines and checks if the compilation and execution
        # are succesful
        print 'Checking if mpif90 works...',
        sys.stdout.flush()
        # generate        
        writefile('tmpf.f',"""
      program ftest
      include 'mpif.h'
      integer Iam, i, ierr
      call mpi_init(ierr)
      call mpi_comm_rank(MPI_COMM_WORLD, Iam, ierr)
      if (Iam .eq. 0) then
            print*,'success'
      end if
      call mpi_finalize(ierr)
      stop
      end\n""")

        # compile
        #fcomm = self.config.mpif90+' '+self.config.fcflags+' -o tmpf '+'tmpf.f'
        #(output, error, retz) = runShellCommand(fcomm)

        #if retz:
        #    print '\n\nCOMMON: mpif90 not working! aborting...'
        #    print 'error is:\n','*'*40,'\n',error,'\n','*'*40
        #    sys.exit()
        
        # run
        #comm = self.config.mpirun + ' ./tmpf'
        #(output, error, retz) = runShellCommand(comm)
        #if retz:
        #    print '\n\nCOMMON: mpif90 not working! aborting...'
        #    print 'error is:\n','*'*40,'\n',error,'\n','*'*40
        #    sys.exit()

        # cleanup        
        killfiles(['tmpf.f','tmpf','tmpf.o'])
        print 'yes'

        return 0;
        

    def check_f90(self):
        """ check if the Fortran 90/95 compiler works """
        # simply generates a F90 program and checks if the compilation and execution
        # are succesful
        print 'Checking if the Fortran 90/95 compiler works...',
        sys.stdout.flush()
        # generate        
        writefile('tmpf.f90',"""
program testf90
   integer, pointer :: a(:)
   allocate(a(10))
   a(:)=1
   deallocate(A)
   stop
end program testf90\n""")

        # compile
        fcomm = self.config.mpif90+' '+self.config.fcflags+' -o tmpf '+'tmpf.f90'
        (output, error, retz) = runShellCommand(fcomm)

        if retz:
            print '\n\nCOMMON: the Fortran 90/95 compiler is not working! aborting...'
            print 'error is:\n','*'*40,'\n',error,'\n','*'*40
            sys.exit()
        
        # run
        comm = './tmpf'
        (output, error, retz) = runShellCommand(comm)
        if retz:
            print '\n\nCOMMON: the Fortran 90/95 compiler is not working! aborting...'
            print 'error is:\n','*'*40,'\n',error,'\n','*'*40
            sys.exit()

        # cleanup        
        killfiles(['tmpf.f90','tmpf','tmpf.o'])
        print 'yes'

        return 0;
        

    def set_mangling(self):
        """ Sets the INTFACE variable in Bmake.inc """
        # Checks the mangling in FORTRAN function symbols
        print 'Setting Fortran mangling...',
        sys.stdout.flush()
        writefile('tmpf.f',"""
      program intface
      external c_intface
      integer i
      call c_intface(i)
      stop
      end\n""")
        writefile('tmpc.c',"""
      #include <stdio.h>
      void c_intface_(int *i){fprintf(stdout, \"-DAdd_\");fflush(stdout);}
      void c_intface(int *i){fprintf(stdout, \"-DNoChange\");fflush(stdout);}
      void c_intface__(int *i){fprintf(stdout, \"-Df90IsF2C\");fflush(stdout);}
      void C_INTFACE(int *i){fprintf(stdout, \"-DUpCase\");fflush(stdout);}\n""")

        ccomm = self.config.mpicc+' '+self.config.ccflags+' -c tmpc.c -o tmpc.o'
        fcomm = self.config.mpif90+' '+self.config.fcflags+' tmpf.f tmpc.o -o xintface'

        (output, error, retz) = runShellCommand(ccomm)
        if retz:
            print '\n\nCOMMON: in set_mangling: cannot compile'
            print 'error is:\n','*'*40,'\n',error,'\n','*'*40
            sys.exit()

        (output, error, retz) = runShellCommand(fcomm)
        if retz:
            print '\n\nCOMMON: in set_mangling: cannot compile'
            print 'error is:\n','*'*40,'\n',error,'\n','*'*40
            sys.exit()

        comm = os.path.join(os.getcwd(),'xintface')
        (output, error, retz) = runShellCommand(comm)
        if retz:
            print '\n\nCOMMON: in set_mangling: cannot run xintface'
            print 'error is:\n','*'*40,'\n',error,'\n','*'*40
            sys.exit()

        self.mangling = output
        killfiles(['xintface', 'tmpf.f', 'tmpf.o', 'tmpc.c', 'tmpc.o'])
        
        print self.mangling
        return 1;


    def check_linking(self):
        """ Check if C main can be linked to f90 subroutine """

        # This one checks if the linking command works out of the box or
        # if any specific flag is required. For example if the linker if the
        # Intel FORTRAN compiler, then the "-nofor_main" is usually required.
        # This function only checks if linker works but does not automatically
        # detect the required flags
        print 'Checking loader...',
        sys.stdout.flush()
        writefile('tmpf.f',"""
      subroutine fsub()
      write(*,*)'success'
      stop
      end\n""")
        writefile('tmpc.c',"""
      #if defined Add_
      #define fsub fsub_
      #elif defined NoChange
      #define fsub fsub
      #elif defined f90IsF2C
      #define fsub fsub_
      #elif defined UpCase
      #define fsub FSUB
      #endif
      void main(){
      fsub();}\n""")

        ccomm = self.config.mpicc+' '+self.config.ccflags+' '+self.mangling+' -c -o tmpc.o tmpc.c'
        fcomm = self.config.mpif90+' '+self.config.fcflags+' -c -o tmpf.o tmpf.f'
        lcomm = self.config.mpif90+' '+self.config.ldflags_fc+' -o lnk tmpf.o tmpc.o'
      
        (output, error, retz) = runShellCommand(ccomm)
        if retz:
            print '\n\nCOMMON: in check_linking: cannot compile'
            print 'command is: ',ccomm
            print 'error is:\n','*'*40,'\n',error,'\n','*'*40
            sys.exit()

        (output, error, retz) = runShellCommand(fcomm)
        if retz:
            print '\n\nCOMMON: in check_linking: cannot compile'
            print 'command is: ',fcomm
            print 'error is:\n','*'*40,'\n',error,'\n','*'*40
            sys.exit()

        (output, error, retz) = runShellCommand(lcomm)
        if retz:
            print """\n\nCOMMON: in check_linking: cannot link
            Cannot link a C main program to a Fortran77 subroutine
            Make sure that the appropriate flags are passed to the linker."""
            print 'command is: ',lcomm
            print 'error is:\n','*'*40,'\n',error,'\n','*'*40
            sys.exit()


        killfiles(['lnk', 'tmpf.f', 'tmpf.o', 'tmpc.c', 'tmpc.o'])
        
        print 'works'
        return 1;


          
    def set_download(self):
        """ Figures out how to download files """
        print 'Setting download command...'
        wget = 0
        urllib = 0
        # look for proxy setting in the environnement variables
        proxy_http=str(os.getenv('http_proxy'))
        # if proxy_http found in the environnement, we are going to use wget as download command
        if (proxy_http != 'None'):
            self.proxy=1
            urllib=0
        else:    
            try:
                # check if the urllib2 module is included in the
                # python installation. If yes files are downloaded with urllib2            
                print "Checking availability of urllib...",
                import urllib2
                urllib=1
                print "available"
                print "Testing urllib...",
                try:
                    name = getURLName('http://www.netlib.org/lapack/index')
                    url = urllib2.urlopen('http://www.netlib.org/lapack/index')
                    f = open(name,'w')
                    for line in url.readlines():
                        f.write(line)
                    url.close()
                    f.close()
                except:
                    print "not working"
                    urllib = -1
                else:
                    print "working"
                    self.downcmd = 'urllib2'
                    os.remove('index')
                    return
            except ImportError:
                print "not available"
                urllib=0

        if(urllib <= 0):
            # if urllib2 is not present checks if wget is present
            # in the PATH and if yes it sets the download command
            # to be wget
            print "Checking availablility of wget...",
            path=str(os.getenv('PATH')).split(os.pathsep)
            for i in path:
                if (os.path.isfile(os.path.join(i,'wget'))):
                    print "available"
                    wget = 1
                    break

            if(wget == 1):
                # test wget
                if (proxy_http != 'None'):
                    print "Testing wget through the "+proxy_http+" proxy...",
                else:
                    print "Testing wget...",
                try:
                    comm = 'wget http://www.netlib.org/lapack/index'
                    (output, error, retz) = runShellCommand(comm)
                    if(retz != 0):
                        raise
                except:
                    print 'not working.'
                    wget = -1
                else:
                    print 'working'
                    self.downcmd='wget'
                    os.remove('index')
                    return
            else:
                # wget not available
                print "not available"
                wget=0


    def set_ranlib(self):
        """ Sets the ranlib command """
        # Some systems don't have the ranlib command (e.g. SGIs).
        # In the case where ranlib is not present in the PATH,
        # echo is used instead of ranlib
        print "Setting ranlib command...",

        path=str(os.getenv('PATH')).split(os.pathsep)
        for i in path:
            if os.path.isfile(os.path.join(i,'ranlib')):
                self.config.ranlib=os.path.join(i,'ranlib')
                print self.config.ranlib
                return

        for i in path:
            if os.path.isfile(os.path.join(i,'echo')):
                self.config.ranlib=os.path.join(i,'echo')
                print self.config.ranlib
                return





    def detect_compilers(self):
        """ Tries to detect the compilers type """
        # By users experience it is known which compiler flags are required
        # in some cases. This function tries to detect which compilers are used
        # and sets the flags accordingly

        print 'Detecting Fortran compiler...',
        if (self.fc_is_intel()):
            # The Intel FORTRAN compiler requires -nofor_main flag
            # for the linking and the -mp flag to maintain the 
            # floating-point precision
            self.config.ldflags_c   += ' -nofor_main'
            self.config.ldflags_fc += ''
            self.config.noopt += ' -mp'
            print 'Intel'
        elif (self.fc_is_gnu()):
            print 'GNU'
        elif (self.fc_is_pgi()):
            self.config.ldflags_c   += ' -Mnomain'
            self.config.ldflags_fc += ''
        else:
            print 'unknown'

        print 'Detecting C compiler...',
        if (self.cc_is_intel()):
            print 'Intel'
        elif (self.cc_is_gnu()):
            print 'GNU'
        elif (self.cc_is_pgi()):
            print 'PGI'
        else:
            print 'unknown'


        print 'C flags are... ', self.config.ccflags
        print 'Fortran flags are... ', self.config.fcflags
        print 'Selected loader flags (C main): '+self.config.ldflags_c
        print 'Selected loader flags (f90 main): '+self.config.ldflags_fc
        print 'Selected NOOPT flags: '+self.config.noopt
        print 'AR flags are... ', self.config.arflags

        return


    def fc_is_intel(self):
        comm = self.config.mpif90+' -V'
        (output, error, retz) = runShellCommand(comm)
        isifort = string.find(error,'Intel(R) Fortran')
        if (isifort != -1):
            return 1

        return 0


    def fc_is_gnu(self):
        comm = self.config.mpif90+' --help'
        (output, error, retz) = runShellCommand(comm)
        isifort = string.find(output,'gnu.org')
        if (isifort != -1):
            return 1

        return 0

    def fc_is_pgi(self):
        comm = self.config.mpif90+' -V'
        (output, error, retz) = runShellCommand(comm)
        isifort = string.find(error,'pgif90')
        if (isifort != -1):
            return 1
        isifort = string.find(error,'pgif90')
        if (isifort != -1):
            return 1
        isifort = string.find(error,'pgif95')
        if (isifort != -1):
            return 1
        isifort = string.find(error,'Portland')
        if (isifort != -1):
            return 1
        isifort = string.find(output,'pgif90')
        if (isifort != -1):
            return 1
        isifort = string.find(output,'pgif90')
        if (isifort != -1):
            return 1
        isifort = string.find(output,'pgif95')
        if (isifort != -1):
            return 1
        isifort = string.find(output,'Portland')
        if (isifort != -1):
            return 1

        return 0



    def cc_is_intel(self):
        comm = self.config.mpicc+' -V'
        (output, error, retz) = runShellCommand(comm)
        isifort = string.find(error,'Intel(R) C')
        if (isifort != -1):
            return 1

        return 0


    def cc_is_gnu(self):
        comm = self.config.mpicc+' --help'
        (output, error, retz) = runShellCommand(comm)
        isifort = string.find(output,'gnu.org')
        if (isifort != -1):
            return 1

        return 0
        

    def cc_is_pgi(self):
        comm = self.config.mpicc+' -V'
        (output, error, retz) = runShellCommand(comm)
        isifort = string.find(error,'pgicc')
        if (isifort != -1):
            return 1
        isifort = string.find(error,'Portland')
        if (isifort != -1):
            return 1
        isifort = string.find(output,'pgicc')
        if (isifort != -1):
            return 1
        isifort = string.find(output,'Portland')
        if (isifort != -1):
            return 1

        return 0


    def resume(self):
        
        cwd = os.getcwd()
        print """
******************************************************
******************************************************

ScaLAPACK installation completed.


Your BLAS library is                     : """+self.config.blaslib+"""\n
Your LAPACK library is                   : """+self.config.lapacklib+"""\n
Your BLACS/ScaLAPACK library is          : """+self.config.scalapacklib+"""

Log messages are in the\n"""+os.path.join(cwd,'log')+""" directory.
"""
        if(self.testing == 0):
           print "The ScaLAPACK testing programs are in:\n"+os.path.join(cwd,'build/scalapack-2.0.0/TESTING')
        else:
           print "The ouput of ScaLAPACK testing programs are in:\n"+os.path.join(cwd,'log/sca_testing')

        print """
The\n"""+self.build+"""
directory contains the source code of the libraries 
that have been installed. It can be removed at this time.
          

******************************************************
******************************************************
"""



    def cleanup(self):
        """ Cleans up the installer directory """

        print "Cleaning up...",
        sys.stdout.flush()
        
        builddir = os.path.join(self.build)

        comm = 'rm -rf '+builddir
        #+' '+libdir+' '+logdir
        (output, error, retz) = runShellCommand(comm)
        
        print "done."
