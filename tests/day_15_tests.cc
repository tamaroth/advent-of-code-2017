/// @file
///
/// Day 15 tests.
///

#include <string>

#include <gmock/gmock.h>

#include "advent/days/15/dueling_generators.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class Day15Tests: public TestsBase, public Day15 {};

TEST_F(Day15Tests, compare_pairs_compares_correctly) {
	auto result = compare_pairs(65, 8921, 5, [](auto& a, auto& b) -> std::pair<int, int> {
		return {a(), b()};
	});

	ASSERT_EQ(result, 1);
}

}
