/// @file
///
/// Day 07: Recursive Circus
///

#pragma once

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "advent/utils/base.hh"

namespace advent {

using Children = std::vector<std::string>;
using Value = std::pair<int, std::string>;

struct DBEntry {
	int weight;
	Children children;
};

using DB = std::unordered_map<std::string, DBEntry>;

class Day07: public Task {
public:
	Day07() = default;
	~Day07() override = default;

	virtual void set_up() override;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	std::string solve_part_one_for_input(const DB& db);
	int solve_part_two_for_input(const DB& db, const std::string& root);

	DB lines_to_database(std::vector<std::string>& lines);
	DB file_to_database(const std::string& file_name);
	int weight_to_int(const std::string& weight_str);

	int find_correct_node_weight(const DB& db, const std::string& node, bool& found);
	std::optional<Value> find_bad_value_and_compute_difference(
		std::multimap<int, std::string>& weights);

private:
	std::string root;
	DB db;
};

}
