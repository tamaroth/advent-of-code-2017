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
#include "advent/days/08/registers.hh"
#include "advent/days/09/stream_processing.hh"
#include "advent/days/10/knot_hash.hh"
#include "advent/days/11/hex_ed.hh"
#include "advent/days/12/digital_plumber.hh"
#include "advent/days/13/packet_scanners.hh"
#include "advent/days/14/disk_defragmentation.hh"
#include "advent/days/15/dueling_generators.hh"
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
		case TaskID::kDay08:
			solutions[task] = std::make_shared<Day08>();
			break;
		case TaskID::kDay09:
			solutions[task] = std::make_shared<Day09>();
			break;
		case TaskID::kDay10:
			solutions[task] = std::make_shared<Day10>();
			break;
		case TaskID::kDay11:
			solutions[task] = std::make_shared<Day11>();
			break;
		case TaskID::kDay12:
			solutions[task] = std::make_shared<Day12>();
			break;
		case TaskID::kDay13:
			solutions[task] = std::make_shared<Day13>();
			break;
		case TaskID::kDay14:
			solutions[task] = std::make_shared<Day14>();
			break;
		case TaskID::kDay15:
			solutions[task] = std::make_shared<Day15>();
			break;
		default:
			ABORT("unknown task");
	}

	return solutions[task];
}

}
