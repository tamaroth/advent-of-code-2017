/// @file
///
/// Day 18: Duet.
///

#include <cctype>
#include <iostream>
#include <sstream>
#include <thread>

#include "advent/days/18/duet.hh"
#include "advent/utils/misc.hh"

namespace advent {

namespace {

VALUE load_reg_or_value(const CodeLine& line, std::map<REG, VALUE>& rs) {
	return (line.source ? rs[line.source] : line.value);
}

}

int thread_func(CodeLines& lines, VALUE program_id, Queue& this_q, Queue& other_q) {
	std::map<REG, VALUE> rs;
	rs['p'] = program_id;

	for (auto it = lines.begin(); it != lines.end(); it++) {
		auto distance_from_start = it - lines.begin();
		auto distance_from_end = lines.end() - it;
		auto line = *it;

		if (line.instruction == "snd") {
			other_q.add_to_queue(load_reg_or_value(line, rs));
		} else if (line.instruction == "set") {
			rs[line.destination] = load_reg_or_value(line, rs);
		} else if (line.instruction == "add") {
			rs[line.destination] += load_reg_or_value(line, rs);
		} else if (line.instruction == "mul") {
			rs[line.destination] *= load_reg_or_value(line, rs);
		} else if (line.instruction == "mod") {
			rs[line.destination] %= load_reg_or_value(line, rs);
		} else if (line.instruction == "rcv") {
			auto value = this_q.get_from_queue(other_q);
			if (value == -1) {
				return value;
			}
			rs[line.destination] = value;
		} else if (line.instruction == "jgz") {
			if (rs[line.destination]) {
				auto distance = load_reg_or_value(line, rs) - 1;
				if (distance > 0 && distance >= distance_from_end) {
					return -1;
				}
				if (distance < 0 && distance_from_start + distance < 0) {
					return -1;
				}
				it += distance;

			}
		}
	}
	return -1;
}

// Override.
void Day18::solve_part_one() {
	auto lines = read_lines_from_file("day_18_input.txt");
	CodeLines code_lines(lines);
	std::cout << part_one()
			<< emulate(code_lines)
		<< std::endl;
}

// Override.
void Day18::solve_part_two() {
	auto lines = read_lines_from_file("day_18_input.txt");
	CodeLines code_lines_a(lines);
	CodeLines code_lines_b(lines);

	Queue queue_a; VALUE program_id_a = 0;
	Queue quque_b; VALUE program_id_b = 1;

	std::thread thread_a(thread_func,
		std::ref(code_lines_a),
		program_id_a,
		std::ref(queue_a),
		std::ref(quque_b)
	);
	std::thread thread_b(thread_func,
		std::ref(code_lines_b),
		program_id_b,
		std::ref(quque_b),
		std::ref(queue_a)
	);

	thread_a.join();
	thread_b.join();

	std::cout << part_two()
			<< queue_a.get_sent_values()
		<< std::endl;
}

// Override.
std::string Day18::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day18::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

int Day18::emulate(CodeLines& lines) {
	std::map<REG, VALUE> rs;

	int sound_reg = 0;
	for (auto it = lines.begin(); it != lines.end(); it++) {
		auto distance_from_start = it - lines.begin();
		auto distance_from_end = lines.end() - it;
		auto line = *it;
		if (line.instruction == "snd") {
			sound_reg = rs[line.destination];
		} else if (line.instruction == "set") {
			rs[line.destination] = load_reg_or_value(line, rs);
		} else if (line.instruction == "add") {
			rs[line.destination] += load_reg_or_value(line, rs);
		} else if (line.instruction == "mul") {
			rs[line.destination] *= load_reg_or_value(line, rs);
		} else if (line.instruction == "mod") {
			rs[line.destination] %= load_reg_or_value(line, rs);
		} else if (line.instruction == "rcv") {
			if (rs[line.destination]) {
				return sound_reg;
			}
		} else if (line.instruction == "jgz") {
			if (rs[line.destination]) {
				auto distance = load_reg_or_value(line, rs) - 1;
				if (distance > 0 && distance >= distance_from_end) {
					return -1;
				}
				if (distance < 0 && distance_from_start + distance < 0) {
					return -1;
				}
				it += distance;

			}
		}
	}
	return -1;
}

}
