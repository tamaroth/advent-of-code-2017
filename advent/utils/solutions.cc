/// @file
///
/// All solutions.
///

#include "advent/days/01/inverse_captcha.hh"
#include "advent/days/02/corruption_checksum.hh"
#include "advent/days/03/spiral_memory.hh"
#include "advent/days/04/high_entropy_passphrases.hh"
#include "advent/days/05/maze.hh"
#include "advent/days/06/memory_reallocation.hh"
#include "advent/days/07/recursive_circus.hh"
#include "advent/utils/assert.hh"
#include "advent/utils/base.hh"
#include "advent/utils/container.hh"
#include "advent/utils/solutions.hh"

namespace advent {

Solutions::Solutions() = default;
Solutions::~Solutions() = default;

// Copying is allowed.
Solutions::Solutions(const Solutions&) = default;
Solutions& Solutions::operator=(const Solutions&) = default;

// Moving is allowed.
Solutions::Solutions(Solutions&&) = default;
Solutions& Solutions::operator=(Solutions&&) = default;

///
/// Get a pointer to the given task. If the given task does not exist
/// in the cache create new one and store it in cache.
///
std::shared_ptr<Task> Solutions::get_task(TaskID task) {
	if (contains(solutions, task)) {
		return solutions[task];
	}

	switch (task) {
		case TaskID::kDay01:
			solutions[task] = std::make_shared<Day01>();
			break;
		case TaskID::kDay02:
			solutions[task] = std::make_shared<Day02>();
			break;
		case TaskID::kDay03:
			solutions[task] = std::make_shared<Day03>();
			break;
		case TaskID::kDay04:
			solutions[task] = std::make_shared<Day04>();
			break;
		case TaskID::kDay05:
			solutions[task] = std::make_shared<Day05>();
			break;
		case TaskID::kDay06:
			solutions[task] = std::make_shared<Day06>();
			break;
		case TaskID::kDay07:
			solutions[task] = std::make_shared<Day07>();
			break;
		default:
			ABORT("unknown task");
	}

	return solutions[task];
}

}
