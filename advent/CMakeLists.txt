##
## CMake configuration file for the AdventOfCode program

add_subdirectory(days)
add_subdirectory(utils)

##
## Main executable
##
add_executable(advent main.cc)
target_link_libraries(advent utils days)

