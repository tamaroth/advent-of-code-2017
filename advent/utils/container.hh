/// @file
///
/// Container utilities.
///

#pragma once

namespace advent {

/// @name General Operations
/// @{

///
/// Returns @c true if @a container contains @a item, @c false otherwise.
///
/// @tparam Container Type of the container.
/// @tparam Item Type of the items that @a container holds.
///
template<typename Container, typename Item>
bool contains(const Container& container, const Item& item) {
	return container.find(item) != container.end();
}

/// @}

}
