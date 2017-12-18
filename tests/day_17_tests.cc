/// @file
///
/// Day 17 tests.
///


#include <gmock/gmock.h>

#include "advent/days/17/spinlock.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class Day17Tests: public TestsBase, public Day17 {};

TEST_F(Day17Tests, spin_spins_correctly) {
	auto result = spin(3, 2017);

	ASSERT_EQ(result, 638);
}

}
