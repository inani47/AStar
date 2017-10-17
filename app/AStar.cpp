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
 *  @file AStar.cpp
 *
 *  @brief Implements A* algorithm
 *
 *
 *  Defines pathFinding function that find the path
 *  Defines function to overload '>' operator to implement minimum priority queue
 *  Defines constructor and destructor
 *
 *  @author Pranav Inani
 *  @copyright 2017
 */
#include <AStar.h>
/**
 *
 *  @brief Constructor for initializing goal and start coordinates
 *
 *  intitializes the coordinates of start & goal coordinates
 *
 *
 */
AStar::AStar(int _startx, int _starty, int _goalx, int _goaly)
    : startx(_startx),
      starty(_starty),
      goalx(_goalx),
      goaly(_goaly) {
}

/**
 *
 * @brief overloads the '>' operator
 *
 * gives priority to node with greater total cosr
 *
 * @param p is a reference of a node
 * @param q is a reference of a node
 *
 * @return true if the total cost of p is greater, else false
 *
 */

bool operator>(const Node & p, const Node & q) {
  return p.totalCost > q.totalCost;
}
/**
 *
 * @brief finds the path of directions from start to goal
 *
 *
 *
 * @param vec is a map which holds info if a node is walkable or blocked
 *
 *
 * @return path with parent directions from start to goal
 *
 */

  std::vector<int> AStar::pathFind(std::vector<std::vector<int> > vec) {
  int neighbours = 8; /* max no of possible neighbors for any node*/
  std::vector<int> moveX { 1, 1, 0, -1, -1, -1, 0, 1 }; /* possible moves in x directions */
  std::vector<int> moveY { 0, 1, 1, 1, 0, -1, -1, -1 }; /* possible moves in y direction */
  std::vector<int> path;
  int j;
  priority_queue<Node, std::vector<Node>, greater<Node> > ol; /* stores Nodes ordered by priority */
  priority_queue<Node, std::vector<Node>, greater<Node> > temp;
  std::vector<std::vector<int> > open(10, std::vector<int>(10, 0)); /* stores list of unexpanded nodes */
  std::vector<std::vector<int> > visited(10, std::vector<int>(10, 0)); /*stores list of expanded nodes */
  std::vector<std::vector<int> > parentDir(10, std::vector<int>(10, 0)); /* stores the direction of parent of each node */
  Node start(startx, starty, 0, 0);
  start.totalCost = start.fCal(goalx, goaly);
  ol.push(start);
  open[start.x][start.y] = start.totalCost;
  /* while open list is not empty this loop
   * chooses the node with least total cost
   * and expands it*/
  while (!ol.empty()) {
  Node current = ol.top();
  ol.pop();
  open[current.x][current.y] = 0;
  visited[current.x][current.y] = 1;
    /* If goal is found this loop uses parentDir
     * map to trace the path from start node to
     * end node*/
    if (current.x == goalx && current.y == goaly) {
      int p = current.x, q = current.x;
      while (!(p == startx && q == starty)) {
        j = parentDir[p][q];
        path.push_back((j + neighbours / 2) % neighbours);
        p += moveX[j];
        q += moveY[j];
      }
      return path;
    }
    /* This loop expands the current node and
     * calculates the costs for all the neighbours. */

  int dir = 0;
  while (dir < 8) {
      int dx = current.x + moveX[dir], dy = current.y + moveY[dir];
      /* If the node lies outside the map, is blocked
       * or is in the visisted list then it is ignored.*/
    if (!(dx < 0 || dx > 9 || dy < 0 || dy > 9 || vec[dx][dy] == 0
            || visited[dx][dy] == 1)) {
        Node child(dx, dy, current.pathCost, current.totalCost);
        child.pathCost = child.gCal(dir);
        child.totalCost = child.fCal(goalx, goaly);
        /* If the node is not in the open list
         * it's total cost and parent node are updated.*/
      if (open[dx][dy] == 0) {
          open[dx][dy] = child.totalCost;
          ol.push(child);
          parentDir[dx][dy] = (dir + neighbours / 2) % neighbours;
      }
        /* If the node exists in open list but has more
         * promising total cost then it is replaced by
         * the previous node and it's parent direction is updated.*/
      else if (open[dx][dy] > child.totalCost) {
          open[dx][dy] = child.totalCost;
          parentDir[dx][dy] = (dir + 8 / 2) % 8;
        while (!(ol.top().x == dx && ol.top().y == dy)) {
          temp.push(ol.top());
          ol.pop();
        }
        ol.pop();
        while (!temp.empty()) {
          ol.push(temp.top());
          temp.pop();
        }
        ol.push(child);
      }
    }
    ++dir;
  }
}
  std::cout << "Path not found. Start blocked or goal is an obstacle"
            << std::endl;
  path = {-1};
  return path;
}

AStar::~AStar() {
}






