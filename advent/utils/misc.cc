/// @file
///
/// Miscellaneous funcitons.
///

#include <string>
#include <regex>

#include "advent/utils/misc.hh"

namespace advent {

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

std::vector<std::string> split(const std::string& input, const std::string regex) {
	std::regex re(regex);
	std::sregex_token_iterator
		first{input.begin(), input.end(), re, -1},
		last;
	return {first, last};
}

std::ostream& operator<<(std::ostream& os, const Matrix& mx) {
	os << "{" << std::endl;
	for (const auto& row: mx) {
		os << "    { ";
		for (const auto& element: row) {
			os << element << ", ";
		}
		os << "}," << std::endl;
	}
	os << "}" << std::endl;
	return os;
}

}
