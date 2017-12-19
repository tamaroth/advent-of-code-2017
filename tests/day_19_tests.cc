/// @file
///
/// Day 19 tests.
///

#include <gmock/gmock.h>

#include "advent/days/19/tubes.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class Day19Tests: public TestsBase, public Day19 {};

TEST_F(Day19Tests, traverse_maze_traverses_the_maze) {
	std::vector<std::string> maze = {
		"     |          ",
		"     |  +--+    ",
		"     A  |  C    ",
		" F---|----E|--+ ",
		"     |  |  |  D ",
		"     +B-+  +--+ ",
	};

	auto result = traverse_maze(maze);

	ASSERT_EQ(result, "ABCDEF");
}

TEST_F(Day19Tests, traverse_maze_traverses_the_maze_and_counts_the_steps) {
	std::vector<std::string> maze = {
		"     |          ",
		"     |  +--+    ",
		"     A  |  C    ",
		" F---|----E|--+ ",
		"     |  |  |  D ",
		"     +B-+  +--+ ",
	};

	auto result = traverse_maze(maze, true);

	ASSERT_EQ(result, "38");
}


}
