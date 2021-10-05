#include <iostream>
#include <queue>
using namespace std;
#define MAX_SIZE 1000

struct Point {
  int x, y, cost;
};

struct cmp {
  bool operator()(Point a, Point b) {
    return a.cost > b.cost;
  }
};

int m, n;
short graph[MAX_SIZE][MAX_SIZE];
priority_queue<Point, vector<Point>, cmp> pq;
bool visited[MAX_SIZE][MAX_SIZE];

short dx[4] = {0,0,-1,1};
short dy[4] = {-1,1,0,0};

int bfs() {
  if (graph[0][0] == -1 || graph[m-1][n-1] == -1) return -1;
  pq.push({0,0,graph[0][0]});
  visited[0][0] = true;

  int cx, cy, nx, ny, c;
  while (!pq.empty()) {
    cx = pq.top().x;
    cy = pq.top().y;
    c = pq.top().cost;
    pq.pop();

    if(cx == n-1 && cy == m-1) return c;

    for (int i = 0; i < 4; i++) {
      nx = cx + dx[i];
      ny = cy + dy[i];

      if (0 <= nx && 0 <= ny && nx < n && ny < m) {
        if (!visited[ny][nx] && graph[ny][nx] != -1) {
          pq.push({nx,ny,c+graph[ny][nx]});
          visited[ny][nx] = true;
        }
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> m >> n;
  for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> graph[i][j];
  
  cout << bfs();
}