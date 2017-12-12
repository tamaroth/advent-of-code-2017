/// @file
///
/// Day 11: Hex Ed
///

#pragma once

#include <string>

#include "advent/utils/base.hh"

namespace advent {

///
/// A representation of coordinates in a hexagonal map.
///
struct Coords {
	int x;
	int y;
	int max_distance = 0;

	/// @name Addition of coordinates.
	/// @{
	Coords& operator+=(const Coords& rhs) {
		this->x += rhs.x;
		this->y += rhs.y;
		max_distance = std::max(max_distance, distance_from_zero());
		return *this;
	}

	friend Coords operator+(Coords lhs, const Coords& rhs) {
		lhs += rhs;
		return lhs;
	}
	/// @}

	///
	/// Resets the coordinates to (0,0)
	///
	void reset() {
		x = 0;
		y = 0;
		max_distance = 0;
	}

	///
	/// @returns the distance of the current coordinate from the centre.
	///
	int distance_from_zero() const {
		if (x*y > 0) {
			return abs(x+y);
		}
		return std::max(abs(x), abs(y));
	}

	///
	/// @returns the maximum distance we have traversed from the centre.
	///
	int maximum_distance() const {
		return max_distance;
	}
};

class Day11: public Task {
public:
	Day11() = default;
	~Day11() override = default;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	int solve_part_one_for_input(const std::string& input);
	int solve_part_two_for_input();

private:
	Coords position{0,0};
};

}
