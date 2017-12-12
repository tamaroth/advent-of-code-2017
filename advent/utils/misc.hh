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

template<typename LineT = std::string>
using Lines = std::vector<LineT>;

/// @name Streaming.
/// @{
std::ostream& operator<<(std::ostream& os, const Matrix& mx);

///
/// Streams vector of objects to ostream.
///
/// @tparam T The type of vector to stream.
///
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

/// @name String to Type conversion.
/// @{

///
/// Converts from a string to a type.
///
/// @tparam T Type to convert to
/// @param input String to convert from
/// @result converted value
///
/// For now supported convertion types:
///  - @a int
///  - @a std::string (no convertion)
///
template<typename T>
T convert_to(const std::string& input) {
	static_assert(
		std::is_same<T, int>::value ||
		std::is_same<T, std::string>::value,
		"unsupported convertion type"
	);
	if constexpr(std::is_same<T, int>::value) {
		return std::stoi(input);
	} else {
		return input;
	}
}
/// @}

/// @name String splitting.
/// @{
std::vector<std::string> split(const std::string& input, const std::string regex = " ");

///
/// Splits a string by a delimiter into a vector.
///
template<typename T>
std::vector<T> split_to(const std::string& input, const std::string delimiter = " ") {
	auto split_string = split(input, delimiter);
	std::vector<T> result;
	for (const auto& element : split_string) {
		result.push_back(convert_to<T>(element));
	}
	return result;
}
/// @}

/// @name Reading lines from text files.
/// @{

///
/// Read lines from a text file and stores then in a vector.
///
/// @tparam T Type of value stored in a single line.
/// @param file_name The Name of the file to be read.
/// @return A vector of type T containing values read from the given file.
///
template<typename T = std::string>
std::vector<T> read_lines_from_file(const std::string& file_name) {
	std::vector<T> lines;
	std::ifstream file_stream(file_name);
	if (!file_stream.is_open()) {
		std::cerr << "Could not find input file " << file_name
			<< ". Make sure it's located in current directory." << std::endl;
			return lines;
	}
	std::string line;
	while(std::getline(file_stream, line)) {
		lines.push_back(convert_to<T>(line));
	}

	return lines;
}

std::optional<std::string> read_line_from_file(const std::string& file_name);
/// @}

/// @name Decorative method names
/// @{
std::string method_name(const std::string& function, const std::string& pretty_function);
#define __COMPACT_PRETTY_FUNCTION__ method_name(__FUNCTION__,__PRETTY_FUNCTION__)
/// @}

}


