##
## CMake configuration for the source files.
##

set(DAYS_SOURCES
	01/inverse_captcha.cc
	02/corruption_checksum.cc
	03/spiral_memory.cc
	04/high_entropy_passphrases.cc
)

add_library(days SHARED ${DAYS_SOURCES})
target_include_directories(days PUBLIC ${SRC_DIR})
