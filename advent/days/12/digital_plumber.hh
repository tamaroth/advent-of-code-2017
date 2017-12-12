/// @file
///
/// Day 12: Digital Plumber
///

#pragma once

#include <map>
#include <vector>

#include "advent/utils/base.hh"

using DB = std::map<int, std::vector<int>>;
using Group = std::vector<int>;
using Groups = std::vector<Group>;

namespace advent {

class Day12: public Task {
public:
	Day12() = default;
	~Day12() override = default;

	void set_up() override;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	int solve_part_one_for_input(const DB& db);
	int solve_part_two_for_input(const DB& db);

	DB parse_lines_to_db(const std::vector<std::string>& lines);
	void get_group_with_id(const DB& db, Group& group, const int& id);

private:
	DB puzzle_db;
};

}
