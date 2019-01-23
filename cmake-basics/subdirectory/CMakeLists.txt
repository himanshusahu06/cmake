cmake_minimum_required(VERSION 2.8)

hello_world()
MESSAGE("In subdirectory, value of FOO is ${FOO}")

if(DEFINED BAR)	# that's how you check whether a variable is defined or not
	MESSAGE("In subdirectory, value of BAR is ${BAR}")
else()
	MESSAGE("In subdirectory, BAR is undefined")
endif(DEFINED BAR)
