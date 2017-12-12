/// @file
///
/// Day 04: High-Entropy Passphrases
///

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

#include "advent/days/04/high_entropy_passphrases.hh"

namespace advent {

// Override.
void Day04::set_up() {
	lines = read_lines_from_file("day_04_input.txt");
}

// Override.
void Day04::solve_part_one() {
	std::cout << part_one();
	int correct_passphrases = 0;
	for (const auto& line : lines) {
		if (solve_part_one_for_input(line)) {
			correct_passphrases++;
		}
	}
	std::cout << correct_passphrases << std::endl;
}

// Override.
void Day04::solve_part_two() {
	std::cout << part_two();
	int correct_passphrases = 0;
	for (const auto& line : lines) {
		if (solve_part_two_for_input(line)) {
			correct_passphrases++;
		}
	}
	std::cout << correct_passphrases << std::endl;
}

// Override.
std::string Day04::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day04::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

///
/// Method checks if the words in a passphrase are unique.
///
bool Day04::solve_part_one_for_input(const std::string& input) {
	auto words = split(input);
	std::unordered_set<std::string> unique;

	for (const auto& word : words) {
		if (unique.count(word)) {
			return false;
		}
		unique.insert(word);
	}

	return true;
}

///
/// Method checks if the words and their anagrams in the given passphrase are unique.
///
bool Day04::solve_part_two_for_input(const std::string& input) {
	auto words = split(input);
	std::unordered_set<std::string> unique;

	for (auto& word : words) {
		std::sort(word.begin(), word.end());
		if (unique.count(word)) {
			return false;
		}
		unique.insert(word);
	}

	return true;
}

}
