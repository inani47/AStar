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
  int goalx;
  int goaly;
  int startx;
  int starty;

 public:
  AStar(int, int, int, int);
  bool operator>(const Node&, const Node&);
  std::vector<int> pathFind(std::vector<std::vector<int> > vec);
  ~AStar();
};
#endif
