/// @file
///
/// Assertions.
///

#pragma once

#include <cstdlib>
#include <iostream>

#define ABORT(MSG) \
	(std::cerr << __FILE__ ":" << __LINE__ << ": " << __func__ << \
		": " << MSG << std::endl, std::abort())

#define LOG_MSG(MSG) \
	(std::cerr << __FILE__ ":" << __LINE__ << ": " << __func__ << \
		": " << MSG << std::endl)
