##
## CMake configuration file for utilities.
##

set(UTILS_SOURCES
	base.cc
	solutions.cc
)
add_library(utils SHARED ${UTILS_SOURCES})
target_include_directories(utils PUBLIC ${SRC_DIR})
