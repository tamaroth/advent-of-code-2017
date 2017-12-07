/// @file
///
/// Tests for Day01.
///

#include <vector>

#include <gtest/gtest.h>

#include "advent/days/02/corruption_checksum.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class Day02Tests: public TestsBase, public Day02 {};

TEST_F(Day02Tests, part_one_is_computed_correctly) {
	const Matrix test_values = {
		{ 5, 1, 9, 5, },
		{ 7, 5, 3, },
		{ 2, 4, 6, 8 ,},
	};

	EXPECT_EQ(solve_part_one_for_input(test_values), 18);
}

TEST_F(Day02Tests, part_two_is_computed_correctly) {
	const Matrix test_values = {
		{ 5, 9, 2, 8, },
		{ 9, 4, 7, 3, },
		{ 3, 8, 6, 5, },
	};

	EXPECT_EQ(solve_part_two_for_input(test_values), 9);
}

}
