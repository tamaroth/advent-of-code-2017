##
## CMake configuration for the source files.
##

set(DAYS_SOURCES
	01/inverse_captcha.cc
)

add_library(days SHARED ${DAYS_SOURCES})
target_include_directories(days PUBLIC ${SRC_DIR})
