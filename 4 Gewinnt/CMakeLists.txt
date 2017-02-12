message(STATUS "Building 4 Gewinnt")

set(target eynet_4gewinnt)

set(sources
	4Gewinnt.cpp,
	Functions.h
)

find_package(OpenCV REQUIRED)
add_executable(${target} ${sources})
target_link_libraries(${target} ${OpenCV_LIBS})