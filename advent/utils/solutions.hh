/// @file
///
/// All solutions.
///

#pragma once

#include <map>
#include <memory>
#include <type_traits>

#include "advent/utils/tasks.hh"

namespace advent {

class Task;

///
/// A representation of all solved tasks.
///
class Solutions {
public:
	/// @name Construction and Destruction.
	/// @{
	Solutions();
	~Solutions();

	Solutions(const Solutions&);
	Solutions& operator=(const Solutions&);

	Solutions(Solutions&&);
	Solutions& operator=(Solutions&&);
	/// @}

	/// @name Access to tasks.
	/// @{
	std::shared_ptr<Task> get_task(TaskID task);
	/// @}

private:
	/// Cache containing loaded solutions.
	std::map<TaskID, std::shared_ptr<Task>> solutions;
};

}
