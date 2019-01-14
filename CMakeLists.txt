# set executable directory path - all add_executable output will go to this directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/bin)
# set library directory path
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/lib)

add_executable(HelloWorld src/HelloWorld.cc)

# method 1 : specify all the files here
set(Main_dependency_list src/Main.cc src/lib/Num.cc src/lib/Exp.cc)
add_executable(Main ${Main_dependency_list})
