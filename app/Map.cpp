/*
 * BSD 2-Clause License
 *
 * Copyright (c) 2017, Pranav Inani
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *  list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation
 *  and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/**
 *  @file Map.cpp
 *
 *  @brief Implements map class
 *
 *
 *  defines createMap function that creates a map with obstacles
 *  defines printMap that prints the path found by the algortihm
 *
 *
 *
 *
 *  @author Pranav Inani
 *  @copyright 2017
 */
#include <Map.h>
#include <vector>
/**
 *
 * @brief creates a 10x10 map with obstacles placed randomly
 *
 * A 10x10 vector of vectors of int is initialez with all values set to 1
 * Then 20 elemnts are randomly set to 0 to act as obstacles
 *
 * @return 10x10 map
 *
 */
std::vector<std::vector<int> > Map::createMap() {
  std::vector<std::vector<int> > vec(10, std::vector<int>(10, 1));
  std::random_device rd; /* used to initialize (seed) engine*/
  std::mt19937 rng(rd()); /* random-number engine used (Mersenne-Twister)*/
  std::uniform_int_distribution<int> uni(0, 9); /* guaranteed unbiased*/
  int i = 20;
  while (i != 0) {
    vec[uni(rng)][uni(rng)] = 0;
    --i;
  }
  vec[0][0] = 1;  // Assert start point is walkable
  return vec;
}
/**
 *
 * @brief Prints the path from start to goal
 *
 * @param _map is the map with all the nodes (walkable nodes as well as obstacles)
 * @param path is the map containing direction to the parent of each node to trace path
 * @param sx is the x coordinate of start
 * @param sy is the y coordinate of start
 * @param gx is the x coordinate of goal
 * @param gy is the y coordinate of goal
 *
 * traces the path from start to goal using path
 * prints '#' in place of obstacle
 * prints 'S' for start node
 * prints 'G' for goal node
 * prints '*' for path
 * prints '.' for all other walkable nodes
 *
 * @return none
 *
 */
int Map::printPath(std::vector<std::vector<int> > _map,
                    std::vector<int> path,
                    int sx, int sy, int gx, int gy) {
  if (path[0] == -1) {
    return -1;
  } else {
    std::vector<int> moveX { 1, 1, 0, -1, -1, -1, 0, 1 };
    std::vector<int> moveY { 0, 1, 1, 1, 0, -1, -1, -1 };
    int a = 0, b = 0;
    for (auto t : path) {
      a += moveX[t];
      b += moveY[t];
      _map[a][b] = 2;
    }
    _map[sx][sy] = 3;
    _map[gx][gy] = 4;
    for (auto &row : _map) {
      for (int col : row) {
        if (col == 1)
          std::cout << '.';
        else if (col == 0)
          std::cout << '#';
        else if (col == 2)
          std::cout << '*';
        else if (col == 3)
          std::cout << 'S';
        else if (col == 4)
          std::cout << 'G';
      }
      std::cout << std::endl;
    }
  }
  return 1;
}
