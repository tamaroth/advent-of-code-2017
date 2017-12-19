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

std::ostream& print_one(std::ostream& os) {
	return os;
}

std::mutex& get_cout_mutex() {
	static std::mutex m;
	return m;
}

std::optional<std::string> read_line_from_file(const std::string& file_name) {
	std::string line;
	std::ifstream file_stream(file_name);

	if (!file_stream.is_open()) {
		std::cerr << "Could not find input file " << file_name
			<< ". Make sure it's located in current directory." << std::endl;
			return std::nullopt;
	}

	std::getline(file_stream, line);
	return line;
}

}
