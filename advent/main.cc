/// @file
///
/// Main executable
///

#include <cstring>
#include <map>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/any.hpp>
#include <boost/program_options.hpp>

#include "advent/utils/base.hh"
#include "advent/utils/container.hh"
#include "advent/utils/solutions.hh"
#include "advent/utils/timer.hh"

namespace {

enum class Test {
	kNoTests,
	kOnlyTests,
	kBadEntry
};

struct TestOption {
	TestOption(const std::string& test): test(string_to_test(test)) {}

	static bool is_valid(const std::string& str) {
		auto to_test =  boost::algorithm::to_lower_copy(str);
		return advent::contains(correct_options, to_test);
	}

	static Test string_to_test(const std::string& str) {
		auto to_test =  boost::algorithm::to_lower_copy(str);
		if (advent::contains(correct_options, to_test)) {
			return correct_options.at(to_test);
		}
		return Test::kBadEntry;
	}

	Test test;
private:
	static const std::map<std::string, Test> correct_options;
};

const std::map<std::string, Test> TestOption::correct_options = {
	{"no", Test::kNoTests},
	{"only", Test::kOnlyTests},
};

void validate(boost::any& v, const std::vector<std::string>& values, TestOption*, int)
{
	namespace po = boost::program_options;

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

Arguments parse_arguments(int argc, char** argv) {
	namespace po = boost::program_options;

	Arguments args;

	po::options_description supported_options("Supported options");
	supported_options.add_options()
		(
			"help,h",
			po::bool_switch()->
				notifier([&args](bool value) {
					args.show_help = value;
				}),
			"Show this help message."
		)
		(
			"test,t",
			po::value<TestOption>()->
				value_name("TESTS")->
				notifier([&args](const TestOption& opt) {
					args.test = opt.test;
				}),
			"Choose mode for tests: NO (no tests), ONLY(only tests)"
		)
		(
			"day,d",
			po::value<int>()->
				value_name("NUM")->
				notifier([&args](int day) {
					args.day_to_run = static_cast<advent::TaskID>(day-1);
				}),
			"Which day to run, skipping this value will test all days."
		)
	;

	po::options_description options;
	options.add(supported_options);

	po::variables_map vm;
	auto parsed = po::command_line_parser(argc, argv)
		.options(options)
		.run();
	po::store(parsed, vm);
	po::notify(vm);

	if (args.show_help) {
		std::cerr << options << std::endl;
		std::exit(0);
	}

	return args;
}

void run_tests_for_task(advent::Solutions& solutions, advent::TaskID task_id) {
	auto day = solutions.get_task(task_id);
	day->test_part_one();
	day->test_part_two();
}

void run_task_solutions(advent::Solutions& solutions, advent::TaskID task_id) {
	auto day = solutions.get_task(task_id);
	advent::measure_execution_time(day->part_one(), [&] {
		day->solve_part_one();
	});
	advent::measure_execution_time(day->part_two(), [&] {
		day->solve_part_two();
	});
}

}

int main(int argc, char** argv) {
	auto args = parse_arguments(argc, argv);
	advent::Solutions solutions;
	std::vector<advent::TaskID> to_run;

	if (args.day_to_run == advent::TaskID::kAllDays) {
		auto tasks = advent::Tasks();
		for (const auto& task : tasks) {
			to_run.push_back(task);
		}
	} else {
		to_run.push_back(args.day_to_run);
	}

	for (const auto& task : to_run) {
		if (args.test != Test::kNoTests) {
			run_tests_for_task(solutions, task);
		}
		if (args.test != Test::kOnlyTests) {
			run_task_solutions(solutions, task);
		}
	}
}
