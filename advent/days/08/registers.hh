/// @file
///
/// Day 08: I Heard You Like Registers
///

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "advent/utils/base.hh"

namespace advent {

using Register = std::string;

class Day08: public Task {
public:
	Day08() = default;
	~Day08() override = default;

	virtual void set_up() override;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

public:
	enum class Operation {
		kInc,
		kDec,
	};

	enum class Cond {
		kLess,
		kLessOrEqual,
		kMore,
		kMoreOrEqual,
		kEqual,
		kDifferent,
	};

	struct Condition {
		Register	reg;
		Cond		cond;
		int			value;
	};

	struct InstructionLine {
		Register	reg;
		Operation	operation;
		int			value;
		Condition	condition;
	};

	using Instructions = std::vector<InstructionLine>;
	using Registers = std::unordered_map<Register, int>;

protected:
	int solve_part_one_for_input();
	int solve_part_two_for_input();

	InstructionLine parse_instruction_line(const std::string& line);
	Instructions convert_lines_to_instructions(const std::vector<std::string>& lines);
	Registers execute_instructions(const Instructions& instructions);
	int execute_instruction(Registers& registers, const InstructionLine& line);
	int get_maximal_register_value(const Registers& registers);
	int get_maximal_register_value_during_execution(const Day08::Instructions& instructions);

private:
	Instructions get_instructions_from_file(const std::string& file_name);
	bool check_condition(Registers& registers, const Condition& cond);
	Operation to_operation(const std::string& line);
	Condition to_condition(const std::string& reg, const std::string& cond, const std::string& val);

	Instructions instruction_set;
};

}
