/// @file
///
/// Main executable
///

#include <cstring>
#include <map>
#include <string>
#include <vector>

#include <boost/program_options.hpp>

#include "advent/utils/base.hh"
#include "advent/utils/solutions.hh"
#include "advent/utils/timer.hh"

namespace {

///
/// Arguments
///
struct Arguments {
	/// Should the help message be shown?
	bool show_help = false;

	/// Which day to run?
	advent::TaskID day_to_run = advent::TaskID::kAllDays;
};

///
/// Parse command line arguments
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
			run_task_solutions(solutions, task);
	}
}
