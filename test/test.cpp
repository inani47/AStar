#include <gtest/gtest.h>
#include "../include/Node.h"
#include "../app/Node.cpp"
#include "../include/AStar.h"
#include "../app/AStar.cpp"
#include "../include/Map.h"
#include "../app/Map.cpp"

TEST(HeuristicTest,CheckCalculatedDistance) {
  Node node(10, 10, 25, 50);
  int x = 10, y = 10;
  ASSERT_EQ(node.heuristic(x, y), 0);
}
TEST(PathCostTest,CheckPathCostCalculation) {
  Node node(10, 10, 0, 50);
  int i = 1;

  ASSERT_NE(node.gCal(i), 10);
}
TEST(TotalCostTest,FIsGreater) {
  Node node(10, 10, 20, 20);
  int a = 0, b = 0;
  ASSERT_GE(node.fCal(a, b), node.pathCost);
}

TEST(OperatorTest, TestMinPriorityQ) {
  Node n1(1, 2, 23, 45), n3(23, 5, 12, 23);
  ASSERT_TRUE(n1 > n3);
}
TEST(GoalBlocked,PathNotFound) {
  AStar demo(0, 0, 9, 9);
  Map map;
  std::vector<std::vector<int>> m = map.createMap();
  m[9][9] = 0;
  std::vector<int> sol;
  sol = demo.pathFind(m);
  ASSERT_EQ(-1, sol[0]);
}

TEST(StartWalkable,MapValueIsOne) {
  Map map;
  std::vector<std::vector<int>> m = map.createMap();
  ASSERT_EQ(1, m[0][0]);
}


