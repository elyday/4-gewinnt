message(STATUS "Building 4 Gewinnt")

set(target eynet_4gewinnt)

set(sources
	4Gewinnt.cpp,
	Functions.h
)

add_executable(${target} ${sources})