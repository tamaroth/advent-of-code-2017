/// @file
///
/// Day 18 tests.
///

#include <chrono>
#include <thread>

#include <gmock/gmock.h>

#include "advent/days/18/duet.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class Day18Tests: public TestsBase, public Day18 {};


TEST_F(Day18Tests, parse_line_parses_correctly) {
	std::string line = "set a -1";

	auto op = parse_line(line);

	ASSERT_EQ(op.instruction, "set");
	ASSERT_EQ(std::get<REG>(op.first), 'a');
	ASSERT_EQ(std::get<VALUE>(op.second), -1);
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
	auto code_lines = parse_lines(lines);
	CPU cpu(code_lines, 0);

	cpu.execute(cpu);

	ASSERT_EQ(cpu.get_sound_value(), 4);
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
	CodeLines code_lines = parse_lines(lines);

	CPU first(code_lines, 0);
	CPU second(code_lines, 1);

	std::thread thread_a([&] {
		first.execute(second, true);
	});
	std::thread thread_b([&] {
		second.execute(first, true);
	});

	thread_a.detach();
	thread_b.detach();

	while (!first.has_finished() || !second.has_finished());

	first.queue.cleanup();
	second.queue.cleanup();

	ASSERT_EQ(first.get_send_count(), 3);
}

}
