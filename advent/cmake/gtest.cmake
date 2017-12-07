##
## Google Test build (including Google Mock).
##

find_package(Threads REQUIRED)

set(GTEST_INSTALL_DIR "${BINARY_EXTERNAL_DIR}/src/gtest-project-install")
# Set a custom library installation directory because the default directory
# depends on the OS ('lib' on Debian and 'lib64' on Arch Linux).
set(GTEST_INSTALL_LIB_DIR "${GTEST_INSTALL_DIR}/lib")
ExternalProject_Add(gtest-project
	# Snapshot from 2017-09-24.
	URL "https://github.com/google/googletest/archive/f1a87d73fc604c5ab8fbb0cc6fa9a86ffd845530.zip"
	URL_HASH SHA1=ca0390eba180fe345afeb0804dbbc24e0abf0abd
	CMAKE_ARGS
		"-DCMAKE_BUILD_TYPE=Release"
		"-DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}"
		"-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
		"-DCMAKE_INSTALL_PREFIX=${GTEST_INSTALL_DIR}"
		"-DCMAKE_INSTALL_LIBDIR=${GTEST_INSTALL_LIB_DIR}"
	LOG_CONFIGURE ON
	LOG_BUILD ON
	LOG_INSTALL ON
)

add_library(gtest INTERFACE)
target_include_directories(gtest SYSTEM INTERFACE
	"${GTEST_INSTALL_DIR}/include"
)
target_link_libraries(gtest INTERFACE
	"${GTEST_INSTALL_LIB_DIR}/libgmock.a"
	${CMAKE_THREAD_LIBS_INIT}
)
add_dependencies(gtest gtest-project)
