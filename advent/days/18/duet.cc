/// @file
///
/// Day 18: Duet.
///

#include <cassert>
#include <cctype>
#include <chrono>
#include <iostream>
#include <sstream>
#include <thread>

#include "advent/days/18/duet.hh"

namespace advent {

// Override.
void Day18::set_up() {
	auto lines = read_lines_from_file("day_18_input.txt");
	code_lines = parse_lines(lines);
}

// Override.
void Day18::solve_part_one() {
	CPU cpu(code_lines, 0);
	cpu.execute(cpu);
	std::cout << part_one()
			<< cpu.get_sound_value()
		<< std::endl;
}

// Override.
void Day18::solve_part_two() {
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

	std::cout << part_two()
			<< second.get_send_count()
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

///
/// Queue.
///

///
/// Adds a value to the queue and notifies this queue's CV about the change.
///
void Queue::push(const VALUE& value) {
	std::lock_guard lock(mutex);

	queue.push_back(value);

	cv.notify_one();
}

///
/// Removes an item from queue. If the queue is empty the function waits for
/// a signal from push (through CV) that indicates a new item has been added to
/// the queue. If both threads are waiting, it indicates a termination.
///
int Queue::pop() {
	std::unique_lock lock(mutex);
	cv.wait(lock, [&] {
		is_waiting = true;
		return !queue.empty() || clean_up; });

	if (clean_up) {
		return -1;
	}

	is_waiting = false;
	auto result = queue.front();
	queue.pop_front();
	return result;
}

///
/// Signal queue to clean up and exit.
///
void Queue::cleanup() {
	clean_up = true;
	cv.notify_one();
}

///
/// Are we waiting for new values in queue?
///
bool Queue::waiting() const {
	return is_waiting;
}

/// @name CPU Implementation.
/// @{

///
/// Constructor.
///
CPU::CPU(CodeLines& code_lines, VALUE program_id) : code_lines(code_lines) {
	set('p', program_id);
}

///
/// Destructor
///
CPU::~CPU() = default;

///
/// Execute a series of instructions that were inserted in the constructor until
/// end is reached (deadlock, jump out of block or special instruction reached)
///
void CPU::execute(CPU& cpu, bool part_two) {
	while (true) {
		if (execute_line(cpu, part_two)) {
			break;
		}
	}
}

///
/// Executes a single line of code.
///
bool CPU::execute_line(CPU& cpu, bool part_two) {
	using namespace std::chrono_literals;
	int next = 1;

	if (ip > static_cast<int>(code_lines.size())) {
		return true;
	}

	const auto& [cmd, p1, p2] = code_lines[ip];

	if (cmd == "snd") {
		// Increase count of sends.
		count++;
		// Store last signal sent.
		sound = get(p1);
		// Send the value to another queue.
		cpu.queue.push(sound);
	}
	else if (cmd == "rcv") {
		if (!part_two) {
			// For part1, terminate here.
			return true;
		}
		// Receive value from queue. If no value in queue, wait indefinitely.
		auto result = queue.pop();
		if (result == -1) {
			return true;
		}
		set(p1, result);
	}
	else if (cmd == "set") {
		// Set the register to value
		set(p1, p2);
	}
	else if (cmd == "add") {
		// Ass value to register.
		add(p1, p2);
	}
	else if (cmd == "mul") {
		// Multiply register by value.
		mul(p1, p2);
	}
	else if (cmd == "mod") {
		// Compute reminder of division of register by value.
		mod(p1, p2);
	}
	else if (cmd == "jgz") {
		// Jump to code.
		if (get(p1) > 0) {
			next = get(p2);
		}
	}
	ip += next;
	return ip >= static_cast<int>(code_lines.size());
}

///
/// Has the current thread finished? It's considered to be finished if the queue
/// is empty
///
bool CPU::has_finished() const {
	return queue.waiting() && queue.empty();
}

///
/// Returns the count of sent signals.
///
int CPU::get_send_count() const {
	return count;
}

///
/// Returns the value of the most recently sent signal.
///
int CPU::get_sound_value() const {
	return sound;
}

///
/// Get a value directly of from a register.
///
VALUE CPU::get(const REGVALUE& regvalue) {
	if (std::holds_alternative<REG>(regvalue)) {
		return registers[std::get<REG>(regvalue)];
	}
	return std::get<VALUE>(regvalue);
}

///
/// Gets a reference to a register.
///
VALUE& CPU::set(const REGVALUE& to) {
	return registers[std::get<REG>(to)];
}

///
/// Sets a register to the given value.
///
void CPU::set(const REGVALUE& to, const VALUE& from) {
	set(to) = from;
}

///
/// Sets a registers to the given value.
///
void CPU::set(const REGVALUE& to, const REGVALUE& from) {
	set(to) = get(from);
}

///
/// Adds the given value to the given register and stores the result in the
/// given register.
///
void CPU::add(const REGVALUE& to, const REGVALUE& from) {
	set(to) += get(from);
}

///
/// Multiplies the given register with the given value and stores the result
/// in the given register.
///
void CPU::mul(const REGVALUE& to, const REGVALUE& from) {
	set(to) *= get(from);
}

///
/// Computes the reminder of the division of the given register by the given
/// value and stores the result in the given register.
///
void CPU::mod(const REGVALUE& to, const REGVALUE& from) {
	set(to) %= get(from);
}

/// @}

///
/// Parses the given string line into the line of code.
///
CodeLine parse_line(const std::string& line) {
	CodeLine cl{};
	auto list = split(line);

	cl.instruction = list[0];
	if (isalpha(list[1][0])) {
		cl.first = list[1][0];
	} else {
		cl.first = std::stoll(list[1]);
	}
	if (list.size() > 2) {
		if (isalpha(list[2][0])) {
			cl.second = list[2][0];
		} else {
			cl.second = std::stoll(list[2]);
		}
	}

	return cl;
}

CodeLines parse_lines(const std::vector<std::string>& lines) {
	CodeLines code_lines;

	for (const auto& line : lines) {
		code_lines.emplace_back(std::move(parse_line(line)));
	}
	return code_lines;
}

}
