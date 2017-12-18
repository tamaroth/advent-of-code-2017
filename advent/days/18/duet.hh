/// @file
///
/// Day 18: Duet.
///

#pragma once

#include <condition_variable>
#include <deque>
#include <map>
#include <mutex>
#include <string>
#include <vector>

#include "advent/utils/base.hh"

namespace advent {

class Queue;

using REG = char;
using VALUE = long long;

struct CodeLine {
	std::string	instruction;
	REG			destination;
	REG			source;
	VALUE		value;
};

struct CodeLines {
	CodeLines() = default;
	CodeLines(std::vector<std::string> source) {
		for (const auto& source_line : source) {
			lines.push_back(parse_line(source_line));
		}
	}
	~CodeLines() = default;

	static CodeLine parse_line(const std::string& line) {
		std::istringstream iss(line);
		CodeLine cl{};

		iss >> cl.instruction;
		iss >> cl.destination;
		if (cl.instruction != "snd" && cl.instruction != "rcv") {
			std::string last;
			iss >> last;
			if ((last.length() > 1) || isdigit(last[0])) {
				cl.value = std::stoll(last);
			} else {
				cl.source = last[0];
			}
		}
		return cl;
	}

	auto begin() { return lines.begin(); };
	auto end() { return lines.end(); };
	auto cbegin() { return lines.cbegin(); };
	auto cend() { return lines.cend(); };

private:
	std::vector<CodeLine> lines;
};

class Queue {
public:
	void add_to_queue(const VALUE& value) {
		std::unique_lock<std::mutex> lock(mutex);

		sent_values++;
		queue.push_back(value);
		lock.unlock();
		cv.notify_all();
	}

	int get_from_queue(const Queue& other) {
		std::unique_lock<std::mutex> lock(mutex);
		cv.wait(lock, [&]{
			waiting = true;
			if (other.waiting == waiting) {
				terminate = true;
				return true;
			}
			return queue.size() > 0;
		});

		if (terminate) {
			return -1;
		}

		auto result = queue.front();
		queue.pop_front();
		return result;
	}

	int get_sent_values() const { return sent_values; }

private:
	std::deque<VALUE> queue;
	std::mutex mutex;
	std::condition_variable cv;
	bool waiting = false;
	bool terminate = false;
	int sent_values = 0;
};

class Day18: public Task {
public:
	Day18() = default;
	~Day18() override = default;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	static int emulate(CodeLines& lines);
};

int thread_func(CodeLines& lines, VALUE program_id, Queue& this_q, Queue& other_q);

}
