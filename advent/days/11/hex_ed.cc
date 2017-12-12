/// @file
///
/// Day 11: Hex Ed
///

#include <map>

#include "advent/days/11/hex_ed.hh"
#include "advent/utils/misc.hh"

namespace advent {

// Override.
void Day11::solve_part_one() {
	auto input = read_line_from_file("day_11_input.txt");
	std::cout << part_one()
			<< solve_part_one_for_input(*input)
		<< std::endl;
}

// Override.
void Day11::solve_part_two() {
	std::cout << part_two()
			<< solve_part_two_for_input()
		<< std::endl;
}

// Override.
std::string Day11::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day11::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

///
/// Solves the first part of the puzzle.
/// For the given input traverses the hexagonal grid and @returns the Manhattan
/// Distance from the centre of the grid.
///
int Day11::solve_part_one_for_input(const std::string& input) {
	auto directions = split(input, ",");
	std::map<std::string, Coords> relations = {
		{"n", {0,1}},
		{"ne", {1,0}},
		{"se", {1,-1}},
		{"s", {0,-1}},
		{"sw", {-1,0}},
		{"nw", {-1,1}},
	};

	position.reset();
	for (const auto& direction : directions) {
		position += relations[direction];
	}

	return position.distance_from_zero();
}

///
/// Solves the second part of the puzzle.
/// @returns the maximal distance we have traversed during the first part.
///
int Day11::solve_part_two_for_input() {
	return position.maximum_distance();
}

}
