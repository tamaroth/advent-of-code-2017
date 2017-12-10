/// @file
///
/// Tests for Day10.
///

#include <string>
#include <vector>

#include <gmock/gmock.h>

#include "advent/days/10/knot_hash.hh"
#include "advent/utils/container.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class CircularBufferTests: public TestsBase {};

TEST_F(CircularBufferTests, get_gets_requested_range) {
	std::vector<int> result{3,4,5,0,1};
	auto cb = CircularBuffer(6);

	auto range = cb.get(3, 5);

	ASSERT_EQ(range, result);
}

TEST_F(CircularBufferTests, set_sets_new_values) {
	std::vector<int> result{6,6,2,6,6,6};
	std::vector<int> to_set{6,6,6,6,6};
	auto cb = CircularBuffer(6);

	cb.set(3, to_set);

	auto range = cb.get(0, 6);
	ASSERT_EQ(range, result);
}

class Day10Tests: public TestsBase, public Day10 {};

TEST_F(Day10Tests, get_hash_computes_correct_hash) {
	Buffer lengths = {3,4,1,5};

	auto hash = get_hash(5, lengths);

	ASSERT_EQ(hash, 12);
}

}
