/// @file
///
/// Day 13: Packet Scanners
///

#pragma once

#include <vector>

#include "advent/utils/base.hh"

namespace advent {

using Layer = std::pair<int, int>;
using Layers = std::vector<Layer>;

class Day13: public Task {
public:
	Day13() = default;
	~Day13() override = default;

	virtual void set_up() override;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	int solve_part_one_for_input();
	int solve_part_two_for_input(const Layers& layers);

	bool is_caught(int layer, int depth);
	int compute_severity(const Layers& layers, int delay = 0);

private:
	Layers layers;
};

}
