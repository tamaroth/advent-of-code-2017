/// @file
///
/// Day 20: Particle Swarm
///

#include <algorithm>
#include <iostream>
#include <regex>

#include "advent/days/20/particle_swarm.hh"
#include "advent/utils/container.hh"
#include "advent/utils/misc.hh"

namespace advent {

std::ostream& operator<<(std::ostream& os, const Measure& ms) {
	os << "<" << ms.x << "," << ms.y << "," << ms.z << ">";
	return os;
}

std::ostream& operator<<(std::ostream& os, const Particle& pt) {
	os << "idx=" << pt.index << ", p=" << pt.p << ", v=" << pt.v << ", a=" << pt.a;
	return os;
}

// Override.
void Day20::set_up() {
	auto lines = read_lines_from_file("day_20_input.txt");
	int index = 0;
	for (const auto& line : lines) {
		auto particle = to_particle(line);
		particle.index = index++;
		particles.push_back(std::move(particle));
	}
}

// Override.
void Day20::solve_part_one() {
	std::cout << part_one()
			<< solve_part_one_for_input(particles)
		<< std::endl;
}

// Override.
void Day20::solve_part_two() {
	std::cout << part_two()
			<< solve_part_two_for_input(particles)
		<< std::endl;
}

// Override.
std::string Day20::part_one() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

// Override.
std::string Day20::part_two() const {
	return __COMPACT_PRETTY_FUNCTION__;
}

Particle Day20::to_particle(const std::string& line) {
	Particle particle;
	std::regex rx(R"(p=<([-\d]+),([-\d]+),([-\d]+)>, v=<([-\d]+),([-\d]+),([-\d]+)>, a=<([-\d]+),([-\d]+),([-\d]+)>)");
	std::smatch match;

	if (std::regex_search(line.begin(), line.end(), match, rx)){
		return Particle{
			Measure{
				std::stoi(match[1]),
				std::stoi(match[2]),
				std::stoi(match[3])
			},
			Measure{
				std::stoi(match[4]),
				std::stoi(match[5]),
				std::stoi(match[6])
			},
			Measure{
				std::stoi(match[7]),
				std::stoi(match[8]),
				std::stoi(match[9])
			},
			0
		};
	}
	return particle;
}

void Day20::get_new_position(Particle& particle) {
	particle.v += particle.a;
	particle.p += particle.v;
}

int Day20::remove_collisions(std::vector<Particle>& particles) {
	int old = particles.size();
	std::vector<Particle> to_erase;

	for (std::size_t i = 0; i < particles.size(); i++) {
		if (std::find(to_erase.begin(), to_erase.end(), particles[i]) != to_erase.end()) {
			continue;
		}
		for (std::size_t j = i + 1; j < particles.size(); j++) {
			if (particles[i] == particles[j]) {
				to_erase.push_back(particles[i]);
				break;
			}
		}
	}
	for (const auto& er : to_erase) {
		auto iter = particles.begin();
		while (iter != particles.end()) {
			Particle v = *iter;
			if (v == er) {
				iter = particles.erase(iter);
				continue;
			}
			iter++;
		}
	}
	return old - particles.size();
}

int Day20::solve_part_one_for_input(std::vector<Particle>& particles) {
	std::sort(particles.begin(), particles.end(), [](const auto& p1, const auto& p2) {
		if (p1.a.distance() == p2.a.distance()) {
			if (p1.v.distance() == p2.v.distance()) {
				return p1.p.distance() < p2.p.distance();
			}
			return p1.v.distance() < p2.v.distance();
		}
		return p1.a.distance() < p2.a.distance();
	});

	return particles[0].index;
}

int Day20::solve_part_two_for_input(std::vector<Particle>& particles) {
	std::vector<int> loops = { 128 };
	std::vector<std::size_t> counts;
	for (auto loop : loops) {
		auto parts = particles;
		while(loop--) {
			remove_collisions(parts);
			if (parts.size() == 1) {
				break;
			}
			for (auto& particle : parts) {
				get_new_position(particle);
			}
		}
		counts.push_back(parts.size());
	}
	if (std::adjacent_find(counts.begin(), counts.end(), std::not_equal_to<std::size_t>())
		== counts.end()) {
		return counts[0];
	}
	return -1;
}

}
