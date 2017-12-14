/// @file
///
/// Day 14: Disk Defragmentation
///

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/connected_components.hpp>
#include <fmt/format.h>

#include "advent/days/10/knot_hash.hh"
#include "advent/days/14/disk_defragmentation.hh"
#include "advent/utils/misc.hh"

namespace advent {

namespace {

inline int char_to_value(char c) {
	return (c > '9') ? (c &~ 0x20) - 'A' + 10: (c - '0');
}

}

// Override.
void Day14::solve_part_one() {
	std::string input = "ugkiagan";
	std::cout << part_one()
			<< solve_part_one_for_input(input)
		<< std::endl;
}

// Override.
void Day14::solve_part_two() {
	std::string input = "ugkiagan";
	std::cout << part_two()
			<< solve_part_two_for_input(input)
		<< std::endl;
}

// Override.
std::string Day14::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day14::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

///
/// Solves first part of the puzzle.
///
int Day14::solve_part_one_for_input(const std::string& input) {
	int bits = 0;
	for (int i = 0; i < 128; i++) {
		auto hash = Day10::compute_hash_for_input(fmt::format("{}-{}", input, i));
		for (const auto& ch : hash) {
			bits += std::bitset<8>(char_to_value(ch)).count();
		}
	}
	return bits;
}

///
/// Solves second part of the puzzle using graps.
/// Using: http://www.boost.org/doc/libs/1_65_1/libs/graph/example/connected_components.cpp
///
int Day14::solve_part_two_for_input(const std::string& input) {
	using Graph = boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>;

	Graph graph;
	int id = 0;
	std::vector<std::vector<int>> bit_array(128);
	for (auto& ba : bit_array) {
		ba.resize(128, -1);
	}

	for (int i = 0; i < 128; i++) {
		auto hash = Day10::compute_hash_for_input(fmt::format("{}-{}", input, i));
		for (std::size_t j = 0; j < hash.length(); j++) {
			std::bitset<4> bits(char_to_value(hash[j]));
			for (int b = 0; b < 4; b++) {
				if (bits[3 - b]) {
					bit_array[i][j*4 + b] = id;
					if (i != 0 && bit_array[i - 1][j*4 + b] != -1) {
						add_edge(id, bit_array[i - 1][j*4 + b], graph);
					}
					if ((j != 0 || b != 0) && bit_array[i][j*4 + b - 1] != -1) {
						add_edge(id, bit_array[i][j*4 + b - 1], graph);
					}
					id++;
				}
			}
		}
	}

	std::vector<int> components(boost::num_vertices(graph));
	return connected_components(graph, &components[0]);
}

}
