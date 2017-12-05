/// @file
///
/// Day 03: Spiral Memory
///

#pragma once

#include <vector>

#include "advent/utils/base.hh"
#include "advent/utils/tests.hh"

namespace advent {

class Day03: public Task {
public:
	Day03() = default;
	~Day03() override = default;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual void test_part_one() override;
	virtual void test_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

private:
	int solve_part_one_for_input(const int& input);
	int solve_part_two_for_input(const int& input);
};

}
