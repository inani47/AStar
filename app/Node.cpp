#include <Node.h>


Node::Node(int x1, int y1, int d, int p) {
  x = x1;
  y = y1;
  pathCost = d;
  totalCost = p;
}

int Node::heuristic(int _goalx, int _goaly) {
  int d = static_cast<int>(sqrt(
      (x - _goalx) * (x - _goalx) + (y - _goaly) * (y - _goaly)));
  ;
  return d;
}

int Node::gCal(int i) {
  return pathCost += (i % 2 == 0 ? 10 : 14);
}

int Node::fCal(int a, int b) {
  return totalCost = pathCost + heuristic(a, b) * 10;
}
