/// @file
///
/// All solutions.
///

#pragma once

#include <map>
#include <memory>
#include <type_traits>

namespace advent {

namespace Impl {

template<typename T>
class Tasks {
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
typename Tasks<T>::Iterator begin(Tasks<T>) {
	return typename Tasks<T>::Iterator(
		static_cast<typename std::underlying_type<T>::type>(T::kFirst)
	);
}

template<typename T>
typename Tasks<T>::Iterator end(Tasks<T>) {
	return typename Tasks<T>::Iterator(
		static_cast<typename std::underlying_type<T>::type>(T::kLast) + 1
	);
}

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
	kDay07,
	kFirst = kDay01,
	kLast = kDay07,
	kAllDays
};

using Tasks = Impl::Tasks<TaskID>;

}
