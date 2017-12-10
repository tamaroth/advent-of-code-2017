/// @file
///
/// Day 10: Knot Hash
///

#pragma once

#include <string>
#include <vector>

#include "advent/utils/base.hh"

namespace advent {

using Buffer = std::vector<int>;

class CircularBuffer {
public:
	CircularBuffer();
	CircularBuffer(int length);
	~CircularBuffer();

	Buffer get(std::size_t start, std::size_t length) const;
	void set(std::size_t start, const Buffer& replacement);
	std::size_t get_size() const;

private:
	Buffer buffer;
};

class Day10: public Task {
public:
	Day10() = default;
	~Day10() override = default;

	virtual void set_up() override;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	int solve_part_one_for_input();
	int solve_part_two_for_input();

	int get_hash(int length, const Buffer& lengths);

private:
	Buffer lengths;
};

}
