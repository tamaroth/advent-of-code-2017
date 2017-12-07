/// @file
///
/// Tests for Day01.
///

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "advent/days/06/memory_reallocation.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

using TestData = std::pair<std::vector<int>, int>;

class Day06Tests: public TestsBase, public Day06 {};

TEST_F(Day06Tests, part_one_is_computed_correctly) {
	TestData test_value { {0, 2, 7, 0}, 5 };

	auto& [input, expected] = test_value;
	EXPECT_EQ(solve_part_one_for_input(input), expected);
}

TEST_F(Day06Tests, part_two_is_computed_correctly) {
	TestData test_value { {0, 2, 7, 0}, 4 };

	auto& [input, expected] = test_value;
	solve_part_one_for_input(input);
	EXPECT_EQ(solve_part_two_for_input(), expected);
}

}
