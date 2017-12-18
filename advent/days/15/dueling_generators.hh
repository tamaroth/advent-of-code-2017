/// @file
///
/// Day 15: Dueling Generators.
///

#pragma once

#include <random>

#include "advent/utils/base.hh"

namespace advent {

class Day15: public Task {
public:
	Day15() = default;
	~Day15() override = default;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	template<typename GetF>
	int compare_pairs(int init_a, int init_b, int checks, GetF func) {
		int all = 0;
		std::minstd_rand0 a(init_a);
		std::minstd_rand  b(init_b);

		do {
			auto [atc, btc] = func(a, b);
			if ((atc & 0xFFFF) == (btc & 0xFFFF)) {
				all++;
			}
		} while(--checks);
		return all;
	}
};

}
