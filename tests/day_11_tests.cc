/// @file
///
/// Tests for Day11.
///

#include <string>
#include <vector>

#include <gmock/gmock.h>

#include "advent/days/11/hex_ed.hh"
#include "advent/utils/container.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class Day11Tests: public TestsBase, public Day11 {};

TEST_F(Day11Tests, solve_first_part_solves_correctly) {
	std::vector<std::pair<std::string, int>> to_test = {
		{"ne,ne,ne", 3},
		{"ne,ne,sw,sw", 0},
		{"ne,ne,s,s", 2},
		{"se,sw,se,sw,sw", 3},
	};

	for (const auto& [input, expected] : to_test) {
		EXPECT_EQ(solve_part_one_for_input(input), expected);
	}
}

}
