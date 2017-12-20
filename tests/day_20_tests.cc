/// @file
///
/// Day 20 tests.
///

#include <gmock/gmock.h>

#include "advent/days/20/particle_swarm.hh"
#include "tests/tests_base.hh"

namespace advent::tests {

class Day20Tests: public TestsBase, public Day20 {};

TEST_F(Day20Tests, to_paricle_converts_string_to_particle_correctly) {
	std::string line = "p=<1500,413,-535>, v=<-119,22,36>, a=<-5,-12,3>";

	auto particle = to_particle(line);

	ASSERT_EQ(particle.p.x, 1500);
	ASSERT_EQ(particle.p.y, 413);
	ASSERT_EQ(particle.p.z, -535);
	ASSERT_EQ(particle.v.x, -119);
	ASSERT_EQ(particle.v.y, 22);
	ASSERT_EQ(particle.v.z, 36);
	ASSERT_EQ(particle.a.x, -5);
	ASSERT_EQ(particle.a.y, -12);
	ASSERT_EQ(particle.a.z, 3);
}

TEST_F(Day20Tests, get_new_position_calculates_new_position_correctly) {
	std::string line = "p=<3,0,0>, v=<2,0,0>, a=<-1,0,0>";
	auto particle = to_particle(line);

	get_new_position(particle);

	ASSERT_EQ(particle.p.x, 4);
	ASSERT_EQ(particle.p.y, 0);
	ASSERT_EQ(particle.p.z, 0);
	ASSERT_EQ(particle.v.x, 1);
	ASSERT_EQ(particle.v.y, 0);
	ASSERT_EQ(particle.v.z, 0);
}

TEST_F(Day20Tests, solve_part_one_for_input_solves_correctly) {
	std::vector<std::string> lines = {
		"p=<3,0,0>, v=<2,0,0>, a=<-1,0,0>",
		"p=<4,0,0>, v=<0,0,0>, a=<-2,0,0>",
	};
	std::vector<Particle> particles;
	int index = 0;
	for (const auto& line : lines) {
		auto particle = to_particle(line);
		particle.index = index++;
		particles.push_back(std::move(particle));
	}

	auto result = solve_part_one_for_input(particles);

	ASSERT_EQ(result, 0);
}

TEST_F(Day20Tests, remove_collisions_removes_entries_with_the_same_position) {
	std::vector<std::string> lines = {
		"p=<0,0,0>, v=<3,0,0>, a=<0,0,0>",
		"p=<0,1,0>, v=<1,0,0>, a=<0,0,0>",
		"p=<0,0,0>, v=<1,0,0>, a=<0,0,0>",
		"p=<3,0,0>, v=<-1,0,0>, a=<0,0,0>",
		"p=<3,0,0>, v=<-1,0,0>, a=<0,0,0>",
		"p=<0,0,0>, v=<1,0,0>, a=<0,0,0>",
	};
	std::vector<Particle> particles;
	int index = 0;
	for (const auto& line : lines) {
		auto particle = to_particle(line);
		particle.index = index++;
		particles.push_back(std::move(particle));
	}

	auto result = remove_collisions(particles);

	ASSERT_EQ(result, 5);
}

TEST_F(Day20Tests, solve_part_two_for_input_solves_correctly) {
	std::vector<std::string> lines = {
		"p=<-6,0,0>, v=<3,0,0>, a=<0,0,0>",
		"p=<-4,0,0>, v=<2,0,0>, a=<0,0,0>",
		"p=<-2,0,0>, v=<1,0,0>, a=<0,0,0>",
		"p=<3,0,0>, v=<-1,0,0>, a=<0,0,0>",
	};
	std::vector<Particle> particles;
	int index = 0;
	for (const auto& line : lines) {
		auto particle = to_particle(line);
		particle.index = index++;
		particles.push_back(std::move(particle));
	}

	auto result = solve_part_two_for_input(particles);

	ASSERT_EQ(result, 1);
}

}
