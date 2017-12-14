/// @file
///
/// Day 14 tests.
///

#include <string>

#include <gmock/gmock.h>

#include "advent/days/14/disk_defragmentation.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class Day14Tests: public TestsBase, public Day14 {};

TEST_F(Day14Tests, solve_part_one_solves_correctly) {
	auto result = solve_part_one_for_input("flqrgnkx");

	ASSERT_EQ(result, 8108);
}

}
