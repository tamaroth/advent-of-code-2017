/// @file
///
/// Day 17: Spinlock.
///

#include <iostream>

#include "advent/days/17/spinlock.hh"
#include "advent/utils/misc.hh"

namespace advent {

// Override.
void Day17::solve_part_one() {
	std::cout << part_one()
			<< spin(329, 2017)
		<< std::endl;
}

// Override.
void Day17::solve_part_two() {
	int value_at_one = 1;
	int current = 2;
	int index = 1;

	while (current <= 50'000'000) {
		index = (index + 329) % current + 1;
		if (index == 1) {
			value_at_one = current;
		}
		current++;
	}
	std::cout << part_two()
			<< value_at_one
		<< std::endl;
}

// Override.
std::string Day17::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day17::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

int Day17::spin(int steps, int spins) {
	list.clear();
	list = {0};

	int current = 1;
	auto iter = list.begin();
	while (current <= spins) {
		int step = 0;
		while (step++ < steps) {
			iter++;
			if (iter == list.end()) {
				iter = list.begin();
			}
		}
		iter = list.insert_after(iter, current++);
	}
	return *(++iter);
}


}
