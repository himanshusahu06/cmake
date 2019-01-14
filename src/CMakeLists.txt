cmake_minimum_required(VERSION 2.8)
include(../CMakeLists.txt.common)

add_library(lib_common SHARED lib/Num.cc lib/Exp.cc)

# type of libraries will be shared if BUILD_SHARED_LIBS flag is ON
add_library(lib_common_default lib/Num.cc lib/Exp.cc)
