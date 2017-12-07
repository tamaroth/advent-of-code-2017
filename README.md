# [AdventOfCode2017](http://adventofcode.com/2017/) solutions.

## Solution table.

| Day | Name                                                                    | Part 1    | Part 2    |
|:---:|:------------------------------------------------------------------------|:---------:|:---------:|
| 01  | [Inverse Captcha][day01] - [Solution][day01sol]                         |      77µs |      49µs |
| 02  | [Corruption Checksum][day02] - [Solution][day02sol]                     |      11µs |      35µs |
| 03  | [Spiral Memory][day03] - [Solution][day03sol]                           |      15µs |      17µs |
| 04  | [High-Entropy Passphrases][day04] - [Solution][day04sol]                |      41ms |      40ms |
| 05  | [A Maze of Twisty Trampolines, All Alike][day05] - [Solution][day05sol] |       2ms |     263ms |
| 06  | [Memory Reallocation][day06] - [Solution][day06sol]                     |      22ms |       4µs |
| 07  | [Recursive Circus][day07] - [Solution][day07sol]                        |      71ms |     136µs |

[day01]: https://adventofcode.com/2017/day/1
[day01sol]: ./advent/days/01/inverse_captcha.cc#L72
[day02]: https://adventofcode.com/2017/day/2
[day02sol]: ./advent/days/02/corruption_checksum.cc#L88
[day03]: http://adventofcode.com/2017/day/3
[day03sol]: ./advent/days/03/spiral_memory.cc#L76
[day04]: http://adventofcode.com/2017/day/4
[day04sol]: ./advent/days/03/high_entropy_passphrases.cc#L69
[day05]: http://adventofcode.com/2017/day/5
[day05sol]: ./advent/days/05/maze.cc#L54
[day06]: http://adventofcode.com/2017/day/6
[day06sol]: ./advent/days/05/memory_reallocation.cc#L72
[day07]: http://adventofcode.com/2017/day/7
[day07sol]: ./advent/days/07/recursive_circus.cc#L64

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
