/// @file
///
/// Day 13 tests.
///

#include <string>

#include <gmock/gmock.h>

#include "advent/days/13/packet_scanners.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class Day13Tests: public TestsBase, public Day13 {};

TEST_F(Day13Tests, compute_severity_computes_correctly) {
	Layers layers = {
		{0, 3},
		{1, 2},
		{4, 4},
		{6, 4},
	};

	auto severity = compute_severity(layers);

	EXPECT_EQ(severity, 24);
}

TEST_F(Day13Tests, solve_part_two_for_input_solves_correctly) {
	Layers layers = {
		{0, 3},
		{1, 2},
		{4, 4},
		{6, 4},
	};

	auto delay = solve_part_two_for_input(layers);

	EXPECT_EQ(delay, 10);
}

}
