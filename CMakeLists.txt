cmake_minimum_required(VERSION 2.8)

# set executable directory path - all add_executable output will go to this directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/bin)

# set library directory path
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/lib)

add_executable(HelloWorld src/HelloWorld.cc)

# method 1 : specify all the files here
set(Main_dependency_list src/Main.cc src/lib/Num.cc src/lib/Exp.cc)
add_executable(Main ${Main_dependency_list})

# this is how you define a custom target and that can be found at `make help`
# this target will not be invoked by default build target
add_custom_target(realclean
	COMMAND rm -rf build/ cmake_install.cmake CMakeCache.txt CMakeFiles/)

# this is also a custome target but it has been added to default target ALL
# If the ALL option is specified it indicates that this target should be added to the default
# build target so that it will be run every time (the command cannot be called ALL).
add_custom_target(echoname ALL
	COMMAND echo "-------------\n"
	COMMAND echo "Himanshu Sahu"
	COMMAND echo "-------------\n")
