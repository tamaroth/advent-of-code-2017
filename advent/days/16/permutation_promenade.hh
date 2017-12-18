/// @file
///
/// Day 16: Permutation Promenade.
///

#pragma once

#include <string>
#include <vector>

#include "advent/utils/base.hh"

namespace advent {

class Day16: public Task {
public:
	Day16() = default;
	~Day16() override = default;

	virtual void set_up() override;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	void dance(std::vector<char>& programs, std::vector<std::string>& commands);

	template<typename InitT, typename FuncT>
	int get_cycle_length(InitT& init, FuncT&& f) {
		int cycle = 1;
		auto next = f(init);

		while (next != init) {
			cycle++;
			next = f(next);
		}

		return cycle;
	}

private:
	std::vector<std::string> common_commands;
};

}
