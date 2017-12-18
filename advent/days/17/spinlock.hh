/// @file
///
/// Day 17: Spinlock.
///

#pragma once

#include <forward_list>
#include <string>

#include "advent/utils/base.hh"

namespace advent {

class Day17: public Task {
public:
	Day17() = default;
	~Day17() override = default;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	int spin(int step, int spins);

private:
	std::forward_list<int> list;
};

}
