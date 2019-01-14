# CMake

#### Cmake Generators
1. There is single global generator at root level of the project.
2. There are multiple local generators, one for each directory.
3. Global generator is responsible for generating local generators for each directory. This local generator is responsible for generating `MakeFiles` under respective directory.

#### Variables
Multiple argument can be grouped togather using `set` command to create a variable. `set(Foo a b c)` will result in setting `Foo` variable to `a b c`. Variable can be accessed using following command ${VAR}

##### Passing arguments as list using set command
If you want to pass list of argument as a list, then simply pass the variable. `command(${FOO})` will be equivalent to `command(a b c)`.

##### Passing arguments as string using set command
If you want to pass list of argument as a string, then simply double quote the variable. `command("${FOO}")` will be equivalent to `command("a b c")`.


#### Target
Target represent executables, libraries and utilities built by `cmake`. Source files are combined into target. You you can write your own custom target. Every `add_library`, `add_executables`, `add_custom_target` command creates a target.
##### ALL target
ALL is default build target which does execute all the remaining target.
##### Custom target
Custome target can ge written manually. It can be added to the default target (ALL) to execute every time you run `make` command or else it can be invoked manually.
[add_custom_target — CMake 3.0.2 Documentation](https://cmake.org/cmake/help/v3.0/command/add_custom_target.html)

#### Binary Installation

This command generates installation rules for a project. Rules specified by calls to this command within a source directory are executed in order during installation. The order across directories is not defined.

```shell
mkdir _build/
cd _build/
cmake ../ -DCMAKE_INSTALL_PREFIX=<installation_directory>
```
Usage:
```cmake
# this command will move targets to ${CMAKE_INSTALL_PREFIX}/lib directory
install(TARGETS test test2 DESTINATION lib)

# this command will move files to ${CMAKE_INSTALL_PREFIX}/include directory
install(FILES test.h DESTINATION include)
```

#### Static Libraries vs Dynamic/Shared Libraries
Static libraries link to an object file during linking stage of compilation and is incorporated into the final executable file. Since the library code resides within the final executable, the final executable can run independently. But this increases the the file’s size. *And the file would have to be recompiled if changes are made to the library*. Generally, `.a` files are static libraries.
```cmake
# static library
add_libary(lib_common_static STATIC lib/Num.cc lib/Exp.cc)
```

Dynamic libraries are not statically linked to an executable file. They are linked either at loadtime or runtime. Only the memory address is needed in the final executable file as opposed to a copy of the entire library. For this reason, dynamic libraries are smaller in size and do not need to be recompiled if changes are made to the library code. This makes updating a library code much faster and much easier than having to remove and recompile an entire program that uses this library. Dynamically linking allows programs to share a library easily without having to each hold a copy of the code. Generally, `.so` files are dynamic libraries.

```cmake
# shared library
add_libary(lib_common_shared SHARED lib/Num.cc lib/Exp.cc)
```

But because dynamic libraries are not loaded into an executable, the executable is not self-sufficient. This could mean a program would not be able run if the library is not compatible with the current version of a program.

```cmake
# default library. type of library will be determined by BUILD_SHARED_LIBS flag.
# if BUILD_SHARED_LIBS is ON then library will be shared by default else static.
add_libary(lib_common_default lib/Num.cc lib/Exp.cc)
```

[Static Library and Shared Library – Jennifer Huang – Medium](https://medium.com/@jhuang1012bn/static-library-and-shared-library-de6def6b1d3b)





