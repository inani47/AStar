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
 *  @file Node.cpp
 *
 *  @brief Implements node class
 *
 *  Defines functions to compute heuristic, path cost and total cost
 *  Defines constructor and destructor
 *
 *
 *
 *
 *  @author Pranav Inani
 *  @copyright 2017
 */
#include <Node.h>
/**
 *
 *  @brief Constructor for creating an object of Node
 *
 *  intitializes the coordinates of the node, the
 *  path cost and total cost
 *
 */
Node::Node(int _x, int _y, int _g, int _f) {
  x = _x;
  y = _y;
  pathCost = _g;
  totalCost = _f;
}
/**
 *
 * @brief Calculates the Euclidian Distance between the current node and goal
 *
 * @param _goalx is the x coordinate of goal
 * @param _goaly is the y coordinate of goal
 *
 * @return the distance in int
 *
 */

int Node::heuristic(int _goalx, int _goaly) {
  int d = static_cast<int>(sqrt(
      (x - _goalx) * (x - _goalx) + (y - _goaly) * (y - _goaly)));
  return d;
}
/**
 *
 * @brief Calculates the path cost of a node
 *
 * @param i is the direction of the next movement in x and y direction
 *
 * if the movement is diagonal path cost of 14 is incurred
 * if the movement is a straight line then path cost of 10 is incurred
 *
 * @return total path cost from start node to current node
 *
 */

int Node::gCal(int i) {
  return pathCost += (i % 2 == 0 ? 10 : 14);
}
/**
 *
 * @brief calculates total cost
 *
 * @param a is the x coordinate of the goal
 * @param b is the y coordinate of the goal
 *
 * @return sum of the path cost and heuristic
 *
 */
int Node::fCal(int a, int b) {
  return totalCost = pathCost + heuristic(a, b) * 10;
}
/**
 *
 *  @brief Destructor of Node object
 *
 */
Node::~Node() {
}


