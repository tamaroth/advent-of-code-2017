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
		std::cerr << "\033[1;m[TEST FAILED]\033[0m " \
			<< __PRETTY_FUNCTION__ << " "\
			<< "for input: " << input << " " \
			<< "expected: " << expected << ", " \
			<< "got: " << got \
			<< std::endl; \
		return false; \
	} else { \
		std::cerr << "[TEST PASSED] " \
			<< __PRETTY_FUNCTION__ << " " \
			<< "for input: " << input \
			<< std::endl; \
	} \
}
