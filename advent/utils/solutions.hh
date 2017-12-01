/// @file
///
/// All solutions.
///

#pragma once

#include <map>
#include <memory>

#include "base.hh"

namespace advent {

enum class Task {
	kDay01,
	kFinished
};

class Solutions {
public:
	Solutions();
	~Solutions();

	std::shared_ptr<Day> get_or_create(Task task);

private:
	std::map<Task, std::shared_ptr<Day>> solutions;
};

}
