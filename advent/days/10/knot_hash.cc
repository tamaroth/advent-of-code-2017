/// @file
///
/// Day 10: Knot Hash
///

#include <algorithm>
#include <iomanip>

#include "advent/days/10/knot_hash.hh"
#include "advent/utils/misc.hh"

namespace advent {

namespace {

///
/// Input for Day 09 puzzle.
///
const std::string puzzle_input = "129,154,49,198,200,133,97,254,41,6,2,1,255,0,191,108";

}

///
/// Construction of the default CircularBuffer.
///
CircularBuffer::CircularBuffer() : CircularBuffer(256) {}

///
/// Construction of the CircularBuffer for the given length.
///
CircularBuffer::CircularBuffer(int length) {
	buffer.reserve(length);
	for (int i = 0; i < length; i++) {
		buffer.push_back(i);
	}
}

///
/// Destruction of the CircularBuffer.
///
CircularBuffer::~CircularBuffer() = default;

///
/// Gets a copy of underlying buffer in the given range (can loop).
///
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

///
/// Sets the underlying buffer with the given one, replacing old values with
/// the new ones (can loop).
///
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

///
/// @returns the size of the underlying buffer.
///
std::size_t CircularBuffer::get_size() const {
	return buffer.size();
}

// Override.
void Day10::solve_part_one() {
	std::cout << part_one()
			<< solve_part_one_for_input(puzzle_input)
		<< std::endl;
}

// Override.
void Day10::solve_part_two() {
	std::cout << part_two()
			<< solve_part_two_for_input(puzzle_input)
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

///
/// Solves the first part of the puzzle.
/// Computes simple has of the given input with the given length of the
/// circular buffer.
///
int Day10::solve_part_one_for_input(const std::string& input, int len) {
	auto lengths = split_to<int>(input, ",");
	auto sub = get_hash(len, lengths).get(0, 2);
	return (sub[0]*sub[1]);
}

///
/// Solves the second part of the puzzle.
/// Computes the hash of the given input.
///
std::string Day10::solve_part_two_for_input(const std::string& input) {
	return compute_hash_for_input(input);
}

std::string Day10::compute_hash_for_input(const std::string& input) {
	std::vector<int> seq = {17, 31, 73, 47, 23};
	std::vector<int> lengths;
	for (const auto& ch : input) {
		lengths.push_back(static_cast<int>(ch));
	}
	lengths.insert(lengths.end(), seq.begin(), seq.end());

	auto sparse_hash = get_hash(256, lengths, 64);
	std::vector<int> dense;
	for (int i = 0; i < 16; i++) {
		auto sub = sparse_hash.get(i*16, 16);
		int r = 0;
		for (const auto& ch : sub) {
			r ^= ch;
		}
		dense.push_back(r);
	}

	std::stringstream stream;
	for (const auto& e : dense) {
		stream << std::setfill('0') << std::setw(2) << std::hex << e;
	}

	return stream.str();
}

///
/// Method computes knot hash for the given @a size with the given @a length of
/// the buffer in the number of @a rounds.
///
CircularBuffer Day10::get_hash(int size, const Buffer& lengths, int rounds) {
	CircularBuffer cb(size);
	int current_position = 0;
	int skip = 0;

	while (rounds--) {
		round(cb, current_position, skip, lengths);
	}

	return cb;
}

///
/// Computes a single round of the knot hash.
///
void Day10::round(CircularBuffer& cb, int& current_position, int& skip, const Buffer& lengths) {
	for (const auto& length : lengths) {
		auto sub = cb.get(current_position, length);
		std::reverse(sub.begin(), sub.end());
		cb.set(current_position, sub);
		current_position = (current_position + length + skip) % cb.get_size();
		skip++;
	}
}

}
