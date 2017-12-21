##
## CMake configuration file for tests.
##

include(gtest)

set(TESTS_SOURCES
	main.cc
	day_01_tests.cc
	day_02_tests.cc
	day_03_tests.cc
	day_04_tests.cc
	day_05_tests.cc
	day_06_tests.cc
	day_07_tests.cc
	day_08_tests.cc
	day_09_tests.cc
	day_10_tests.cc
	day_11_tests.cc
	day_12_tests.cc
	day_13_tests.cc
	day_14_tests.cc
	day_15_tests.cc
	day_16_tests.cc
	day_17_tests.cc
	day_18_tests.cc
	day_19_tests.cc
	day_20_tests.cc
	day_21_tests.cc
)

add_executable(tests ${TESTS_SOURCES})
target_include_directories(tests PUBLIC "${PROJECT_SOURCE_DIR}")
target_link_libraries(tests PUBLIC
	utils
	days
	gtest
)
install(TARGETS tests DESTINATION "${INSTALL_BIN_DIR}/tests")
