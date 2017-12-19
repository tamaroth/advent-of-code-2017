/// @file
///
/// Day 19: A Series of Tubes.
///

#include <iostream>

#include "advent/days/19/tubes.hh"
#include "advent/utils/misc.hh"

namespace advent {

// Override.
void Day19::set_up() {
	maze = read_lines_from_file("day_19_input.txt");
}

// Override.
void Day19::solve_part_one() {
	std::cout << part_one()
			<< traverse_maze(maze)
		<< std::endl;
}

// Override.
void Day19::solve_part_two() {
	std::cout << part_two()
			<< traverse_maze(maze, true)
		<< std::endl;
}

// Override.
std::string Day19::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day19::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

///
/// Traverses the given maze, counts number of steps taken and collected letters.
///
std::string Day19::traverse_maze(const std::vector<std::string>& maze, bool part_two) {
	std::string result = "";
	const std::size_t maxY = maze.size();
	const std::size_t maxX = maze[0].size();

	std::size_t x = maze[0].find("|");
	std::size_t y = 0;
	std::size_t steps = 0;

	for (int dx = 0, dy = 1; maze[y][x] != ' '; x += dx, y+=dy, steps++) {
		auto mark = maze[y][x];
		if (std::isalpha(mark)) {
			result += mark;
		} else if (mark == '+') {
			dx = -std::exchange(dy, dx);
			if (x + dx >= maxX || y + dy >= maxY || maze[y + dy][x + dx] == ' ') {
				dx = -dx;
				dy = -dy;
			}
		}
	}
	if (part_two) {
		result = std::to_string(steps);
	}
	return result;
}

}
