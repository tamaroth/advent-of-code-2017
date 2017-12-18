/// @file
///
/// Day 16: Permutation Promenade.
///

#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>

#include "advent/days/16/permutation_promenade.hh"
#include "advent/utils/misc.hh"

namespace advent {

// Override.
void Day16::set_up() {
	auto line = read_line_from_file("day_16_input.txt");
	common_commands = split(*line, ",");
}

// Override.
void Day16::solve_part_one() {
	std::vector<char> programs(16);
	std::iota(std::begin(programs), std::end(programs), 'a');
	dance(programs, common_commands);

	std::cout << part_one();
	for (const auto& ch : programs) {
		std::cout << ch;
	}
	std::cout << std::endl;
}

// Override.
void Day16::solve_part_two() {
	std::vector<char> programs(16);
	std::iota(std::begin(programs), std::end(programs), 'a');
	auto cycle_length = get_cycle_length(programs, [&](std::vector<char>& prgms) -> std::vector<char> {
		auto result = prgms;
		dance(result, common_commands);
		return result;
	});
	auto rest = 1'000'000'000 % cycle_length;
	while(rest--) {
		dance(programs, common_commands);
	}
	std::cout << part_two();
	for (const auto& ch : programs) {
		std::cout << ch;
	}
	std::cout << std::endl;
}

// Override.
std::string Day16::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day16::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

void Day16::dance(std::vector<char>& programs, std::vector<std::string>& commands) {
	for (const auto& command : commands) {
		std::istringstream iss(command);
		char cmd;
		iss >> cmd;
		switch (cmd) {
			case 's':
			{
				int i;
				iss >> i;
				std::rotate(
					std::begin(programs),
					std::prev(std::end(programs), i),
					std::end(programs)
				);
				break;
			}
			case 'x':
			{
				int i,j;
				(iss >> i).ignore(1, '/') >> j;
				std::iter_swap(
					std::begin(programs) + i,
					std::begin(programs) + j
				);
				break;
			}
			case 'p':
			{
				char a,b;
				(iss >> a).ignore(1, '/') >> b;
				std::iter_swap(
					std::find(std::begin(programs), std::end(programs), a),
					std::find(std::begin(programs), std::end(programs), b)
				);
				break;
			}
			default:
				break;
		}
	}
}

}
