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
| 08  | [I Heard You Like Registers][day08] - [Solution][day08sol]              |     866µs |     795µs |
| 09  | [Stream Processing][day09] - [Solution][day09sol]                       |     372µs |       3µs |
| 10  | [Knot Hash][day10] - [Solution][day10sol]                               |     217µs |       4ms |
| 11  | [Hex Ed][day11] - [Solution][day11sol]                                  |      38ms |       4µs |
| 12  | [Digital Plumber][day12] - [Solution][day12sol]                         |     314µs |      23ms |
| 13  | [Packet Scanners][day13] - [Solution][day13sol]                         |      15µs |     341ms |
| 14  | [Disk Defragmentation][day14] - [Solution][day14sol]                    |      18ms |      15ms |
| 15  | [Dueling Generators][day15] - [Solution][day15sol]                      |     186ms |     290ms |
| 16  | [Permutation Promenade][day16] - [Solution][day16sol]                   |       3ms |     387ms |
| 17  | [Spinlock][day17] - [Solution][day17sol]                                |       1ms |     325ms |
| 18  | [Duet][day18] - [Solution][day18sol]                                    |     109µs |       5ms |
| 19  | [A Series of Tubes][day19] - [Solution][day19sol]                       |      60µs |      70µs |
| 20  | [Particle Swarm][day20] - [Solution][day20sol]                          |     120µs |      13ms |
| 21  | [Fractal Art][day21] - [Solution][day21sol]                             |     404µs |    1825ms |

[day01]: https://adventofcode.com/2017/day/1
[day01sol]: ./advent/days/01/inverse_captcha.cc
[day02]: https://adventofcode.com/2017/day/2
[day02sol]: ./advent/days/02/corruption_checksum.cc
[day03]: http://adventofcode.com/2017/day/3
[day03sol]: ./advent/days/03/spiral_memory.cc
[day04]: http://adventofcode.com/2017/day/4
[day04sol]: ./advent/days/03/high_entropy_passphrases.cc
[day05]: http://adventofcode.com/2017/day/5
[day05sol]: ./advent/days/05/maze.cc
[day06]: http://adventofcode.com/2017/day/6
[day06sol]: ./advent/days/05/memory_reallocation.cc
[day07]: http://adventofcode.com/2017/day/7
[day07sol]: ./advent/days/07/recursive_circus.cc
[day08]: http://adventofcode.com/2017/day/8
[day08sol]: ./advent/days/08/registers.cc
[day09]: http://adventofcode.com/2017/day/9
[day09sol]: ./advent/days/09/stream_processing.cc
[day10]: http://adventofcode.com/2017/day/10
[day10sol]: ./advent/days/10/knot_hash.cc
[day11]: http://adventofcode.com/2017/day/11
[day11sol]: ./advent/days/11/hex_ed.cc
[day12]: http://adventofcode.com/2017/day/12
[day12sol]: ./advent/days/12/digital_plumber.cc
[day13]: http://adventofcode.com/2017/day/13
[day13sol]: ./advent/days/13/packet_scanners.cc
[day14]: http://adventofcode.com/2017/day/14
[day14sol]: ./advent/days/14/disk_defragmentation.cc
[day15]: http://adventofcode.com/2017/day/15
[day15sol]: ./advent/days/15/dueling_generators.cc
[day16]: http://adventofcode.com/2017/day/16
[day16sol]: ./advent/days/16/permutation_promenade.cc
[day17]: http://adventofcode.com/2017/day/17
[day17sol]: ./advent/days/17/spinlock.cc
[day18]: http://adventofcode.com/2017/day/18
[day18sol]: ./advent/days/18/duet.cc
[day19]: http://adventofcode.com/2017/day/19
[day19sol]: ./advent/days/19/tubes.cc
[day20]: http://adventofcode.com/2017/day/20
[day20sol]: ./advent/days/20/particle_swarm.cc
[day21]: http://adventofcode.com/2017/day/21
[day21sol]: ./advent/days/21/fractal_art.cc


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
