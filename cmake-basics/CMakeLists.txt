cmake_minimum_required(VERSION 2.8)

# create your own function
function(print_foo)
	MESSAGE("FOO value is ${FOO}")
endfunction()

function(hello_world)
	MESSAGE("Hello World")
endfunction()

set(FOO 10)
print_foo()

# all the functions and variable defined above of this line can be used in the subdirectory as well
add_subdirectory(subdirectory)

# conditional statement
if (${FOO} LESS 2)
	set(FOO 2)
	# calling a function
	print_foo()
else (${FOO} GREATER 3)
	set(FOO 3)
	print_foo()
endif (${FOO} LESS 2)

# this variable can't be used inside subdirectory because this variable is defined after subdirectory inclusion
set(BAR "purple haze")


##################### variable scoping #####################
function(testing)
	MESSAGE("Local test is ${TEST}") # test is 1
	set(TEST 2 PARENT_SCOPE)	 # parent test is 2
	MESSAGE("Local test is ${TEST}") # test is 1
	set(TEST 3)			 # set the test to 3
	MESSAGE("Local test is ${TEST}") # test is 3
endfunction()

set(TEST 1)
testing()
MESSAGE("Global test is ${TEST}") # test will be 2 here

