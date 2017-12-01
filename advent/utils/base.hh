/// @file
///
/// Base for all puzzles.
///

#pragma once

#include <map>
#include <memory>

#include "advent/utils/misc.hh"

namespace advent {

class Day {
public:
	/// @name Construction and Destruction
	/// @{
	Day() = default;
	virtual ~Day() = default;
	Day(const Day&) = default;
	Day& operator=(const Day&) = default;
	Day(Day&&) = default;
	Day& operator=(Day&&) = default;
	/// @}

	/// @name Puzzle Solutions
	/// @{
	virtual void solve_part_one() = 0;
	virtual void solve_part_two() = 0;
	/// @}

	/// @name Tests for Solutions
	/// @{
	virtual bool test_part_one() = 0;
	virtual bool test_part_two() = 0;
	/// @}

	/// @name Names of solutions.
	/// @{
	virtual std::string part_one() const {
		return __COMPACT_PRETTY_FUNCTION__;
	}
	virtual std::string part_two() const {
		return __COMPACT_PRETTY_FUNCTION__;
	}
	/// @}
};

}
