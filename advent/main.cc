/// @file
///
/// Main executable
///

#include <cstring>

#include "advent/utils/base.hh"
#include "advent/utils/solutions.hh"
#include "advent/utils/timer.hh"

namespace {

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
	std::array<advent::TaskID, static_cast<int>(advent::TaskID::kFinished)> to_run = {
		advent::TaskID::kDay01,
		advent::TaskID::kDay02,
		advent::TaskID::kDay03,
		advent::TaskID::kDay04,
	};
	advent::Solutions solutions;

	for (const auto& task : to_run) {
		if (argc == 2 && !strcmp(argv[1], "tests")) {
			run_tests_for_task(solutions, task);
		}
		run_task_solutions(solutions, task);
	}
}
