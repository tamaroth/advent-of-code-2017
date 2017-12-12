/// @file
///
/// Tests for Day12.
///

#include <string>
#include <vector>

#include <gmock/gmock.h>

#include "advent/days/12/digital_plumber.hh"
#include "advent/utils/container.hh"
#include "advent/utils/misc.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class Day12Tests: public TestsBase, public Day12 {};

TEST_F(Day12Tests, parse_lines_to_db_parses_correctly) {
	std::vector<std::string> lines = {
		"0 <-> 2",
		"1 <-> 1",
		"2 <-> 0, 3, 4",
		"3 <-> 2, 4",
		"4 <-> 2, 3, 6",
		"5 <-> 6",
		"6 <-> 4, 5",
	};

	auto db = parse_lines_to_db(lines);

	EXPECT_EQ(db.size(), lines.size());
}

TEST_F(Day12Tests, solve_part_one_for_input_solves_correctly) {
	std::pair<std::vector<std::string>, int> to_test = {
		{
			"0 <-> 2",
			"1 <-> 1",
			"2 <-> 0, 3, 4",
			"3 <-> 2, 4",
			"4 <-> 2, 3, 6",
			"5 <-> 6",
			"6 <-> 4, 5",
		}, 6
	};
	const auto& [input, expected] = to_test;
	auto db = parse_lines_to_db(input);

	EXPECT_EQ(solve_part_one_for_input(db), expected);
}

TEST_F(Day12Tests, solve_part_two_for_input_solves_correctly) {
	std::pair<std::vector<std::string>, int> to_test = {
		{
			"0 <-> 2",
			"1 <-> 1",
			"2 <-> 0, 3, 4",
			"3 <-> 2, 4",
			"4 <-> 2, 3, 6",
			"5 <-> 6",
			"6 <-> 4, 5",
		}, 2
	};
	const auto& [input, expected] = to_test;
	auto db = parse_lines_to_db(input);

	EXPECT_EQ(solve_part_two_for_input(db), expected);
}

}
