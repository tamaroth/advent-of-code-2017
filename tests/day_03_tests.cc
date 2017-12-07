/// @file
///
/// Tests for Day01.
///

#include <vector>

#include <gtest/gtest.h>

#include "advent/days/03/spiral_memory.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

using TestData = std::pair<int, int>;

class Day03Tests: public TestsBase, public Day03 {};

TEST_F(Day03Tests, part_one_is_computed_correctly) {
	const std::vector<TestData> test_values {
		{1, 0},
		{12, 3},
		{23, 2},
		{1024, 31},
	};

	for (const auto& [input, expected] : test_values) {
		EXPECT_EQ(solve_part_one_for_input(input), expected);
	}
}

}
