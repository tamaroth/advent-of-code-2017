##
## CMake configuration file for Day01
##

set(AOC_D01_SOURCES
	inverse_captcha.cc
)
add_library(day01 SHARED ${AOC_D01_SOURCES})
target_include_directories(day01 PUBLIC ${SRC_DIR})
