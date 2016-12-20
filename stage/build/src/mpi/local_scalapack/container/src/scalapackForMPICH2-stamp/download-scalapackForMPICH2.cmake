message(STATUS "downloading...
     src='http://www.netlib.org/scalapack/scalapack_installer.tgz'
     dst='/home/gary/programmer/scidbtrunk/stage/build/src/mpi/local_scalapack/container/src/scalapack_installer.tgz'
     timeout='120 seconds'")




file(DOWNLOAD
  "http://www.netlib.org/scalapack/scalapack_installer.tgz"
  "/home/gary/programmer/scidbtrunk/stage/build/src/mpi/local_scalapack/container/src/scalapack_installer.tgz"
  SHOW_PROGRESS
  # no EXPECTED_HASH
  TIMEOUT;120
  STATUS status
  LOG log)

list(GET status 0 status_code)
list(GET status 1 status_string)

if(NOT status_code EQUAL 0)
  message(FATAL_ERROR "error: downloading 'http://www.netlib.org/scalapack/scalapack_installer.tgz' failed
  status_code: ${status_code}
  status_string: ${status_string}
  log: ${log}
")
endif()

message(STATUS "downloading... done")
