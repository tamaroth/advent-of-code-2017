##
## The project's main CMake configuration file.
##

cmake_minimum_required(VERSION 3.6)

project(adventofcode CXX C)

##
## Settings.
##

# Build type.
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(IS_DEBUG_BUILD "YES")
	set(IS_RELEASE_BUILD "NO")
else()
	set(IS_DEBUG_BUILD "NO")
	set(IS_RELEASE_BUILD "YES")
endif()

# Name of the used C++ compiler.
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(CXX_COMPILER_NAME "gcc")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set(CXX_COMPILER_NAME "clang")
else()
	message(ERROR "unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

# Version of the used C++ compiler.
execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
	OUTPUT_VARIABLE CXX_COMPILER_VERSION)

##
## Paths.
##

# All our CMake modules are in the 'cmake' subdirectory.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/advent/cmake")

set(SRC_DIR "${CMAKE_SOURCE_DIR}")
set(BINARY_SRC_DIR "${PROJECT_BINARY_DIR}")
set(EXTERNAL_DIR "${CMAKE_SOURCE_DIR}/external")
set(BINARY_EXTERNAL_DIR "${PROJECT_BINARY_DIR}/external")
set(INSTALL_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib")

# Set a proper RPATH for installed executables. Otherwise, they would not be
# able to find shared libraries after installation.
set(CMAKE_INSTALL_RPATH "${INSTALL_LIB_DIR}")

##
## External projects.
##

include (ExternalProject)

# The default root directory for external projects.
set_directory_properties(PROPERTIES EP_PREFIX ${BINARY_EXTERNAL_DIR})

include(boost)

##
## Compiler options.
##

# Set our own default options. Do not use the CMake default values as it e.g.
# disables assertions in release builds (we want to preserve assertions in
# release builds).
set(CMAKE_CXX_FLAGS_DEBUG "-g -Og")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O3")

# C++1z is required.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -pedantic")

# Optimizations.
if(CLUSTY_FORCE_OPTIMIZATIONS)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O3")
endif()

# Abort compilation upon the first error.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfatal-errors")

# Standard warning parameters.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Additional warning parameters.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wcast-align")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wcast-qual")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfloat-equal")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wold-style-cast")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wswitch-default")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wuninitialized")
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wzero-as-null-pointer-constant")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wsuggest-override")

	# Disable flaging of variables that are _potentially_ used uninitialized
	# because it produces spurious warnings. We only want -Wuninitialized,
	# which flags only variables that are _certainly_ used uninitialized. In
	# GCC, -Wall turns this warning on.
	# See http://stackoverflow.com/a/21756517/2580955 for more details.
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-maybe-uninitialized")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconditional-uninitialized")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wheader-hygiene")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnon-literal-null-conversion")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wreserved-id-macro")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wsometimes-uninitialized")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunreachable-code")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-exception-parameter")
endif()

##
## Subdirectories.
##

add_subdirectory(advent)
add_subdirectory(tests)
