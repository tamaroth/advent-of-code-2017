/// @file
///
/// Day 05: A Maze of Twisty Trampolines, All Alike
///

#include <iostream>
#include <string>
#include <vector>

#include "advent/days/05/maze.hh"
#include "advent/utils/assert.hh"
#include "advent/utils/misc.hh"
#include "advent/utils/tests.hh"

namespace advent {

namespace {

using LocalTestData = BasicTestData<std::vector<int>, int>;

///
/// Input for Day 04 puzzle.
///
const std::string puzzle_input = "day_05_input.txt";

///
/// Test values and results for the first part of the puzzle.
///
const LocalTestData part_one_tests { {0, 3, 0, 1, -3}, 5 };

///
/// Test value and results for the second part of the puzzle.
///
const LocalTestData part_two_tests { {0, 3, 0, 1, -3}, 10 };

}

// Override.
void Day05::solve_part_one() {
	std::cout << part_one();
	auto lines = read_lines_from_file<int>(puzzle_input);
	if (lines) {
		std::cout << solve_part_one_for_input(*lines) << std::endl;
	}
}

// Override.
void Day05::solve_part_two() {
	std::cout << part_two();
	auto lines = read_lines_from_file<int>(puzzle_input);
	if (lines) {
		std::cout << solve_part_two_for_input(*lines) << std::endl;
	}
}

// Override.
void Day05::test_part_one() {
	auto [input, expected] = part_one_tests;
	TEST_EQ_V(input, solve_part_one_for_input(input), expected);
}

// Override.
void Day05::test_part_two() {
	auto [input, expected] = part_two_tests;
	TEST_EQ_V(input, solve_part_two_for_input(input), expected);
}

std::string Day05::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}
std::string Day05::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

///
/// Method traverses the maze of instruction jumps and exits when the offset jumps
/// outside of the array.
///
int Day05::solve_part_one_for_input(std::vector<int>& input) {
	int steps = 0;
	int index = 0;
	auto end = static_cast<int>(input.size());
	while (true) {
		steps++;
		auto& value = input[index];
		if (value + index >= end) {
			break;
		}
		index += value;
		value++;
	}
	return steps;
}

///
/// Same as above with additional condition included. If the offset is 3 or greater
/// instead subtract one.
///
int Day05::solve_part_two_for_input(std::vector<int>& input) {
	int steps = 0;
	int index = 0;
	auto end = static_cast<int>(input.size());
	while (true) {
		steps++;
		auto& value = input[index];
		if (value + index >= end) {
			break;
		}
		index += value;
		if (value >= 3) {
			value -= 2;
		}
		value++;
	}
	return steps;
}

}
