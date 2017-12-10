/// @file
///
/// Day 09: Stream Processing
///

#include <limits>
#include <regex>

#include "advent/days/09/stream_processing.hh"
#include "advent/utils/assert.hh"
#include "advent/utils/container.hh"
#include "advent/utils/misc.hh"

namespace advent {

namespace {

///
/// Input for Day 09 puzzle.
///
const std::string puzzle_input = "day_09_input.txt";

}

void Day09::set_up() {
	garbage = 0;
	auto line = read_line_from_file(puzzle_input);
	if (line) {
		day_09_input = *line;
	}
}

// Override.
void Day09::solve_part_one() {
	std::cout << part_one()
			<< solve_part_one_for_input()
		<< std::endl;
}

// Override.
void Day09::solve_part_two() {
	std::cout << part_two()
			<< solve_part_two_for_input()
		<< std::endl;
}

std::string Day09::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}
std::string Day09::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

///
/// Finds the name of the root of the loaded tree.
///
int Day09::solve_part_one_for_input() {
	auto start = day_09_input.begin();
	return get_stream_score(start, day_09_input.end());
}

///
/// Finds the correct weight for the sole badly weigted node.
///
int Day09::solve_part_two_for_input() {
	return garbage;
}

///
/// Calculates the score of the stream.
///
int Day09::get_stream_score(std::string::iterator& start, const std::string::iterator& end,
		int sgl) {
	int score = 0;

	if (*start != '{') {
		return -1;
	}

	do {
		start++;
		if (*start == '{') {
			score += get_stream_score(start, end, sgl + 1);
		} else 	if (*start == '<') {
			skip_garbage(start, end);
		} else if (*start == '}') {
			return score + sgl;
		}
	} while (start != end);
	return score + sgl;
}

///
/// Skips the garba within the stream.
///
void Day09::skip_garbage(std::string::iterator& start, const std::string::iterator& end) {
	if (*start != '<') {
		return;
	}

	do {
		start++;
		if (*start == '!') {
			start += 1;
		} else if (*start == '>') {
			return;
		} else {
			garbage++;
		}
	} while (start != end);
}

}
