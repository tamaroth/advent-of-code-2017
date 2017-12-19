/// @file
///
/// Day 19: A Series of Tubes.
///

#pragma once

#include <string>
#include <vector>

#include "advent/utils/base.hh"

namespace advent {

class Day19: public Task {
public:
	Day19() = default;
	~Day19() override = default;

	virtual void set_up() override;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	std::string traverse_maze(const std::vector<std::string>& maze, bool part_two = false);

private:
	std::vector<std::string> maze;
};

}
