/// @file
///
/// Main executable
///

#include <cstring>

#include "advent/utils/assert.hh"
#include "advent/utils/solutions.hh"
#include "advent/utils/timer.hh"

namespace {

void run_tests_for_task(advent::Solutions& solutions, advent::Task task) {
	auto day = solutions.get_or_create(task);
	advent::execution(day->part_one(), [&] {
		day->test_part_one();
	});
	advent::execution(day->part_two(), [&] {
		day->test_part_two();
	});
}

void run_task_solutions(advent::Solutions& solutions, advent::Task task) {
	auto day = solutions.get_or_create(task);
	advent::execution(day->part_one(), [&] {
		day->solve_part_one();
	});
	advent::execution(day->part_two(), [&] {
		day->solve_part_two();
	});
}

}

int main(int argc, char** argv) {
	using advent::Task;

	std::array<Task, static_cast<int>(Task::kFinished)> to_test = {
		Task::kDay01,
	};
	advent::Solutions solutions;

	for (const auto& task : to_test) {
		if (argc == 2 && !strcmp(argv[1], "tests")) {
			run_tests_for_task(solutions, task);
		}
		run_task_solutions(solutions, task);
	}
}
