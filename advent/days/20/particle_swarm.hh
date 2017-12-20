/// @file
///
/// Day 20: Particle Swarm
///

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "advent/utils/base.hh"

namespace advent {

struct Measure {
	int x;
	int y;
	int z;

	Measure& operator+=(const Measure& other) {
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		return *this;
	}

	Measure& operator-=(const Measure& rhs) {
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		return *this;
	}

	bool operator==(const Measure& rhs) {
		return (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z);
	}

	int distance() const {
		return std::abs(x) + std::abs(y) + std::abs(z);
	}
};

struct Particle {
	Measure p;
	Measure v;
	Measure a;
	int index;

	Particle& operator-=(const Particle& rhs) {
		this->p -= rhs.p;
		return *this;
	}

	friend Particle operator-(Particle lhs, const Particle& rhs) {
		lhs -= rhs;
		return lhs;
	}

	bool operator==(const Particle& rhs) {
		return this->p == rhs.p;
	}
};

std::ostream& operator<<(std::ostream& os, const Measure& ms);
std::ostream& operator<<(std::ostream& os, const Particle& ms);

class Day20: public Task {
public:
	Day20() = default;
	~Day20() override = default;

	virtual void set_up() override;

	virtual void solve_part_one() override;
	virtual void solve_part_two() override;

	virtual std::string part_one() const override;
	virtual std::string part_two() const override;

protected:
	int solve_part_one_for_input(std::vector<Particle>& particles);
	int solve_part_two_for_input(std::vector<Particle>& particles);
	Particle to_particle(const std::string& line);
	void get_new_position(Particle& particle);
	int remove_collisions(std::vector<Particle>& particles);

private:
	std::vector<Particle> particles;
};

}
