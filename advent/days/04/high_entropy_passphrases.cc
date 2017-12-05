/// @file
///
/// Day 04: High-Entropy Passphrases
///

#include <algorithm>

#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <unordered_set>
#include <vector>

#include "advent/days/04/high_entropy_passphrases.hh"
#include "advent/utils/assert.hh"
#include "advent/utils/misc.hh"
#include "advent/utils/tests.hh"

namespace advent {

namespace {

using LocalTestData = std::vector<BasicTestData<std::string, bool>>;

///
/// Input for Day 04 puzzle.
///
const std::string puzzle_input = "day_04_input.txt";

///
/// Test values and results for the first part of the puzzle.
///
const LocalTestData part_one_tests {
	{ "aa bb cc dd ee", true },
	{ "aa bb cc dd aa", false },
	{ "aa bb cc dd aaa", true },
};

///
/// Test value and results for the second part of the puzzle.
///
const LocalTestData part_two_tests {
	{ "abcde fghij", true },
	{ "abcde xyz ecdab", false },
	{ "a ab abc abd abf abj", true },
	{ "iiii oiii ooii oooi oooo", true },
	{ "oiii ioii iioi iiio", false },
};

std::vector<std::string> split(const std::string& input) {
	std::regex re(" ");
	std::sregex_token_iterator
		first{input.begin(), input.end(), re, -1},
		last;
	return {first, last};
}

}

// Override.
void Day04::solve_part_one() {
	std::cout << part_one();
	auto lines = read_lines_from_file<std::string>(puzzle_input);
	if (lines) {
		int correct_passphrases = 0;
		for (const auto& line : *lines) {
			if (solve_part_one_for_input(line)) {
				correct_passphrases++;
			}
		}
		std::cout << correct_passphrases << std::endl;
	}
}

// Override.
void Day04::solve_part_two() {
	std::cout << part_two();
	auto lines = read_lines_from_file<std::string>(puzzle_input);
	if (lines) {
		int correct_passphrases = 0;
		for (const auto& line : *lines) {
			if (solve_part_two_for_input(line)) {
				correct_passphrases++;
			}
		}
		std::cout << correct_passphrases << std::endl;
	}
}

// Override.
void Day04::test_part_one() {
	for (auto& [input, expected] : part_one_tests) {
		TEST_EQ(input, solve_part_one_for_input(input), expected);
	}
}

// Override.
void Day04::test_part_two() {
	for (auto& [input, expected] : part_two_tests) {
		TEST_EQ(input, solve_part_two_for_input(input), expected);
	}
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
