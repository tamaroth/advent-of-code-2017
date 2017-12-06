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

#include "advent/utils/types.hh"

namespace advent {

std::string method_name(const std::string& function, const std::string& pretty_function);
std::vector<std::string> split(const std::string& input, const std::string regex = " ");

/// @name Streaming.
/// @{
std::ostream& operator<<(std::ostream& os, const Matrix& mx);

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> vec) {
	os << "{ ";
	for (const auto& element : vec) {
		os << element << ", ";
	}
	os << "}";
	return os;
}
/// @}
///
/// Converts from a string to a type.
///
/// For now supported convertion types:
///  - @a int
///  - @a std::string (no convertion)
///
template<typename T>
T convert_to(const std::string& value) {
	static_assert(
		std::is_same<T, int>::value ||
		std::is_same<T, std::string>::value,
		"unsupported convertion type"
	);
	if constexpr(std::is_same<T, int>::value) {
		return std::stoi(value);
	} else {
		return value;
	}
}

template<typename T>
std::vector<T> split_to(const std::string& input, const std::string regex = " ") {
	auto split_string = split(input, regex);
	std::vector<T> result;
	for (const auto& element : split_string) {
		result.push_back(convert_to<T>(element));
	}
	return result;
}

///
/// Read lines from a text file and stores then in a vector.
///
/// @tparam T Type of value stored in a single line.
/// @param file_name The Name of the file to be read.
/// @return A vector of type T containing values read from the given file.
///
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

#define __COMPACT_PRETTY_FUNCTION__ method_name(__FUNCTION__,__PRETTY_FUNCTION__)

}


