/// @file
///
/// Day 15: Dueling Generators.
///

#include <iostream>

#include "advent/days/15/dueling_generators.hh"
#include "advent/utils/misc.hh"

namespace advent {

// Override.
void Day15::solve_part_one() {
	std::cout << part_one()
			<< compare_pairs(618, 814, 40'000'000, [](auto& a, auto& b) -> std::pair<int, int> {
				return {a(), b()};
			})
		<< std::endl;
}

// Override.
void Day15::solve_part_two() {

	std::cout << part_two()
			<< compare_pairs(618, 814, 5'000'000, [](auto& a, auto& b) -> std::pair<int, int> {
				int atc, btc;
				while ((atc = a()) % 4) {}
				while ((btc = b()) % 8) {}
				return {atc, btc};
			})
		<< std::endl;
}

// Override.
std::string Day15::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day15::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

}
