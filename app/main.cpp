#include <Node.h>
#include <AStar.h>
#include <Map.h>

int main() {
  Map map;
  std::vector<std::vector<int>> m = map.createMap();
  AStar demo(0, 0, 9, 9);
  std::vector<int> sol;
  sol = demo.pathFind(m);
  map.printPath(m, sol, 0, 0, 9, 9);
}
