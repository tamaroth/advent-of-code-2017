/// @file
///
/// Day 06: Memory Reallocation
///

#include <limits>
#include <regex>

#include "advent/days/08/registers.hh"
#include "advent/utils/assert.hh"
#include "advent/utils/container.hh"
#include "advent/utils/misc.hh"

namespace advent {

namespace {

///
/// Input for Day 08 puzzle.
///
const std::string puzzle_input = "day_08_input.txt";

}

// Override.
void Day08::set_up() {
	instruction_set = get_instructions_from_file(puzzle_input);
}

// Override.
void Day08::solve_part_one() {
	std::cout << part_one()
			<< solve_part_one_for_input()
		<< std::endl;
}

// Override.
void Day08::solve_part_two() {
	std::cout << part_two()
			<< solve_part_two_for_input()
		<< std::endl;
}

std::string Day08::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}
std::string Day08::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

///
/// Finds the name of the root of the loaded tree.
///
int Day08::solve_part_one_for_input() {
	auto registers = execute_instructions(instruction_set);
	return get_maximal_register_value(registers);
}

///
/// Finds the correct weight for the sole badly weigted node.
///
int Day08::solve_part_two_for_input() {
	return get_maximal_register_value_during_execution(instruction_set);
}

Day08::InstructionLine Day08::parse_instruction_line(const std::string& line) {
	std::regex rx(R"((\w+) (inc|dec) ([-0-9]+) if (\w+) (<=|>=|<|>|!=|==) ([-0-9]+))");
	std::smatch match;
	if (!regex_search(line, match, rx)) {
		throw std::invalid_argument(line.c_str());
	}
	return InstructionLine{
		match.str(1),
		to_operation(match.str(2)),
		std::stoi(match.str(3)),
		to_condition(match.str(4), match.str(5), match.str(6))
	};
}

Day08::Instructions Day08::convert_lines_to_instructions(const std::vector<std::string>& lines) {
	Instructions instructions;
	for (const auto& line : lines) {
		instructions.emplace_back(parse_instruction_line(line));
	}
	return instructions;
}

Day08::Registers Day08::execute_instructions(const Day08::Instructions& instructions) {
	Registers registers;
	for (const auto& instruction : instructions) {
		execute_instruction(registers, instruction);
	}
	return registers;
}

int Day08::get_maximal_register_value_during_execution(
	const Day08::Instructions& instructions) {
	Registers registers;
	int max = std::numeric_limits<int>::min();
	for (const auto& instruction : instructions) {
		max = std::max(execute_instruction(registers, instruction), max);
	}
	return max;
}

int Day08::execute_instruction(Registers& registers, const InstructionLine& instruction) {
	if (!contains(registers, instruction.reg)) {
		registers[instruction.reg] = 0;
	}

	if (check_condition(registers, instruction.condition)) {
		if (instruction.operation == Operation::kInc) {
			registers[instruction.reg] += instruction.value;
		} else { // kDec
			registers[instruction.reg] -= instruction.value;
		}
	}
	return registers[instruction.reg];
}

int Day08::get_maximal_register_value(const Registers& registers) {
	int max = std::numeric_limits<int>::min();
	for (const auto& reg : registers) {
		max = std::max(reg.second, max);
	}
	return max;
}

Day08::Instructions Day08::get_instructions_from_file(const std::string& file_name) {
	auto lines = read_lines_from_file<std::string>(file_name);
	if (!lines) {
		throw std::invalid_argument("could not read any lines from the file");
	}
	return convert_lines_to_instructions(*lines);
}

Day08::Operation Day08::to_operation(const std::string& line) {
	if (line == "inc") {
		return Operation::kInc;
	}
	return Operation::kDec;
}

Day08::Condition Day08::to_condition(const std::string& reg,
		const std::string& cond, const std::string& val) {
	Cond cd;
	if (cond == "<") {
		cd = Cond::kLess;
	} else if (cond == ">") {
		cd = Cond::kMore;
	} else if (cond == "==") {
		cd = Cond::kEqual;
	} else if (cond == "!=") {
		cd = Cond::kDifferent;
	} else if (cond == "<=") {
		cd = Cond::kLessOrEqual;
	} else if (cond == ">=") {
		cd = Cond::kMoreOrEqual;
	}
	return Condition{
		reg,
		cd,
		std::stoi(val)
	};
}

bool Day08::check_condition(Registers& registers, const Condition& cond) {
	if (!contains(registers, cond.reg)) {
		registers[cond.reg] = 0;
	}

	auto to_test = registers[cond.reg];
	switch (cond.cond) {
		case Cond::kLess:
			return to_test < cond.value;
		case Cond::kMore:
			return to_test > cond.value;
		case Cond::kEqual:
			return to_test == cond.value;
		case Cond::kDifferent:
			return to_test != cond.value;
		case Cond::kLessOrEqual:
			return to_test <= cond.value;
		default:
			return to_test >= cond.value;
	}
}

}
