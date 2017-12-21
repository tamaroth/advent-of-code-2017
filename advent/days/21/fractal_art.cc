/// @file
///
/// Day 21: Fractal Art

#include <algorithm>
#include <cmath>
#include <regex>
#include <sstream>
#include <unordered_map>

#include "advent/days/21/fractal_art.hh"
#include "advent/utils/assert.hh"
#include "advent/utils/misc.hh"

namespace advent {

// Override.
void Day21::set_up() {
	rules = read_lines_from_file("day_21_input.txt");
}

// Override.
void Day21::solve_part_one() {
	Rulebook rulebook(rules);
	std::cout << part_one()
			<< solve_part_one_for_input(rulebook)
		<< std::endl;
}

// Override.
void Day21::solve_part_two() {
	Rulebook rulebook(rules);
	std::cout << part_two()
			<< solve_part_two_for_input(rulebook)
		<< std::endl;
}

// Override.
std::string Day21::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day21::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

///
/// Solves part one for the given input.
///
int Day21::solve_part_one_for_input(const Rulebook& rulebook) {
	Image image(".#./..#/###");
	return iterate_image(rulebook, image, 5);
}

///
/// Solves part two for the given input.
///
int Day21::solve_part_two_for_input(const Rulebook& rulebook) {
	Image image(".#./..#/###");
	return iterate_image(rulebook, image, 18);
}

///
/// Transforms the given image with accordance to the rules in rulebook.
///
/// If the rule is not found in the rulebook, the rulebook is incomplete and any
/// further work is irrelevant.
///
Image Day21::transform_image_with_rules(const Rulebook& rulebook, Image& image) {
	constexpr std::size_t max_flips = 2;
	constexpr std::size_t max_rotations = 4;

	for (std::size_t flip = 0; flip < max_flips; ++flip) {
		for (std::size_t rotation = 0; rotation < max_rotations; ++rotation) {
			auto it = rulebook.rules.find(image.to_string());
			if (it != rulebook.rules.end()) {
				return Image(it->second);
			}
			image.rotate();
		}
		image.flip();
	}

	THROW_LOGIC_MSG("we couldn't find the given image in the rulebook " + image.to_string())
}

///
/// Merges the given images into one.
///
Image Day21::merge_images(const std::vector<Image>& images) {
	std::ostringstream oss;
	std::size_t size = images.size();
	std::size_t step = std::sqrt(size);

	for (std::size_t i = 0; i < size; i += step) {
		for (std::size_t j = 0; j < images[i].image.size(); ++j) {
			for (std::size_t x = 0; x < step; ++x) {
				oss << images[i + x].image[j];
			}
			oss << '/';
		}
	}
	auto result = oss.str();
	return Image(result.substr(0, result.size() - 1));
}

///
/// Iterates the image by splitting it and transforming resulting images with
/// the rules from the given rulebook and then merging the image together.
///
int Day21::iterate_image(const Rulebook& rulebook, Image& image, std::size_t iterations) {
	for (std::size_t i = 0; i < iterations; ++i) {
		auto images = image.split();
		std::transform(images.begin(), images.end(), images.begin(), [&](auto& img) {
			return transform_image_with_rules(rulebook, img);
		});
		image = merge_images(images);
	}
	return image.count_lit_pixels();
}


///
/// Converts a string to a representation of an image.
///
std::vector<std::string> Image::from_line(const std::string& line) const {
	std::vector<std::string> image;
	auto begin = line.begin();
	auto end = line.end();
	std::size_t pos = 0;

	auto slash = std::find(begin, end, '/');
	while (slash != end) {
		image.push_back(std::move(line.substr(pos, slash - begin - pos)));
		pos = slash - begin + 1;
		slash = std::find(slash + 1, end, '/');
	}
	image.push_back(std::move(line.substr(pos)));

	return image;
}

///
/// Converts internal representation into a string.
///
std::string Image::to_string() const {
	std::ostringstream oss;

	auto element = image.begin();
	while (element != image.end()) {
		oss << *element;
		if (element != image.end() - 1) {
			oss << "/";
		}
		element++;
	}
	return oss.str();
}

///
/// Rotates the image.
///
void Image::rotate() {
	std::vector<std::string> rotated(image.size(), "");

	for (const auto& line : image) {

		for (std::size_t i = line.size() - 1, j = 0; i > 0; --i, ++j) {
			rotated[j] += line[i];
		}
		rotated[line.size() - 1] += line[0];
	}
	image = rotated;
}

///
/// Flips the image.
///
void Image::flip() {
	std::reverse(image.begin(), image.end());
}

///
/// Splits an image into 4 equal smaller images, if possible.
///
std::vector<Image> Image::split() {
	std::vector<Image> images;
	if (image.size()%2 == 0) {
		for (std::size_t i = 0; i < image.size(); i += 2) {
			for (std::size_t j = 0; j < image.size(); j += 2) {
				std::ostringstream oss;
				oss << image[i][j] << image[i][j+1] << '/'
					<< image[i+1][j] << image[i+1][j+1];
				images.push_back(Image(oss.str()));
			}
		}
	} else {
		for (std::size_t i = 0; i < image.size(); i += 3) {
			for (std::size_t j = 0; j < image.size(); j += 3) {
				std::ostringstream oss;
				oss << image[i][j] << image[i][j+1] << image[i][j+2] << '/'
					<< image[i+1][j] << image[i+1][j+1] << image[i+1][j+2] << '/'
					<< image[i+2][j] << image[i+2][j+1] << image[i+2][j+2];
				images.push_back(Image(oss.str()));
			}
		}
	}
	return images;
}

///
/// Counts all lit pixels in the image.
///
std::size_t Image::count_lit_pixels() const {
	std::size_t count = 0;
	for (const auto& line : image) {
		count += std::count(line.begin(), line.end(), '#');
	}

	return count;
}

///
/// Creates a rulebook out of lines of strings.
///
Rulebook::Rulebook(const std::vector<std::string>& lines) {
	std::regex rx("([./#]+) => ([./#]+)");
	std::smatch match;
	for (const auto& line : lines) {
		if (std::regex_search(line.begin(), line.end(), match, rx)) {
			rules[match[1]] = match[2];
		}
	}
}

}
