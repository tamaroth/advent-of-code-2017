/// @file
///
/// Day 02: Corruption Checksum
///

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "advent/days/02/corruption_checksum.hh"
#include "advent/utils/assert.hh"
#include "advent/utils/misc.hh"
#include "advent/utils/tests.hh"

namespace advent {

namespace {

using LocalTestData = BasicTestData<Matrix, int>;

///
/// Input for Day 02 puzzle.
///
const Matrix puzzle_input = {
	{ 104, 240, 147, 246, 123, 175, 372, 71, 116, 230, 260, 118, 202, 270, 277, 292 },
	{ 740, 755, 135, 205, 429, 822, 844, 90, 828, 115, 440, 805, 526, 91, 519, 373 },
	{ 1630, 991, 1471, 1294, 52, 1566, 50, 1508, 1367, 1489, 55, 547, 342, 512, 323, 51 },
	{ 1356, 178, 1705, 119, 1609, 1409, 245, 292, 1434, 694, 405, 1692, 247, 193, 1482, 1407 },
	{ 2235, 3321, 3647, 212, 1402, 3711, 3641, 1287, 2725, 692, 1235, 3100, 123, 144, 104, 101 },
	{ 1306, 1224, 1238, 186, 751, 734, 1204, 1275, 366, 149, 1114, 166, 1118, 239, 153, 943 },
	{ 132, 1547, 1564, 512, 2643, 2376, 2324, 2159, 1658, 107, 1604, 145, 2407, 131, 2073, 1878 },
	{ 1845, 91, 1662, 108, 92, 1706, 1815, 1797, 1728, 1150, 1576, 83, 97, 547, 1267, 261 },
	{ 78, 558, 419, 435, 565, 107, 638, 173, 93, 580, 338, 52, 633, 256, 377, 73 },
	{ 1143, 3516, 4205, 3523, 148, 401, 3996, 3588, 300, 1117, 2915, 1649, 135, 134, 182, 267 },
	{ 156, 2760, 1816, 2442, 2985, 990, 2598, 1273, 167, 821, 138, 141, 2761, 2399, 1330, 1276 },
	{ 3746, 3979, 2989, 161, 4554, 156, 3359, 173, 3319, 192, 3707, 264, 762, 2672, 4423, 2924 },
	{ 3098, 4309, 4971, 5439, 131, 171, 5544, 595, 154, 571, 4399, 4294, 160, 6201, 4329, 5244 },
	{ 728, 249, 1728, 305, 2407, 239, 691, 2241, 2545, 1543, 55, 2303, 1020, 753, 193, 1638 },
	{ 260, 352, 190, 877, 118, 77, 1065, 1105, 1085, 1032, 71, 87, 851, 56, 1161, 667 },
	{ 1763, 464, 182, 1932, 1209, 640, 545, 931, 1979, 197, 1774, 174, 2074, 1800, 939, 161 },
};

///
/// Test values and results for the first part of the puzzle.
///
const LocalTestData part_one_tests {
	{
		{ 5, 1, 9, 5, },
		{ 7, 5, 3, },
		{ 2, 4, 6, 8 ,},
	}, 18
};

///
/// Test value and results for the second part of the puzzle.
///
const LocalTestData part_two_tests {
	{
		{ 5, 9, 2, 8, },
		{ 9, 4, 7, 3, },
		{ 3, 8, 6, 5, },
	}, 9
};

int find_divisible(const std::vector<int>& input) {
	for (const auto& first : input) {
		for (const auto& second : input) {
			if (first != second) {
				auto max = std::max(first, second);
				auto min = std::min(first, second);
				if (max % min == 0) {
					return max / min;
				}
			}
		}
	}
	return -1;
}

}

// Override.
void Day02::solve_part_one() {
	std::cout << part_one()
			<< solve_part_one_for_input(puzzle_input)
		<< std::endl;
}

// Override.
void Day02::solve_part_two() {
	std::cout << part_two()
			<< solve_part_two_for_input(puzzle_input)
		<< std::endl;
}

// Override.
void Day02::test_part_one() {
	TEST_EQ(part_one_tests.first, solve_part_one_for_input(part_one_tests.first), part_one_tests.second);
}

// Override.
void Day02::test_part_two() {
	TEST_EQ(part_two_tests.first, solve_part_two_for_input(part_two_tests.first), part_two_tests.second);
}

// Override.
std::string Day02::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day02::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

///
/// Method finds a sum of a difference of the maximum and minimum element of a row
/// for each row in a matrix.
///
int Day02::solve_part_one_for_input(const Matrix& input) {
	int sum = 0;
	for (const auto& row : input) {
		sum += (*std::max_element(row.begin(),row.end()) - *std::min_element(row.begin(), row.end()));
	}

	return sum;
}

///
/// Method finds in each row of a matrix two numbers that are divisible, divides them and returns its sum.
///
int Day02::solve_part_two_for_input(const Matrix& input) {
	int sum = 0;
	for (const auto& row : input) {
		if (auto result = find_divisible(row); result != -1) {
			sum += result;
		} else {
			LOG_MSG("could not find divisible values");
		}
	}
	return sum;
}

}
