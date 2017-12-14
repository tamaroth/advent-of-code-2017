##
## fmt build.
##

set(FMT_SRC_DIR "${BINARY_EXTERNAL_DIR}/src/fmt-project")
set(FMT_INSTALL_DIR "${BINARY_EXTERNAL_DIR}/src/fmt-project-install")
ExternalProject_Add(fmt-project
	# Note: When updating version number, do not forget to update version
	#       numbers in the libraries below.
	URL "https://github.com/fmtlib/fmt/archive/3.0.2.tar.gz"
	URL_HASH SHA1=4726b14f05a1d9a1c8a55be5762215c8a3d53786
	CMAKE_ARGS
		"-DCMAKE_BUILD_TYPE=Release"
		"-DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}"
		"-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
		"-DCMAKE_INSTALL_PREFIX=${FMT_INSTALL_DIR}"
		"-DBUILD_SHARED_LIBS=1"
		"-DCMAKE_CXX_FLAGS=-fPIC"
	LOG_CONFIGURE ON
	LOG_BUILD ON
	LOG_INSTALL ON
)

add_library(fmt INTERFACE)
target_include_directories(fmt SYSTEM INTERFACE
	"${FMT_INSTALL_DIR}/include"
)
target_link_libraries(fmt INTERFACE
	"${FMT_INSTALL_DIR}/lib/libfmt.so"
)
install(FILES
	"${FMT_INSTALL_DIR}/lib/libfmt.so"
	"${FMT_INSTALL_DIR}/lib/libfmt.so.3"
	"${FMT_INSTALL_DIR}/lib/libfmt.so.3.0.2"
	DESTINATION "${INSTALL_LIB_DIR}"
)
add_dependencies(fmt fmt-project)
