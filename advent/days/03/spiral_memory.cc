/// @file
///
/// Day 02: Corruption Checksum
///

#include <algorithm>
#include <cmath>
#include <iostream>

#include "advent/days/03/spiral_memory.hh"
#include "advent/utils/assert.hh"
#include "advent/utils/misc.hh"
#include "advent/utils/tests.hh"

namespace advent {

namespace {

using LocalTestData = BasicTestData<int, int>;

///
/// Input for the puzzle
///
const int puzzle_input = 289326;

///
/// Test values and results for the first part of the puzzle.
///
const std::vector<LocalTestData> part_one_tests {
	{1, 0},
	{12, 3},
	{23, 2},
	{1024, 31},
};

///
/// Test values and results for the second part of the puzzle.
///
const std::vector<LocalTestData> part_two_tests {
	{7, 10},
	{32, 54},
	{112, 122},
	{1024, 1968}
};

}

// Override.
void Day03::solve_part_one() {
	std::cout << part_one()
			<< solve_part_one_for_input(puzzle_input)
		<< std::endl;
}

// Override.
void Day03::solve_part_two() {
	std::cout << part_two()
			<< solve_part_two_for_input(puzzle_input)
		<< std::endl;
}

// Override.
void Day03::test_part_one() {
	for (auto& [value, expected] : part_one_tests) {
		TEST_EQ(value, solve_part_one_for_input(value), expected);
	}
}

// Override.
void Day03::test_part_two() {
}

// Override.
std::string Day03::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day03::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

///
/// Method computes the number of required taxicab metric to reach from a value
/// to the centre of the outward spiral.
///
int Day03::solve_part_one_for_input(const int& input) {
	if (input == 1) {
		return 0;
	}
	auto root = static_cast<int>(std::ceil(std::sqrt(input)));
	auto side_length = (root % 2 ? root : root+1);
	auto steps = (side_length -1) / 2;
	auto cycle = static_cast<int>(input - std::pow(side_length - 2, 2));
	auto offset = cycle % (side_length - 1);

	return steps + std::abs(offset - steps);
}

///
/// Find the first number in OEIS sequence that is bigger than the given input.
/// OEIS sequence: https://oeis.org/A141481
///
int Day03::solve_part_two_for_input(const int& input) {
	std::vector<int> values = {
		1, 1, 2, 4, 5, 10, 11, 23, 25, 26, 54, 57, 59, 122, 133, 142, 147, 304,
		330, 351, 362, 747, 806, 880, 931, 957, 1968, 2105, 2275, 2391, 2450, 5022,
		5336, 5733, 6155, 6444, 6591, 13486, 14267, 15252, 16295, 17008, 17370,
		35487, 37402, 39835, 42452, 45220, 47108, 48065, 98098, 103128, 109476,
		116247, 123363, 128204, 130654, 266330, 279138, 295229, 312453, 330785,
		349975, 363010, 369601, 752688, 787032, 830037, 875851, 924406, 975079,
		1009457, 1026827, 2089141, 2179400, 2292124, 2411813, 2539320, 2674100,
		2814493, 2909666, 2957731, 6013560, 6262851, 6573553, 6902404, 7251490,
		7619304, 8001525, 8260383, 8391037, 17048404, 17724526, 18565223, 19452043,
		20390510, 21383723, 22427493, 23510079, 24242690, 24612291, 49977270,
		51886591, 54256348, 56749268, 59379562, 62154898, 65063840, 68075203,
		70111487, 71138314, 144365769, 149661137, 156221802, 163105139, 170348396,
		177973629, 186001542, 194399801, 203081691, 208949088, 211906819, 429827198,
		445061340, 463911304, 483650112, 504377559, 526150757, 549023076, 572904288,
		597557233, 614208653, 622599690,
	};

	auto it = std::find_if(values.begin(), values.end(), [&](const int& element) {
		return element > input;
	});
	return it != values.end() ? *it : -1;
}

}
