/// @file
///
/// Day 04: High-Entropy Passphrases
///

#include <string>

#include "advent/utils/base.hh"

namespace advent {

class Day04: public Task {
public:
	Day04() = default;
	~Day04() override = default;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual void test_part_one() override;
	virtual void test_part_two() override;

private:
	bool solve_part_one_for_input(const std::string& input);
	bool solve_part_two_for_input(const std::string& input);
};

}
