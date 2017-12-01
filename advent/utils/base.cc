/// @file
///
/// Base for all puzzles.
///

#include "advent/utils/base.hh"
#include "advent/utils/misc.hh"

namespace advent {

Task::Task() = default;
Task::~Task() = default;

// Copying is allowed.
Task::Task(const Task&) = default;
Task& Task::operator=(const Task&) = default;

// Moving is allowed.
Task::Task(Task&&) = default;
Task& Task::operator=(Task&&) = default;

///
/// @returns prettified name of the first part function.
///
std::string Task::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

///
/// @return prettified name of the second part function.
///
std::string Task::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

}
