##
## CMake configuration file for the AdventOfCode program

add_subdirectory(days)
add_subdirectory(utils)

##
## Main executable
##
add_executable(advent main.cc)
target_include_directories(advent PUBLIC ${SRC_DIR})
target_link_libraries(advent PUBLIC
	utils
	days
)
