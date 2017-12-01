/// @file
///
/// Miscellaneous functions and macros.
///

#pragma once

std::string method_name(const std::string& function, const std::string& pretty_function) {
	auto locFunName = pretty_function.find(function);
	auto begin = pretty_function.rfind(" ",locFunName) + 1;
	auto end = pretty_function.find("(",locFunName + function.length());
	if (pretty_function[end + 1] == ')') {
		return (pretty_function.substr(begin,end - begin) + "() ");
	} else {
		return (pretty_function.substr(begin,end - begin) + "(...) ");
	}
}

#define __COMPACT_PRETTY_FUNCTION__ method_name(__FUNCTION__,__PRETTY_FUNCTION__)
