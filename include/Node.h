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
 *  @file Node.h
 *
 *  @brief Contains declarations for Node class
 *
 *
 *  Declares x, y, totalCost and pathCost as public members
 *  Declares heuristic function that calculates Euclidian distance
 *  Declares gCal that calculates pathCost
 *  Declares fCal that calculates total cost
 *  Declares constructor and destructor
 *
 *
 *
 *  @author Pranav Inani
 *  @copyright 2017
 */
#ifndef INCLUDE_NODE_H_
#define INCLUDE_NODE_H_
#include <cmath>
/**
 *
 * @brief Defines the Node class
 *
 * @param totalCost stores the heuristic plus pathCost
 * @param pathCost stores the cost incurrened to move to current node
 * @param x is the x coordinate of the node
 * @param y is the y coordinate of the node
 *
 * @return none
 *
 */
class Node {
 public:
  int totalCost, pathCost;
  int x, y;
  Node(int, int, int, int);
  int heuristic(int, int);
  int gCal(int);
  int fCal(int, int);
  ~Node();
};
#endif  // INCLUDE_NODE_H_
