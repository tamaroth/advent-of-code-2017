/// @file
///
/// Day 10: Knot Hash
///

#include <algorithm>
#include <regex>

#include "advent/days/10/knot_hash.hh"
#include "advent/utils/assert.hh"
#include "advent/utils/misc.hh"

namespace advent {

namespace {

///
/// Input for Day 09 puzzle.
///
const std::string puzzle_input = "129,154,49,198,200,133,97,254,41,6,2,1,255,0,191,108";

}

CircularBuffer::CircularBuffer() : CircularBuffer(256) {}

CircularBuffer::CircularBuffer(int length) {
	buffer.reserve(length);
	for (int i = 0; i < length; i++) {
		buffer.push_back(i);
	}
}

CircularBuffer::~CircularBuffer() = default;

Buffer CircularBuffer::get(std::size_t start, std::size_t length) const {
	Buffer result;
	auto max = buffer.size();
	if (length > max) {
		return result;
	}

	auto to_copy = std::min(max - start, length);
	auto from = buffer.begin() + start;
	auto to = from + to_copy;
	if (to_copy == length) {
		return Buffer{from, to};
	}

	result.insert(result.end(), from, to);

	auto rest = length - to_copy;
	result.insert(result.end(), buffer.begin(), buffer.begin() + rest);
	return result;
}

void CircularBuffer::set(std::size_t start, const Buffer& replacement) {
	auto max = buffer.size();
	auto length = replacement.size();

	if (replacement.size() > max) {
		return;
	}

	auto to_set = std::min(max - start, length);
	auto from = buffer.begin() + start;

	std::copy_n(replacement.begin(), to_set, from);

	if (to_set < length) {
		auto rest = length - to_set;
		std::copy_n(replacement.begin() + to_set, rest, buffer.begin());
	}
}

std::size_t CircularBuffer::get_size() const {
	return buffer.size();
}

// Override.
void Day10::set_up() {
	lengths = split_to<int>(puzzle_input, ",");
}

// Override.
void Day10::solve_part_one() {
	std::cout << part_one()
			<< solve_part_one_for_input()
		<< std::endl;
}

// Override.
void Day10::solve_part_two() {
	std::cout << part_two()
//			<< solve_part_two_for_input()
		<< std::endl;
}

// Override.
std::string Day10::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day10::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

int Day10::solve_part_one_for_input() {
	return get_hash(256, lengths);
}

///
/// Method computes knot hash for the given lengths with the given length of the buffer.
///
int Day10::get_hash(int size, const Buffer& lengths) {
	CircularBuffer cb(size);
	int current_position = 0;
	int skip = 0;
	for (const auto& length : lengths) {
		auto sub = cb.get(current_position, length);
		std::reverse(sub.begin(), sub.end());
		cb.set(current_position, sub);
		current_position = (current_position + length + skip) % cb.get_size();
		skip++;
	}

	auto sub = cb.get(0, 2);
	return sub[0]*sub[1];
}

}
