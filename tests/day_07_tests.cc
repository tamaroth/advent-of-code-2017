/// @file
///
/// Tests for Day07.
///

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "advent/days/07/recursive_circus.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class Day07Tests: public TestsBase, public Day07 {};

TEST_F(Day07Tests, lines_to_database_correctly_convers_string_lines_to_database) {
	std::vector<std::string> lines = {
		"pbga (66)",
		"xhth (57)",
		"ebii (61)",
		"havc (66)",
		"ktlj (57)",
		"fwft (72) -> ktlj, cntj, xhth",
		"qoyq (66)",
		"padx (45) -> pbga, havc, qoyq",
		"tknk (41) -> ugml, padx, fwft",
		"jptl (61)",
		"ugml (68) -> gyxo, ebii, jptl",
		"gyxo (61)",
		"cntj (57)",
	};

	auto db = lines_to_database(lines);

	ASSERT_EQ(db.size(), 13);
	ASSERT_EQ(db["xhth"].weight, 57);
	ASSERT_EQ(db["fwft"].children.size(), 3);
	ASSERT_EQ(db["fwft"].children[0], "ktlj");
}

TEST_F(Day07Tests, find_bad_value_and_compute_difference_finds_bad_value) {
	std::multimap<int, std::string> weights = {
		{251, "ugml"},
		{243, "padx"},
		{243, "fuft"},
	};

	auto bad_value = find_bad_value_and_compute_difference(weights);

	ASSERT_TRUE(bad_value);
	ASSERT_EQ(bad_value->first, 8);
	ASSERT_EQ(bad_value->second, "ugml");
}

TEST_F(Day07Tests, find_bad_value_and_compute_difference_does_not_find_bad_value) {
	std::multimap<int, std::string> weights = {
		{243, "ugml"},
		{243, "padx"},
		{243, "fuft"},
	};

	auto bad_value = find_bad_value_and_compute_difference(weights);

	ASSERT_FALSE(bad_value);
}

TEST_F(Day07Tests, part_one_is_computed_correctly) {
	const DB db = {
		{ "pbga", {66, {}} },
		{ "xhth", {57, {}} },
		{ "ebii", {61, {}} },
		{ "havc", {66, {}} },
		{ "ktlj", {57, {}} },
		{ "fwft", {72, { "ktlj", "cntj", "xhth" }} },
		{ "qoyq", {66, {}} },
		{ "padx", {45, { "pbga", "havc", "qoyq" }} },
		{ "tknk", {41, { "ugml", "padx", "fwft" }} },
		{ "jptl", {61, {}} },
		{ "ugml", {68, { "gyxo", "ebii", "jptl" }} },
		{ "gyxo", {61, {}} },
		{ "cntj", {57, {}} },
	};

	EXPECT_EQ(solve_part_one_for_input(db), "tknk");
}

TEST_F(Day07Tests, part_two_is_computed_correctly) {
	const DB db = {
		{ "pbga", {66, {}} },
		{ "xhth", {57, {}} },
		{ "ebii", {61, {}} },
		{ "havc", {66, {}} },
		{ "ktlj", {57, {}} },
		{ "fwft", {72, { "ktlj", "cntj", "xhth" }} },
		{ "qoyq", {66, {}} },
		{ "padx", {45, { "pbga", "havc", "qoyq" }} },
		{ "tknk", {41, { "ugml", "padx", "fwft" }} },
		{ "jptl", {61, {}} },
		{ "ugml", {68, { "gyxo", "ebii", "jptl" }} },
		{ "gyxo", {61, {}} },
		{ "cntj", {57, {}} },
	};

	auto weight = solve_part_two_for_input(db, "tknk");

	ASSERT_EQ(weight, 60);
}

}
