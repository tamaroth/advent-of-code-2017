# [AdventOfCode2017](http://adventofcode.com/2017/) solutions.

## Solution table.

| Day | Name                                           | Part 1    | Part 2    |
|:---:|:-----------------------------------------------|:---------:|:---------:|
| 01  | :ballot_box_with_check: [Inverse Captcha][day01]           |      77µs |      49µs |

[day01]: https://adventofcode.com/2017/day/1

## Building

To build the code you will need:
 * [git](https://git-scm.com) or equivalent
 * [CMake 3.6+](https://cmake.org) or newer
 * [GCC 7.2+](https://gcc.gnu.org/gcc-7/)

Follow the steps:
 * from within terminal, go to a directory you wish to contain the code. (e.g. `cd ~/code`)
 * clone the repo: `git clone https://github.com/tamaroth/AdventOfCode2017.git`
 * enter the repo: `cd AdventOfCode2017`
 * create build directory: `mkdir build`
 * enter build directory: `cd build`
 * run cmake: `cmake ..`
 * run make: `make -j`
 * to run the solutions: `./advent/advent`
 * to run the tests: `./advent/advent tests`
