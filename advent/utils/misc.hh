/// @file
///
/// Miscellaneous functions and macros.
///

#pragma once

#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <type_traits>
#include <vector>

namespace advent {

std::string method_name(const std::string& function, const std::string& pretty_function);
#define __COMPACT_PRETTY_FUNCTION__ method_name(__FUNCTION__,__PRETTY_FUNCTION__)

template<typename T>
T convert_to(const std::string& value) {
	if constexpr(std::is_same<T, int>::value) {
		return std::stoi(value);
	} else {
		return value;
	}
}

template<typename T>
std::optional<std::vector<T>> read_lines_from_file(const std::string& file_name) {
	std::vector<T> lines;
	std::ifstream file_stream(file_name);
	if (!file_stream.is_open()) {
		std::cerr << "Could not find input file " << file_name
			<< ". Make sure it's located in current directory." << std::endl;
			return std::nullopt;
	}
	std::string line;
	while(std::getline(file_stream, line)) {
		lines.push_back(convert_to<T>(line));
	}

	return lines;
}

}


