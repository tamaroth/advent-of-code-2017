/// @file
///
/// Tests for Day01.
///

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "advent/days/05/maze.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

using TestData = std::pair<std::vector<int>, int>;

class Day05Tests: public TestsBase, public Day05 {};

TEST_F(Day05Tests, part_one_is_computed_correctly) {
	TestData test_value { {0, 3, 0, 1, -3}, 5 };

	auto& [input, expected] = test_value;
	EXPECT_EQ(solve_part_one_for_input(input), expected);
}

TEST_F(Day05Tests, part_two_is_computed_correctly) {
	TestData test_value { {0, 3, 0, 1, -3}, 10 };

	auto& [input, expected] = test_value;
	EXPECT_EQ(solve_part_two_for_input(input), expected);
}

}
