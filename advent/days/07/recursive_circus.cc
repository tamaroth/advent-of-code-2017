/// @file
///
/// Day 07: Recursive Circus
///

#include <algorithm>
#include <iostream>
#include <regex>
#include <stdexcept>

#include <boost/algorithm/string/replace.hpp>

#include "advent/days/07/recursive_circus.hh"
#include "advent/utils/container.hh"

namespace advent {

using namespace std::string_literals;

// Override
void Day07::set_up() {
	db = file_to_database("day_07_input.txt");
}

// Override.
void Day07::solve_part_one() {
	root = solve_part_one_for_input(db);

	std::cout << part_one()
			<< root
		<< std::endl;
}

// Override.
void Day07::solve_part_two() {
	std::cout << part_two()
			<< solve_part_two_for_input(db, root)
		<< std::endl;
}

// Override.
std::string Day07::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day07::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

///
/// Finds the name of the root of the loaded tree.
///
std::string Day07::solve_part_one_for_input(const DB& db) {
	for(const auto& look_for : db) {
		bool is_root = true;
		for (const auto& look_in : db) {
			auto children = look_in.second.children;
			if (children.size()) {
				if (std::find( children.begin(), children.end(), look_for.first)
						!= children.end()) {
					is_root = false;
					break;
				}
			}
		}
		if (is_root) {
			return look_for.first;
		}
	}
	return "";
}

///
/// Finds the correct weight for the sole badly weigted node.
///
int Day07::solve_part_two_for_input(const DB& db, const std::string& root) {
	bool found = false;
	auto result = find_correct_node_weight(db, root, found);
	assert(found);
	return result;
}

///
/// Converts string to integer.
///
int Day07::weight_to_int(const std::string& weight_str) {
	std::regex rx(R"(\((\w+)\))");
	std::smatch match;
	if (std::regex_search(weight_str.begin(), weight_str.end(), match, rx)) {
		return std::stoi(match[1]);
	}
	return -1;
}

///
/// Converts lines to a database representation.
///
DB Day07::lines_to_database(Lines<>& lines) {
	DB db;
	for (auto& line : lines) {
		line.erase(std::remove(line.begin(), line.end(), ','), line.end());
		auto split_line = split(line);
		if (split_line.size() < 2) {
			throw std::logic_error("line is too short");
		}

		std::vector<std::string> children{};
		if (split_line.size() > 3) {
			auto it = split_line.begin() + 2;

			if (*it != "->") {
				throw std::logic_error("3rd parameter should be ->");
			}

			while (++it != split_line.end()) {
				children.push_back(*it);
			}
		}

		db[split_line[0]] = DBEntry{weight_to_int(split_line[1]), children};
	}
	return db;
}

///
/// Read all lines from a file and coverts those lines to a database representation.
///
DB Day07::file_to_database(const std::string& file_name) {
	auto lines = read_lines_from_file<std::string>(file_name);
	return lines_to_database(lines);
}

///
/// Locates the node that has incorrect weight and calculates its proper value.
///
int Day07::find_correct_node_weight(const DB& db, const std::string& node, bool& found) {
	if (!contains(db, node)) {
		throw std::invalid_argument("node does not exist in the database");
	}

	auto& self = db.at(node);
	int weight = self.weight;

	std::multimap<int, std::string> children_weights;
	for (const auto& child : self.children) {
		auto child_weight = find_correct_node_weight(db, child, found);
		if (found) {
			return child_weight;
		}
		weight += child_weight;
		children_weights.insert(std::make_pair(child_weight, child));
	}

	auto bad_value = find_bad_value_and_compute_difference(children_weights);
	if (bad_value) {
		auto kid = db.at(bad_value->second);
		found = true;
		return kid.weight - bad_value->first;
	}

	return weight;
}

///
/// Finds mismatched value and computes the difference between it and the correct value.
///
std::optional<Value> Day07::find_bad_value_and_compute_difference(
		std::multimap<int, std::string>& weights) {
	int difference = 0;
	int last_good = 0;
	std::string node;

	if (weights.size() < 2) {
		return std::nullopt;
	}

	for (const auto& [weight, name] : weights) {
		if (weights.count(weight) == 1) {
			difference = weight;
			node = name;
			break;
		}
		last_good = weight;
	}

	if (!difference) {
		return std::nullopt;
	}

	if (!last_good) {
		for (const auto& weight : weights) {
			if (weight.first != difference) {
				last_good = weight.first;
				break;
			}
		}
	}

	return std::optional(std::make_pair(difference - last_good, node));
}

}
