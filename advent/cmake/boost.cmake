##
## Boost build.
##

# We need to obtain the number of CPU cores to make the Boost build parallel.
include(ProcessorCount)
ProcessorCount(CPU_COUNT)

set(BOOST_SRC_DIR "${BINARY_EXTERNAL_DIR}/src/boost-project")
set(BOOST_INSTALL_DIR "${BINARY_EXTERNAL_DIR}/src/boost-project-install")
ExternalProject_Add(boost-project
	# Note: When updating version number, do not forget to update version
	#       numbers in the libraries below.
	URL "https://dl.bintray.com/boostorg/release/1.65.1/source/boost_1_65_1.tar.gz"
	URL_HASH SHA256=a13de2c8fbad635e6ba9c8f8714a0e6b4264b60a29b964b940a22554705b6b60
	BUILD_IN_SOURCE 1
##	PATCH_COMMAND "${CMAKE_SOURCE_DIR}/cmake/patch_boost_sources.sh"
##		"${BOOST_SRC_DIR}"
##		"${CXX_COMPILER_NAME}"
##		"${CMAKE_CXX_COMPILER}"
##		"${CXX_COMPILER_VERSION}"
	CONFIGURE_COMMAND "${BOOST_SRC_DIR}/bootstrap.sh"
		"--with-toolset=${CXX_COMPILER_NAME}"
	BUILD_COMMAND "${BOOST_SRC_DIR}/b2" install
		--prefix=${BOOST_INSTALL_DIR}
		--without-python
		--without-mpi
		--disable-icu
		--threading=multi
		--link=static
		--variant=release
		-j${CPU_COUNT}
	# Disable the install step (it is performed as part of the build step).
	INSTALL_COMMAND ""
	LOG_CONFIGURE ON
	LOG_BUILD ON
)

add_library(boost INTERFACE)
target_compile_definitions(boost INTERFACE
	# Boost libraries are linked dynamically. The following define fixes linking errors.
	-DBOOST_ALL_DYN_LINK
)
target_include_directories(boost SYSTEM INTERFACE
	"${BOOST_INSTALL_DIR}/include"
)
target_link_libraries(boost INTERFACE
	"${BOOST_INSTALL_DIR}/lib/libboost_atomic.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_chrono.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_date_time.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_filesystem.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_log.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_log_setup.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_program_options.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_regex.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_system.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_thread.so"
)
install(FILES
	"${BOOST_INSTALL_DIR}/lib/libboost_atomic.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_atomic.so.1.65.1"
	"${BOOST_INSTALL_DIR}/lib/libboost_chrono.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_chrono.so.1.65.1"
	"${BOOST_INSTALL_DIR}/lib/libboost_date_time.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_date_time.so.1.65.1"
	"${BOOST_INSTALL_DIR}/lib/libboost_filesystem.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_filesystem.so.1.65.1"
	"${BOOST_INSTALL_DIR}/lib/libboost_log.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_log.so.1.65.1"
	"${BOOST_INSTALL_DIR}/lib/libboost_log_setup.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_log_setup.so.1.65.1"
	"${BOOST_INSTALL_DIR}/lib/libboost_program_options.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_program_options.so.1.65.1"
	"${BOOST_INSTALL_DIR}/lib/libboost_regex.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_regex.so.1.65.1"
	"${BOOST_INSTALL_DIR}/lib/libboost_system.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_system.so.1.65.1"
	"${BOOST_INSTALL_DIR}/lib/libboost_thread.so"
	"${BOOST_INSTALL_DIR}/lib/libboost_thread.so.1.65.1"
	DESTINATION "${INSTALL_LIB_DIR}"
)
add_dependencies(boost boost-project)
