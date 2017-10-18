# A Star Path Planning Algorithm
[![Build Status](https://travis-ci.org/inani47/AStar.svg?branch=master)](https://travis-ci.org/inani47/AStar)
[![Coverage Status](https://coveralls.io/repos/github/inani47/AStar/badge.svg?branch=master)](https://coveralls.io/github/inani47/AStar?branch=master)
---

## Overview

Implementation of A* path planning algorithm in C++.

## License

This software is released under the BSD-2 License, see [LICENSE.txt](LICENSE.txt).

## SIP Logs

Link to google spreadsheets: https://docs.google.com/spreadsheets/d/1L3S5S-xUDZFRZburYVNjMFN7-COTC3OJuEMe_ykktyQ/edit?usp=sharing


## Build Instructions
```
git clone --recursive https://github.com/inani47/AStar
cd AStar
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```
## Running the Demo

Follow the build instructions then run the following command from the build directory:
```
./app/shell-app
```

## Running Unit Tests

Follow the build instructions then run the following command from the build directory:
```
./test/cpp-test
```


## Generating Doxygen Documentation

In your cloned directory run the following command from terminal:

```bash
doxygen Doxygen
```

- Doxygen files will be generated to /docs folder



