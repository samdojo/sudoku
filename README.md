# sudoku

A C++20 low-latency sudoku puzzle solver.

#### To build:
- ensure GCC version 10 or higher is installed
- ensure GNU Make version 4.3 or higher is installed
- run `$ make`

#### To Run:
- run `$ sudo ./solver-release [path/to/puzzle]` to run puzzle solver
- run `$ ./test` to run unit tests

#### Dependencies:
- libgtest-dev: 1.10.0-2

#### System Requirements:
- a Linux kernel with the PREEMPT_RT patches applied

#### Suggested System configurations:
- disable simutaneous multithreading (SMT)/hyperthreading
- disable dynamic frequency scaling
- disable real-time throttling
- kill any unneeded real-time processes

For more details on system configurations, see https://shuhaowu.com/blog/2022/02-linux-rt-appdev-part2.html
