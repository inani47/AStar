#include <Map.h>

std::vector<std::vector<int> > Map::createMap() {
  std::vector<std::vector<int> > vec(10, std::vector<int>(10, 1));

  std::random_device rd;     // only used once to initialise (seed) engine
  std::mt19937 rng(rd());  // random-number engine used (Mersenne-Twister in this case)
  std::uniform_int_distribution<int> uni(0, 9);  // guaranteed unbiased
  int i = 20;
  while (i != 0) {

    vec[uni(rng)][uni(rng)] = 0;
    --i;
  }
  return vec;
}

void Map::printPath(std::vector<std::vector<int> > _map,
                    std::vector<int> path,
                    int sx, int sy, int gx, int gy) {
  if (path[0] == -1)
    return;
  else {
    std::vector<int> moveX { 1, 1, 0, -1, -1, -1, 0, 1 };
    std::vector<int> moveY { 0, 1, 1, 1, 0, -1, -1, -1 };
    int a = 0, b = 0;
    for (auto t : path) {
      a += moveX[t];
      b += moveY[t];
      _map[a][b] = 2;
    }
    _map[sx][sy] = 3;
    _map[gx][gy] = 4;
    for (auto &row : _map) {
      for (int col : row) {
        if (col == 1)
          std::cout << '.';
        else if (col == 0)
          std::cout << '#';
        else if (col == 2)
          std::cout << '*';
        else if (col == 3)
          std::cout << 'S';
        else if (col == 4)
          std::cout << 'G';
      }
      std::cout << std::endl;
    }
  }
}
