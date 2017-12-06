/// @file
///
/// Main executable
///

#include <cstring>
#include <map>
#include <string>
#include <vector>

#include <boost/program_options.hpp>

#include "advent/utils/arguments.hh"
#include "advent/utils/base.hh"
#include "advent/utils/solutions.hh"
#include "advent/utils/timer.hh"

namespace advent {

const std::map<std::string, Test> TestOption::correct_options = {
	{"no", Test::kNoTests},
	{"only", Test::kOnlyTests},
};

}

namespace {

using advent::Arguments;
using advent::Test;
using advent::TestOption;

namespace po = boost::program_options;

template<typename Block, typename Handler>
decltype(auto) exit_on_invalid_param(Block&& block, Handler&& handler) {
	try {
		return block();
	} catch (const po::validation_error& ex) {
		std::cerr << ex.what() << std::endl;
		handler();
		std::exit(0);
	}
}

Arguments parse_arguments(int argc, char** argv) {
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

	return exit_on_invalid_param([&]{
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
	}, [&]{
		std::cerr << options << std::endl;
	});
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
