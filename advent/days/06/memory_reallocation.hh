/// @file
///
/// Day 06: Memory Reallocation
///

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include <boost/functional/hash.hpp>

#include "advent/utils/base.hh"

namespace advent {

class Day06: public Task {
public:
	Day06() = default;
	~Day06() override = default;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	int solve_part_one_for_input(std::vector<int>& input);
	int solve_part_two_for_input();

	using LocalData = std::unordered_map<std::vector<int>, int, boost::hash<std::vector<int>>>;

	LocalData visited_states;
	int cycles;
	int loop_length;
};

}
