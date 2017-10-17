#include <AStar.h>

AStar::AStar(int _startx, int _starty, int _goalx, int _goaly)
    : startx(_startx),
      starty(_starty),
      goalx(_goalx),
      goaly(_goaly) {
}


bool operator>(const Node &p, const Node &q) {
  return p.totalCost > q.totalCost;
}

  std::vector<int> AStar::pathFind(std::vector<std::vector<int> > vec) {
  int neighbours = 8;
  std::vector<int> moveX { 1, 1, 0, -1, -1, -1, 0, 1 };
  std::vector<int> moveY { 0, 1, 1, 1, 0, -1, -1, -1 };
  std::vector<int> path;
  int j;
  priority_queue<Node, std::vector<Node>, greater<Node> > ol;
  priority_queue<Node, std::vector<Node>, greater<Node> > temp;
  std::vector<std::vector<int> > open(10, std::vector<int>(10, 0));
  std::vector<std::vector<int> > visited(10, std::vector<int>(10, 0));
  std::vector<std::vector<int> > parentDir(10, std::vector<int>(10, 0));
  Node start(startx, starty, 0, 0);
  start.totalCost = start.fCal(goalx, goaly);
  ol.push(start);
  open[start.x][start.y] = start.totalCost;
  while (!ol.empty()) {
  Node current = ol.top();
  ol.pop();
  open[current.x][current.y] = 0;
  visited[current.x][current.y] = 1;

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
  int dir = 0;
  while (dir < 8) {
      int dx = current.x + moveX[dir], dy = current.y + moveY[dir];
    if (!(dx < 0 || dx > 9 || dy < 0 || dy > 9 || vec[dx][dy] == 0
            || visited[dx][dy] == 1)) {
        Node child(dx, dy, current.pathCost, current.totalCost);
        child.pathCost = child.gCal(dir);
        child.totalCost = child.fCal(goalx, goaly);
      if (open[dx][dy] == 0) {
          open[dx][dy] = child.totalCost;
          ol.push(child);
          parentDir[dx][dy] = (dir + neighbours / 2) % neighbours;
      }
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
  std::cout << "path not found" << std::endl;
  path = {-1};
  return path;
}

AStar::~AStar() {
}




