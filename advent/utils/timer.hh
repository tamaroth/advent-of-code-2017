/// @file
///
/// Time measuring.
///

#pragma once

#include <chrono>
#include <iostream>
#include <string_view>

namespace advent {

using TimeT = std::chrono::milliseconds;

template<typename Block, typename ...Args>
void execution(std::string_view task, Block block) {
		auto start = std::chrono::system_clock::now();
		block();
		auto duration = std::chrono::duration_cast< TimeT>(std::chrono::system_clock::now() - start);
		std::cout << task << "executed in " << duration.count() << "ms." << std::endl;;
}

}
