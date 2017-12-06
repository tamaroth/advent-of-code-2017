/// @file
///
/// Program arguments
///

#pragma once

#include <stdexcept>

#include <boost/algorithm/string.hpp>
#include <boost/any.hpp>
#include <boost/program_options.hpp>

#include "advent/utils/container.hh"
#include "advent/utils/tasks.hh"

namespace advent {

namespace po = boost::program_options;

///
/// Supported Test options
///
enum class Test {
	kNoTests,		///< No tests performed.
	kOnlyTests,		///< Only tests performed, no solutions.
};

///
/// Single Test Option
///
struct TestOption {
	TestOption(const std::string& test): test(string_to_test(test)) {}

	///
	/// Checks whether the given option is valid and supported.
	///
	static bool is_valid(const std::string& str) {
		auto to_test =  boost::algorithm::to_lower_copy(str);
		return advent::contains(correct_options, to_test);
	}

	///
	/// Converts the given string to the
	static Test string_to_test(const std::string& str) {
		auto to_test =  boost::algorithm::to_lower_copy(str);
		if (!advent::contains(correct_options, to_test)) {
			throw po::validation_error(po::validation_error::invalid_option_value);
		}
		return correct_options.at(to_test);
	}

	Test test;
private:
	static const std::map<std::string, Test> correct_options;
};

void validate(boost::any& v, const std::vector<std::string>& values, TestOption*, int)
{
	po::validators::check_first_occurrence(v);

	std::string const& s = po::validators::get_single_string(values);

	if (TestOption::is_valid(s)) {
		v = boost::any(TestOption(s), nullptr, nullptr);
	} else {
		throw po::validation_error(po::validation_error::invalid_option_value);
	}
}

///
/// Arguments
///
struct Arguments {
	/// Should the help message be shown?
	bool show_help = false;

	/// Testing option.
	Test test;

	/// Which day to run?
	advent::TaskID day_to_run = advent::TaskID::kAllDays;
};

}

