# A Star Path Planning Algorithm
[![Build Status](https://travis-ci.org/inani47/AStar.svg?branch=master)](https://travis-ci.org/inani47/AStar)
[![Coverage Status](https://coveralls.io/repos/github/inani47/AStar/badge.svg?branch=master)](https://coveralls.io/github/inani47/AStar?branch=master)
---

## Overview

Implementation of A* path planning algorithm in C++.

The purpose of this project was the design and development of a module that implements the A* path planning algorithm. The A* is a heuristic function based algorithm that is guaranteed to find the shortest path between two points with multiple nodes in between and does so with high performance and accuracy. The A* algorithm solves for the shortest distance by giving priority to the evaluation of those nodes that are likely to lead us to the destination with lower cost. This is done by weighing each path with a cost function which is the sum of two terms. The first term is the total cost incurred to move from start goal to the current node and the second term is the distance between the current node and the destination. The path with the smallest cost function gives the optimal solution.

The module was implemented using three classes: Map, Node and AStar. The map class has a createMap method that creates a map of size 10x10 with twenty randomly placed object. Once the start and end nodes are defined in the AStar class, the pathFind method finds the optimal path from start node to the end node, if it exists. It uses the pathCost, totalCost and Heuristic methods of the node class to do this. Once the path is found the printPath method of Map class prints the final solution.

The project was programmed in the C++ programming language and uses with C++ 11/14 features. The code follows the Google C++ Styleguide with cpplint validation. Cppcheck was also used for static code analysis. This project followed Test_driven Development to guide implementation and uses unit tests to test the code coverage written using Google Test framework. The entire code was written and debugged using the Eclipse IDE. The code follows doxygen-formatted comments to aid doxygen documentation.
 
The project was completed in two weeks time. The source code will use no external libraries. This project was implemented by following the Solo Iterative Process(SIP). This included the creation of a product backlog using the requirements and ordering them in the order of their priority. Finally, the software was developed over two sprints which were one week long in duration. The first week focused on the planning and design of the project inculding the initial UML diagrams. The second week involved the programming of the actual module.

## Example Outputs

Output1: If path found

![pathfound](https://user-images.githubusercontent.com/31521157/31698837-8415db10-b38d-11e7-8ad1-14596e9e8490.png)

Output2: if path not found 

![pathnotfound](https://user-images.githubusercontent.com/31521157/31698862-a3a2bec6-b38d-11e7-90cc-87449e9b05a3.png)

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
```
## Running the Demo

Follow the build instructions, then run the following command from the build directory:
```
./app/shell-app
```

## Running Unit Tests

Follow the build instructions, then run the following command from the build directory:
```
./test/cpp-test
```


## Generating Doxygen Documentation

To install doxygen run the following command: 
```
sudo apt-get install doxygen
```

Now from your cloned directory, run the following command:

```
doxygen AStar.config
```

Doxygen files will be generated to /docs folder

To view them in a browser:
```
cd Docs
cd html
google-chrome index.html
```




