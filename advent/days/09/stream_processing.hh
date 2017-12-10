/// @file
///
/// Day 09: Stream Processing
///

#pragma once

#include <string>

#include "advent/utils/base.hh"

namespace advent {

class Day09: public Task {
public:
	Day09() = default;
	~Day09() override = default;

	virtual void set_up() override;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	int solve_part_one_for_input();
	int solve_part_two_for_input();

	int get_stream_score(std::string::iterator& start, const std::string::iterator& end, int sgl = 1);
	void skip_garbage(std::string::iterator& start, const std::string::iterator& end);

private:
	std::string day_09_input;
	int garbage;
};

}
