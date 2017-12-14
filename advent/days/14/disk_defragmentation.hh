/// @file
///
/// Day 14: Disk Defragmentations
///

#pragma once

#include <vector>

#include "advent/utils/base.hh"

namespace advent {

class Day14: public Task {
public:
	Day14() = default;
	~Day14() override = default;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	int solve_part_one_for_input(const std::string& input);
	int solve_part_two_for_input(const std::string& input);
};

}
