/// @file
///
/// All solutions.
///

#pragma once

#include <map>
#include <memory>
#include <type_traits>

namespace advent {

class Task;

template<typename T>
class Tasks_Impl {
public:
	class Iterator {
	public:
		Iterator(int value): value(value) {}

		T operator*(void) const {
			return static_cast<T>(value);
		}

		void operator++( void ) {
			++value;
		}

		bool operator!=(Iterator rhs) {
			return value != rhs.value;
		}

	private:
		int value;
	};

};

template<typename T>
typename Tasks_Impl<T>::Iterator begin(Tasks_Impl<T>) {
	return typename Tasks_Impl<T>::Iterator(
		static_cast<typename std::underlying_type<T>::type>(T::kFirst)
	);
}

template<typename T>
typename Tasks_Impl<T>::Iterator end(Tasks_Impl<T>) {
	return typename Tasks_Impl<T>::Iterator(
		static_cast<typename std::underlying_type<T>::type>(T::kLast) + 1
	);
}

///
/// A list of all solved tasks.
///
enum class TaskID {
	kDay01,
	kDay02,
	kDay03,
	kDay04,
	kDay05,
	kDay06,
	kFirst = kDay01,
	kLast = kDay06,
	kAllDays
};

using Tasks = Tasks_Impl<TaskID>;

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
