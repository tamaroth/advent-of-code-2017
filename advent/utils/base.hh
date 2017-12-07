/// @file
///
/// Base for all puzzles.
///

#pragma once

#include <string>

namespace advent {

///
/// A reprezentation of a single solution.
///
class Task {
public:
	/// @name Construction and Destruction
	/// @{
	Task();
	virtual ~Task();

	Task(const Task&);
	Task& operator=(const Task&);

	Task(Task&&);
	Task& operator=(Task&&);

	virtual void set_up() {};
	/// @}

	/// @name Puzzle Solutions
	/// @{

	///
	/// Solve first part of a puzzle.
	///
	virtual void solve_part_one() = 0;

	///
	/// Solve second part of a puzzle.
	///
	virtual void solve_part_two() = 0;
	/// @}

	/// @name Tests for Solutions
	/// @{

	/// @name Names of solutions.
	/// @{
	virtual std::string part_one() const = 0;
	virtual std::string part_two() const = 0;
	/// @}
};

}
