/// @file
///
/// Tests for Day09.
///

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "advent/days/09/stream_processing.hh"
#include "advent/utils/container.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class Day09Tests: public TestsBase, public Day09 {};
using TestPair = std::pair<std::string, int>;

TEST_F(Day09Tests, get_stream_score_returns_correct_score) {
	std::vector<TestPair> test_values = {
		{ "{}", 1 },
		{ "{{{}}}", 6 },
		{ "{{},{}}", 5 },
		{ "{{{},{},{{}}}}", 16 },
		{ "{<a>,<a>,<a>,<a>}", 1 },
		{ "{{<ab>},{<ab>},{<ab>},{<ab>}}", 9 },
		{ "{{<!!>},{<!!>},{<!!>},{<!!>}}", 9 },
		{ "{{<a!>},{<a!>},{<a!>},{<ab>}}", 3 },
	};

	for (auto& [stream, score] : test_values) {
		auto start = stream.begin();
		auto my_score = get_stream_score(start, stream.end(), 1);
		ASSERT_EQ(my_score, score);
	}
}

TEST_F(Day09Tests, skip_garbage_skips_garbage_in_stream) {
	std::vector<std::string> to_test = {
		R"(<{!>}>)",
		R"(<>)",
		R"(<random characters>)",
		R"(<<<<>)",
		R"(<{!>}>)",
		R"(<!!>)",
		R"(<!!!>>)",
		R"(<{o"i!a,<{i<a>)"
	};

	for (auto& stream : to_test) {
		auto start = stream.begin();
		skip_garbage(start, stream.end());
		ASSERT_TRUE(start+1 == stream.end());
	}
}


}
