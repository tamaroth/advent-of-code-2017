/// @file
///
/// Day 18 tests.
///

#include <thread>

#include <gmock/gmock.h>

#include "advent/days/18/duet.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class Day18Tests: public TestsBase, public Day18 {};

TEST_F(Day18Tests, parse_line_parses_correctly) {
	std::string line = "set a -1";

	auto op = CodeLines::parse_line(line);

	ASSERT_EQ(op.instruction, "set");
	ASSERT_EQ(op.destination, 'a');
	ASSERT_EQ(op.value, -1);
}

TEST_F(Day18Tests, emulate_instructions_emulates_correctly) {
	std::vector<std::string> lines = {
		"set a 1",
		"add a 2",
		"mul a a",
		"mod a 5",
		"snd a",
		"set a 0",
		"rcv a",
		"jgz a -1",
		"set a 1",
		"jgz a -2",
	};
	CodeLines code_lines(lines);

	auto result = emulate(code_lines);

	ASSERT_EQ(result, 4);
}

TEST_F(Day18Tests, run_parallel_works) {
	std::vector<std::string> lines = {
		"snd 1",
		"snd 2",
		"snd p",
		"rcv a",
		"rcv b",
		"rcv c",
		"rcv d",
	};
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

	ASSERT_EQ(queue_a.get_sent_values(), 3);
}

}
