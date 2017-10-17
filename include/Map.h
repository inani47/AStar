#ifndef INCLUDE_MAP_H_
#define INCLUDE_MAP_H_
#include<vector>
#include<random>
#include<Node.h>
#include<iostream>
class Map {
 public:
  std::vector<std::vector<int> > createMap();
  void printPath(std::vector<std::vector<int> >, std::vector<int>,
                             int, int, int, int);
};
#endif
