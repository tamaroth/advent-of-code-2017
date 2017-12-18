/// @file
///
/// Day 16 tests.
///

#include <numeric>
#include <string>
#include <vector>

#include <gmock/gmock.h>

#include "advent/days/16/permutation_promenade.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class Day16Tests: public TestsBase, public Day16 {};

TEST_F(Day16Tests, dance_performs_entire_dance) {
	std::vector<char> programs(5);
	std::iota(std::begin(programs), std::end(programs), 'a');
	std::vector<std::string> commands = {
		"s1",
		"x3/4",
		"pe/b",
	};

	dance(programs, commands);

	std::vector<char> result = {'b', 'a', 'e', 'd', 'c'};
	ASSERT_EQ(programs, result);
}

TEST_F(Day16Tests, get_cycle_length_computes_cycle_length_correctly) {
	std::vector<char> in = {'a', 'b', 'c', 'd', 'e'};

	auto cycle_length = get_cycle_length(in, [](std::vector<char>& src) -> std::vector<char> {
		auto result = src;
		std::rotate(
			std::begin(result),
			std::end(result) - 1,
			std::end(result)
		);
		return result;
	});

	ASSERT_EQ(cycle_length, 5);
}

TEST_F(Day16Tests, get_cycle_length_does_not_modify_source) {
	int i = 1;
	get_cycle_length(i, [](int i){
		return (i+1)%7;
	});

	ASSERT_EQ(i, 1);
}

}
