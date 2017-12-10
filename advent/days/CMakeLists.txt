##
## CMake configuration for the source files.
##

set(DAYS_SOURCES
	01/inverse_captcha.cc
	02/corruption_checksum.cc
	03/spiral_memory.cc
	04/high_entropy_passphrases.cc
	05/maze.cc
	06/memory_reallocation.cc
	07/recursive_circus.cc
	08/registers.cc
	09/stream_processing.cc
)

add_library(days SHARED ${DAYS_SOURCES})
target_include_directories(days PUBLIC ${SRC_DIR})
target_link_libraries(days PUBLIC boost)

##
## Copy input files for certain days
##

## Day 04 input
add_custom_command(TARGET days POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
		${SRC_DIR}/advent/days/04/day_04_input.txt ${PROJECT_BINARY_DIR})

## Day 05 input
add_custom_command(TARGET days POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
		${SRC_DIR}/advent/days/05/day_05_input.txt ${PROJECT_BINARY_DIR})

## Day 07 input
add_custom_command(TARGET days POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
		${SRC_DIR}/advent/days/07/day_07_input.txt ${PROJECT_BINARY_DIR})

## Day 08 input
add_custom_command(TARGET days POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
		${SRC_DIR}/advent/days/08/day_08_input.txt ${PROJECT_BINARY_DIR})

## Day 08 input
add_custom_command(TARGET days POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
		${SRC_DIR}/advent/days/09/day_09_input.txt ${PROJECT_BINARY_DIR})
