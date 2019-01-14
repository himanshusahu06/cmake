cmake_minimum_required(VERSION 2.8)

set(BUILD_SHARED_LIBS ON)

include(CMakeLists.txt.common)

add_executable(HelloWorld src/HelloWorld.cc)

# method 1 : specify all the files here
set(Main_dependency_list src/Main.cc src/lib/Num.cc src/lib/Exp.cc)
add_executable(Main ${Main_dependency_list})

# method 2: use library which has been created from some other makefile
add_executable(Main2 src/Main.cc)
target_link_libraries(Main2 lib_common)

# also you need to link the sub directory
add_subdirectory(src)

# this is also a custome target but it has been added to default target ALL
# If the ALL option is specified it indicates that this target should be added to the default
# build target so that it will be run every time (the command cannot be called ALL).
add_custom_target(echoname ALL
	COMMAND echo "This is custom target written by Himanshu Sahu and running by default.")

# this is how you define a custom target and that can be found at `make help`
# this target will not be invoked by default build target
add_custom_target(realclean
         COMMAND rm -rf $(CURDIR)/build/)

# install tells cmake to install our binary into the bin directory of the install directory.
# install command is useful when you want to install binaries to a directory because make command
# simply install the binaries in the source directory.
# this command will install binaries to /usr/local/bin directory
# you can also specify base path for installation during cmake like this `cmake . -DCMAKE_INSTALL_PREFIX=_install`
# this will install binaries to ./_install/bin directory
install(TARGETS Main DESTINATION bin)
