/// @file
///
/// Assertions.
///

#pragma once

#include <cstdlib>
#include <iostream>

/// @name Assertions
/// @{

///
/// Aborts the program with an error message @a MSG.
///
#define ABORT(MSG) \
	(std::cerr << __FILE__ ":" << __LINE__ << ": " << __func__ << \
		": " << MSG << std::endl, std::abort())

///
/// Logs the message to cerr.
///
#define LOG_MSG(MSG) \
	(std::cerr << __FILE__ ":" << __LINE__ << ": " << __func__ << \
		": " << MSG << std::endl)

#define THROW_LOGIC_MSG(MSG) \
	std::cerr << __FILE__ ":" << __LINE__ << ": " << __func__ << std::endl; \
	throw std::logic_error(MSG);
/// @}
