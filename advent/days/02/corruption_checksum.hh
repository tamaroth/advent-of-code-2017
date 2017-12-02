/// @file
///
/// Day 02: Corruption Checksum
///

#pragma once

#include <vector>

#include "advent/utils/base.hh"
#include "advent/utils/tests.hh"

namespace advent {

using Row = std::vector<int>;
using Matrix = std::vector<Row>;
using LocalTestData = BasicTestData<Matrix, int>;

class Day02: public Task {
public:
	Day02() = default;
	~Day02() override = default;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual void test_part_one() override;
	virtual void test_part_two() override;

private:
	int solve_part_one_for_input(const Matrix& input);
	int solve_part_two_for_input(const Matrix& input);
};

}
