/// @file
///
/// Day 21 tests.
///


#include <gmock/gmock.h>

#include "advent/days/21/fractal_art.hh"
#include "advent/utils/misc.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class ImageTests: public TestsBase {};

TEST_F(ImageTests, from_line_converts_string_to_image) {
	std::string line = "../.#";

	Image image(line);

	ASSERT_EQ(image.image[0], "..");
	ASSERT_EQ(image.image[1], ".#");
}

TEST_F(ImageTests, to_string_converts_image_to_string) {
	std::string line = "../.#";
	Image image(line);

	auto result = image.to_string();

	ASSERT_EQ(result, "../.#");
}

TEST_F(ImageTests, rotate_rotates_the_image_by_one) {
	std::string line = "../.#";
	Image image(line);

	image.rotate();
	auto result = image.to_string();
	ASSERT_EQ(result, ".#/..");
}

TEST_F(ImageTests, flip_flips_the_image) {
	std::string line = "../.#";
	Image image(line);

	image.flip();

	auto result = image.to_string();
	ASSERT_EQ(result, ".#/..");
}

TEST_F(ImageTests, split_splits_the_image_into_new_images) {
	std::string line = "#..#/..../..../#..#";
	Image image(line);

	auto result = image.split();

	ASSERT_EQ(result[0].to_string(), "#./..");
	ASSERT_EQ(result[1].to_string(), ".#/..");
	ASSERT_EQ(result[2].to_string(), "../#.");
	ASSERT_EQ(result[3].to_string(), "../.#");
}

TEST_F(ImageTests, count_lit_pixels_counts_lit_pixels) {
	std::string line = "#..#/..../..../#..#";
	Image image(line);

	auto result = image.count_lit_pixels();

	ASSERT_EQ(result, 4);
}

class Day21Tests: public TestsBase, public Day21 {};

TEST_F(Day21Tests, rulebook_loads_rules_correctly) {
	using namespace std::string_literals;
	std::vector<std::string> rules = {
		"../.# => ##./#../..."s,
		".#./..#/### => #..#/..../..../#..#"s,
	};

	Rulebook rb(rules);

	ASSERT_EQ(rb.rules.size(), 2);
	ASSERT_EQ(rb.rules["../.#"s], "##./#../..."s);
	ASSERT_EQ(rb.rules[".#./..#/###"s], "#..#/..../..../#..#"s);
}

TEST_F(Day21Tests, find_image_in_rulebook_finds_correct_image) {
	using namespace std::string_literals;
	std::vector<std::string> rules = {
		"../.# => ##./#../..."s,
		".#./..#/### => #..#/..../..../#..#"s,
	};
	Rulebook rb(rules);
	Image image(".#./..#/###");

	auto new_image = transform_image_with_rules(rb, image);

	ASSERT_EQ(new_image.to_string(), "#..#/..../..../#..#");
}

TEST_F(Day21Tests, merge_images_merges_the_images) {
	std::string line = "#..#/..../..../#..#";
	Image image(line);
	auto images = image.split();

	auto new_image = merge_images(images);

	ASSERT_EQ(new_image.to_string(), line);
}

TEST_F(Day21Tests, iterate_image_iterates_given_number_of_times_and_returns_number_of_lit_pixels) {
	using namespace std::string_literals;
	std::vector<std::string> rules = {
		"../.# => ##./#../..."s,
		".#./..#/### => #..#/..../..../#..#"s,
	};
	Rulebook rb(rules);
	Image image(".#./..#/###"s);

	auto result = iterate_image(rb, image, 2);

	ASSERT_EQ(result, 12);
}

}
