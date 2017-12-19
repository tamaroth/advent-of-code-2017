/// @file
///
/// Day 18: Duet.
///

#pragma once

#include <condition_variable>
#include <deque>
#include <map>
#include <mutex>
#include <optional>
#include <ostream>
#include <string>
#include <vector>
#include <variant>

#include "advent/utils/base.hh"
#include "advent/utils/misc.hh"

namespace advent {

class Queue;

using REG = char;
using VALUE = long long;
using REGVALUE = std::variant<REG, VALUE>;
using Registers = std::map<REG, VALUE>;

struct CodeLine {
	std::string	instruction;
	REGVALUE first;
	REGVALUE second;
};

using CodeLines = std::vector<CodeLine>;

std::ostream& operator<<(std::ostream& os, const CodeLine& line);

class Queue {
public:

	/// @name Construction and Destruction
	/// @{
	Queue() = default;
	~Queue() = default;

	// Copying is forbidden.
	Queue(const Queue&) = delete;
	Queue& operator=(const Queue&) = delete;

	// Moving is forbidden.
	Queue(Queue&&) = delete;
	Queue& operator=(Queue&&) = delete;
	/// @}

	/// @name Queue manipulation.
	/// @{
	void push(const VALUE& value);
	int pop();
	/// @}

	/// @name Auxilliary functions.
	/// @{
	bool empty() const {
		return queue.empty();
	}
	void cleanup();
	bool waiting() const;
	/// @}

	/// The underlying Queue of values.
	std::deque<VALUE> queue;

	///
	/// Mutex for locking the queue between threads. Only one thread can have
	/// access to the queue at the same time.
	///
	std::mutex mutex;

	///
	/// Condition Variable to synchronize value passing between the threads.
	/// When a thread is popping a value from queue but queue is empty, that
	/// thread will release the mutex and wait for condition variable to be
	/// notified. When notification happens the queue will either process the
	/// value or terminate, based on whether a value has been added to the queue.
	///
	std::condition_variable cv;

	/// Should we finish?
	bool clean_up = false;

	/// Are we waiting?
	bool is_waiting = false;
};

struct CPU {
	CPU(CodeLines& code_lines, VALUE program_id);
	~CPU();

	/// @name CPU operations.
	/// @{
	void execute(CPU& cpu, bool part_two = false);
	bool execute_line(CPU& cpu, bool part_two);
	bool has_finished() const;
	int get_send_count() const;
	int get_sound_value() const;
	/// @}

	/// @name Registers operations.
	/// @{
	VALUE& set(const REGVALUE& to);
	VALUE get(const REGVALUE& regvalue);
	void set(const REGVALUE& to, const VALUE& from);
	void set(const REGVALUE& to, const REGVALUE& from);
	void add(const REGVALUE& to, const REGVALUE& from);
	void mul(const REGVALUE& to, const REGVALUE& from);
	void mod(const REGVALUE& to, const REGVALUE& from);
	/// @}

	/// Internal Queue for the given CPU.
	Queue queue;


private:
	/// Registers.
	Registers registers;

	/// Lines of code to execute.
	CodeLines code_lines;

	/// Instruction pointer.
	int ip = 0;

	/// Count of sent signals.
	int count = 0;

	/// Most recently sent signal.
	int sound = 0;
};

class Day18: public Task {
public:
	Day18() = default;
	~Day18() override = default;

	virtual void set_up() override;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

private:
	CodeLines code_lines;
};

CodeLine parse_line(const std::string& line);
CodeLines parse_lines(const std::vector<std::string>& lines);

}
