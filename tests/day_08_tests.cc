/// @file
///
/// Tests for Day08.
///

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "advent/days/08/registers.hh"
#include "advent/utils/container.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class Day08Tests: public TestsBase, public Day08 {};

TEST_F(Day08Tests, parse_instruction_line_parses_correctly) {
	std::string line = "b inc 5 if a > 1";

	auto parsed = parse_instruction_line(line);

	ASSERT_EQ(parsed.reg, "b");
	ASSERT_EQ(parsed.operation, Operation::kInc);
}

TEST_F(Day08Tests, convert_lines_to_instructions_converts_lines) {
	std::vector<std::string> lines = {
		"b inc 5 if a > 1",
		"a inc 1 if b < 5",
		"c dec -10 if a >= 1",
		"c inc -20 if c == 10",
	};

	auto instructions = convert_lines_to_instructions(lines);

	ASSERT_EQ(instructions.size(), 4);
	ASSERT_EQ(instructions[0].reg, "b");
}

TEST_F(Day08Tests, execute_instuction_line_executes_one_line) {
	std::string line = "a inc 1 if b < 5";
	Registers registers;

	auto value = execute_instruction(registers, parse_instruction_line(line));

	ASSERT_EQ(value, 1);
}

TEST_F(Day08Tests, execute_instructions_executes_instructions_in_order) {
	std::vector<std::string> lines = {
		"b inc 5 if a > 1",
		"a inc 1 if b < 5",
		"c dec -10 if a >= 1",
		"c inc -20 if c == 10",
	};
	auto instructions = convert_lines_to_instructions(lines);

	auto registers = execute_instructions(instructions);

	ASSERT_EQ(registers.size(), 3);
	ASSERT_TRUE(contains(registers, "a"));
	ASSERT_EQ(registers["a"], 1);
}

TEST_F(Day08Tests, get_maximal_register_value_returns_correct_value) {
		std::vector<std::string> lines = {
		"b inc 5 if a > 1",
		"a inc 1 if b < 5",
		"c dec -10 if a >= 1",
		"c inc -20 if c == 10",
	};
	auto instructions = convert_lines_to_instructions(lines);
	auto registers = execute_instructions(instructions);

	auto max = get_maximal_register_value(registers);

	ASSERT_EQ(max, 1);
}

TEST_F(Day08Tests, get_maximal_register_value_during_execution_returns_correct_value) {
		std::vector<std::string> lines = {
		"b inc 5 if a > 1",
		"a inc 1 if b < 5",
		"c dec -10 if a >= 1",
		"c inc -20 if c == 10",
	};
	auto instructions = convert_lines_to_instructions(lines);

	auto max = get_maximal_register_value_during_execution(instructions);

	ASSERT_EQ(max, 10);
}

}
