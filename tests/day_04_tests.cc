/// @file
///
/// Tests for Day01.
///

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "advent/days/04/high_entropy_passphrases.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

using TestData = std::pair<std::string, bool>;

class Day04Tests: public TestsBase, public Day04 {};

TEST_F(Day04Tests, part_one_is_computed_correctly) {
	const std::vector<TestData> test_values {
		{ "aa bb cc dd ee", true },
		{ "aa bb cc dd aa", false },
		{ "aa bb cc dd aaa", true },
	};

	for (const auto& [input, expected] : test_values) {
		EXPECT_EQ(solve_part_one_for_input(input), expected);
	}
}

TEST_F(Day04Tests, part_two_is_computed_correctly) {
	const std::vector<TestData> test_values {
		{ "abcde fghij", true },
		{ "abcde xyz ecdab", false },
		{ "a ab abc abd abf abj", true },
		{ "iiii oiii ooii oooi oooo", true },
		{ "oiii ioii iioi iiio", false },
	};

	for (const auto& [input, expected] : test_values) {
		EXPECT_EQ(solve_part_two_for_input(input), expected);
	}
}

}
