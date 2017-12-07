/// @file
///
/// Tests for Day01.
///

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "advent/days/01/inverse_captcha.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

using TestData = std::pair<std::string, int>;

class Day01Tests: public TestsBase, public Day01 {};

TEST_F(Day01Tests, part_one_is_computed_correctly) {
	const std::vector<TestData> test_values {
		{"1122", 3},
		{"1111", 4},
		{"1234", 0},
		{"91212129", 9},
	};

	for (const auto& [input, expected] : test_values) {
		EXPECT_EQ(solve_for_input(input), expected);
	}
}

TEST_F(Day01Tests, part_two_is_computed_correctly) {
	const std::vector<TestData> test_values {
		{"1212", 6},
		{"1221", 0},
		{"123425", 4},
		{"123123", 12},
		{"12131415", 4},
	};

	for (const auto& [input, expected] : test_values) {
		EXPECT_EQ(solve_for_input(input, input.length() >> 1), expected);
	}
}

}
