##
## CMake configuration file for the AdventOfCode program

add_subdirectory(days)
add_subdirectory(utils)

##
## Main executable
##
add_executable(advent main.cc)
target_link_libraries(advent utils days)

##
## Copy input files for certain days
##
add_custom_command(TARGET advent POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
		${CMAKE_SOURCE_DIR}/advent/days/04/day_04_input.txt ${PROJECT_BINARY_DIR})
