/// @file
///
/// Time measuring.
///

#pragma once

#include <chrono>
#include <iostream>
#include <string>
#include <sstream>

namespace advent {

using ms = std::chrono::milliseconds;
using us = std::chrono::microseconds;

template<typename Timepoint>
std::string duration_to_string(Timepoint start, Timepoint end) {
	std::ostringstream os;
	if (auto elapsed = std::chrono::duration_cast<ms>(end-start); elapsed.count()) {
		os << elapsed.count() << "ms.";
	} else {
		os << std::chrono::duration_cast<us>(end-start).count() << "µs.";;
	}
	return os.str();
}

template<typename Block, typename ...Args>
void measure_execution_time(std::string_view task, Block block) {
		auto start = std::chrono::high_resolution_clock::now();
		block();
		auto end = std::chrono::high_resolution_clock::now();
		std::cout << task << "executed in " << duration_to_string(start, end) << std::endl;
}

}
