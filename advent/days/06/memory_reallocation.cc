/// @file
///
/// Day 06: Memory Reallocation
///

#include <algorithm>
#include <iostream>

#include "advent/days/06/memory_reallocation.hh"
#include "advent/utils/misc.hh"

namespace advent {

using namespace std::string_literals;

namespace {

///
/// Input for Day 04 puzzle.
///
const std::string puzzle_input =
	"14	0	15	12	11	11	3	5	1	6	8	4	9	1	8	4";

void reallocate_blocks(std::vector<int>& input) {
	auto it = std::max_element(input.begin(), input.end());
	auto to_distribute = *it;
	*it = 0;

	while (to_distribute) {
		it++;
		if (it == input.end()) {
			it = input.begin();
		}
		*it += 1;
		to_distribute--;
	}
}

}

// Override.
void Day06::solve_part_one() {
	auto input = split_to<int>(puzzle_input, "\t"s);
	std::cout << part_one()
			<< solve_part_one_for_input(input)
		 << std::endl;
}

// Override.
void Day06::solve_part_two() {
	std::cout << part_two()
			<< solve_part_two_for_input()
		<< std::endl;
}

// Override.
std::string Day06::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day06::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

///
/// Method calculates the number of cycles required for the given input to find the order
/// of the input that was already generated.
///
int Day06::solve_part_one_for_input(std::vector<int>& input) {
	while (visited_states.count(input) == 0) {
		visited_states[input] = cycles;
		reallocate_blocks(input);
		cycles++;
	}
	loop_length = cycles - visited_states[input];
	visited_states.clear();
	return cycles;
}

///
/// Method returns the length of the loop calculated in part 1.
///
int Day06::solve_part_two_for_input() {
	return loop_length;
}

}
