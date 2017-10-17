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
 *  @file AStar.h
 *
 *  @brief Contains declarations for AStar class
 *
 *
 *  Declares pathFind functions that performs the implementation
 *  Declares start and end coordinates as private members
 *  Declares function to overload '>' operator
 *  Declares constructor and destructor of AStar class
 *
 *
 *  @author Pranav Inani
 *  @copyright 2017
 */
#ifndef INCLUDE_ASTAR_H_
#define INCLUDE_ASTAR_H_
#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <Node.h>
#include <Map.h>
using namespace std;
class AStar {
 public:

  int startx;
  int starty;
  int goalx;
  int goaly;

  AStar(int _startx, int _starty, int _goalx, int _goaly);
  friend bool operator>(const Node&, const Node&);
  std::vector<int> pathFind(std::vector<std::vector<int> > vec);
  ~AStar();
};
#endif
