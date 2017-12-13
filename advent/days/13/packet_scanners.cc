/// @file
///
/// Day 13: Packet Scanners
///

#include <regex>

#include "advent/days/13/packet_scanners.hh"
#include "advent/utils/misc.hh"

namespace advent {

void Day13::set_up() {
	auto lines = read_lines_from_file("day_13_input.txt");
	for (const auto& line : lines) {
		auto layer = split_to<int>(line, ": ");
		layers.emplace_back(Layer{layer[0], layer[1]});
	}
}

// Override.
void Day13::solve_part_one() {
	std::cout << part_one()
			<< solve_part_one_for_input()
		<< std::endl;
}

// Override.
void Day13::solve_part_two() {
	std::cout << part_two()
			<< solve_part_two_for_input(layers)
		<< std::endl;
}

// Override.
std::string Day13::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day13::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

///
/// Solves first part of the puzzle.
///
int Day13::solve_part_one_for_input() {
	return compute_severity(layers);
}

///
/// Solves second part of the puzzle.
///
int Day13::solve_part_two_for_input(const Layers& layers_to_check) {
	int delay = 1;
	while (delay >= 0) {
		auto severity = compute_severity(layers_to_check, delay);
		if (severity == -1) {
			return delay;
		}
		delay++;
	}
	return -1;
}

///
/// Checkws whether the packet going through the given layer with the given
/// depth is caught.
///
bool Day13::is_caught(int layer, int depth) {
	if (depth == 1) {
		return true;
	}

	auto cycle = 2 * (depth - 1);
	if ((layer % cycle) == 0) {
		return true;
	}
	return false;
}

///
/// Method computes severity of the travel, which is a sum of all
/// multiplications of the caught layer by its depth.
///
int Day13::compute_severity(const Layers& layers, int delay) {
	int severity = 0;
	int caught = 0;
	for (const auto& [layer, depth] : layers) {
		if (is_caught(layer+delay, depth)) {
			severity += (layer * depth);
			caught++;
		}
	}
	return caught ? severity : -1;
}

}
