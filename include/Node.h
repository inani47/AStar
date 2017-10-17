#ifndef INCLUDE_NODE_H_
#define INCLUDE_NODE_H_
#include <cmath>
class Node {

 public:
  int totalCost, pathCost;
  int x, y;
  Node(int, int, int, int);
  int heuristic(int, int);
  int gCal(int);
  int fCal(int, int);
  ~Node() {
  }
};
#endif
