/// @file
///
/// Tests for Day10.
///

#include <string>
#include <vector>

#include <gmock/gmock.h>

#include "advent/days/10/knot_hash.hh"
#include "advent/utils/container.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class CircularBufferTests: public TestsBase {};

TEST_F(CircularBufferTests, get_gets_requested_range) {
	std::vector<int> result{3,4,5,0,1};
	auto cb = CircularBuffer(6);

	auto range = cb.get(3, 5);

	ASSERT_EQ(range, result);
}

TEST_F(CircularBufferTests, set_sets_new_values) {
	std::vector<int> result{6,6,2,6,6,6};
	std::vector<int> to_set{6,6,6,6,6};
	auto cb = CircularBuffer(6);

	cb.set(3, to_set);

	auto range = cb.get(0, 6);
	ASSERT_EQ(range, result);
}

class Day10Tests: public TestsBase, public Day10 {};

TEST_F(Day10Tests, solve_first_part_solves_correctly) {
	std::string input = "3,4,1,5";

	auto hash = solve_part_one_for_input(input, 5);

	ASSERT_EQ(hash, 12);
}

TEST_F(Day10Tests, solve_part_two_for_input_solves_correctly) {
	std::vector<std::pair<std::string, std::string>> inputs = {
		{"", "a2582a3a0e66e6e86e3812dcb672a272" },
		{"AoC 2017", "33efeb34ea91902bb2f59c9920caa6cd" },
		{"1,2,3", "3efbe78a8d82f29979031a4aa0b16a9d" },
		{"1,2,4", "63960835bcdc130f0b66d7ff4f6a5a8e" },
	};

	for (const auto& [input, expected] : inputs) {
		ASSERT_EQ(solve_part_two_for_input(input), expected);
	}
}

}
