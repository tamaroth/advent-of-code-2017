/// @file
///
/// Day 05: A Maze of Twisty Trampolines, All Alike
///

#include <string>
#include <vector>

#include "advent/utils/base.hh"
#include "advent/utils/misc.hh"

namespace advent {

class Day05: public Task {
public:
	Day05() = default;
	~Day05() override = default;

	virtual void set_up() override;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	int solve_part_one_for_input(std::vector<int>& input);
	int solve_part_two_for_input(std::vector<int>& input);

private:
	Lines<int> lines;
};

}
