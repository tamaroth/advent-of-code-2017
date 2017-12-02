/// @file
///
/// Tests
///

#pragma once

template<typename T, typename R>
using BasicTestData = std::pair<T, R>;

using TestData = BasicTestData<std::string, int>;

#define TEST_EQ(input, got, expected) { \
	if (got != expected) { \
		std::cerr << "\033[1;31m[TEST FAILED]\033[0m " \
			<< __PRETTY_FUNCTION__ << " "\
			<< "for input: " << input << " " \
			<< "expected: " << expected << ", " \
			<< "got: " << got \
			<< std::endl; \
	} else { \
		std::cerr << "\033[1;32m[TEST PASSED]\033[0m " \
			<< __PRETTY_FUNCTION__ << " " \
			<< std::endl; \
	} \
}
