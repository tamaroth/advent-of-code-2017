/// @file
///
/// Day 12: Digital Plumber
///

#include <regex>

#include "advent/days/12/digital_plumber.hh"
#include "advent/utils/container.hh"
#include "advent/utils/misc.hh"

namespace advent {

// Override.
void Day12::set_up() {
	auto lines = read_lines_from_file("day_12_input.txt");
	puzzle_db = parse_lines_to_db(lines);
}

// Override.
void Day12::solve_part_one() {
	std::cout << part_one()
			<< solve_part_one_for_input(puzzle_db)
		<< std::endl;
}

// Override.
void Day12::solve_part_two() {
	std::cout << part_two()
			<< solve_part_two_for_input(puzzle_db)
		<< std::endl;
}

// Override.
std::string Day12::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day12::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

///
/// Solves first part of the puzzle.
///
int Day12::solve_part_one_for_input(const DB& db) {
	Group group;
	int id = 0;
	get_group_with_id(db, group, id);
	return group.size();
}

///
/// Solves second part of the puzzle.
///
int Day12::solve_part_two_for_input(const DB& db) {
	Groups groups;
	for (const auto& entry : db) {
		bool already_in_group = false;
		for (const auto& group : groups) {
			if (contains(group, entry.first)) {
				already_in_group = true;
				break;
			}
		}

		if (already_in_group) {
			continue;
		}
		Group group;
		get_group_with_id(db, group, entry.first);
		groups.push_back(group);
	}
	return groups.size();
}

///
/// Converts lines from input files into the internal representation.
///
DB Day12::parse_lines_to_db(const std::vector<std::string>& lines) {
	DB db;
	for (const auto& line : lines) {
		auto divided = split(line, " <-> ");
		db[std::stoi(divided[0])] = split_to<int>(divided[1], ", ");
	}
	return db;
}

///
/// Reads from the database a group that contains the given ID.
///
void Day12::get_group_with_id(const DB& db, Group& group, const int& id) {
	if (contains(group, id)) {
		return;
	}

	group.push_back(id);
	auto connected = db.at(id);
	for (const auto& connection_id : connected) {
		get_group_with_id(db, group, connection_id);
	}
}

}
