/// @file
///
/// All solutions.
///

#include "advent/days/01/inverse_captcha.hh"
#include "advent/utils/assert.hh"
#include "advent/utils/container.hh"
#include "advent/utils/solutions.hh"

namespace advent {

Solutions::Solutions() = default;
Solutions::~Solutions() = default;

std::shared_ptr<Day> Solutions::get_or_create(Task task) {
	if (contains(solutions, task)) {
		return solutions[task];
	}

	switch (task) {
		case Task::kDay01:
			solutions[task] = std::make_shared<Day01>();
			break;
		default:
			ABORT("unknown task");
	}

	return solutions[task];
}

}
