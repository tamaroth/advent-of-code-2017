/// @file
///
/// Day 21: Fractal Art.
///

#pragma once

#include <string>
#include <string_view>
#include <vector>

#include "advent/utils/base.hh"

namespace advent {

struct Image {
	Image(const std::string& line) : image(from_line(line)) {};
	~Image() = default;

	/// @name Conversion
	/// @{
	std::vector<std::string> from_line(const std::string& line) const;
	std::string to_string() const;
	/// @}

	/// @name Image manipulation
	/// @{
	void rotate();
	void flip();
	std::vector<Image> split();
	/// @}

	/// @name Additional information
	/// @{
	std::size_t count_lit_pixels() const;
	/// @}

	/// Underlying representation of the image.
	std::vector<std::string> image;
};

struct Rulebook {
	Rulebook(const std::vector<std::string>& lines);

	/// Mapping of transformation rules.
	std::unordered_map<std::string, std::string> rules;
};

class Day21: public Task {
public:
	Day21() = default;
	~Day21() override = default;

	virtual void set_up() override;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	int solve_part_one_for_input(const Rulebook& rulebook);
	int solve_part_two_for_input(const Rulebook& rulebook);

	Image transform_image_with_rules(const Rulebook& rb, Image& image);
	Image merge_images(const std::vector<Image>& images);
	int iterate_image(const Rulebook& rulebook, Image& image, std::size_t iterations);

private:
	/// Lines of rules read from input file.
	std::vector<std::string> rules;
};

}
