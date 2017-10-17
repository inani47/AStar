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
 *  @file test.cpp
 *
 *  @brief Contains Unit tests
 *
 *
 *  Defines several unit tests to check the correct behavior of various methods
 *  in Node, Map and AStar class
 *
 *
 *
 *
 *  @author Pranav Inani
 *  @copyright 2017
 */
#include <gtest/gtest.h>
#include "../include/Node.h"
#include "../app/Node.cpp"
#include "../include/AStar.h"
#include "../app/AStar.cpp"
#include "../include/Map.h"
#include "../app/Map.cpp"
/**
 * @brief Unit test for Heuristic Calculation
 *
 * Checks if Heuristic function is returning the
 * expected distance value
 */
TEST(HeuristicTest,CheckCalculatedDistance) {
  Node node(10, 10, 25, 50);
  int x = 10, y = 10;
  ASSERT_EQ(node.heuristic(x, y), 0);
}
/**
 * @brief Unit test for path cost calculation
 *
 * Checks if the function is returning the
 * expected value of path cost
 */
TEST(PathCostTest,CheckPathCostCalculation) {
  Node node(10, 10, 0, 50);
  int i = 1;

  ASSERT_NE(node.gCal(i), 10);
}
/**
 * @brief Unit test total function cost calculation
 *
 * Checks if function is returning the
 * expected value of the total function cost
 */
TEST(TotalCostTest,FIsGreater) {
  Node node(10, 10, 20, 20);
  int a = 0, b = 0;
  ASSERT_GE(node.fCal(a, b), node.pathCost);
}
/**
 * @brief Unit test for checking the overloaded '>' operator
 *
 * Checks if the node with greater total cost
 * is given priority
 */
TEST(OperatorTest, TestMinPriorityQ) {
  Node n1(1, 2, 23, 45), n3(23, 5, 12, 23);
  ASSERT_TRUE(n1 > n3);
}
/**
 * @brief Unit test to check if goal node is blocked
 *
 * If goal node is blocked path won't be found
 *
 */
TEST(GoalBlocked,PathNotFound) {
  AStar demo(0, 0, 9, 9);
  Map map;
  std::vector<std::vector<int>> m = map.createMap();
  m[9][9] = 0;
  std::vector<int> sol;
  sol = demo.pathFind(m);
  ASSERT_EQ(-1, sol[0]);
}
/**
 * @brief Unit test to check if start node is walkable
 *
 * Asserts that start node should never
 * be an obstacle
 *
 */
TEST(StartWalkable,MapValueIsOne) {
  Map map;
  std::vector<std::vector<int>> m = map.createMap();
  ASSERT_EQ(1, m[0][0]);
}


