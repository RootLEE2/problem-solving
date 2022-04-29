#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N_M 250 
#define MAX_LENGTH 100001
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

int M, N;
int banner[MAX_N_M][MAX_N_M];
bool visited[MAX_N_M][MAX_N_M];

int dr[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void bfs(int r, int c) {
  queue<pair<int, int>> q;
  q.push(make_pair(r, c));
  visited[r][c] = true;

  while (!q.empty()) {
    int curR = q.front().first;
    int curC = q.front().second;
    q.pop();

    for (int i = 0; i < 8; i++) {
      int nextR = curR + dr[i];
      int nextC = curC + dc[i];

      if (nextR < 0 || M <= nextR || nextC < 0 || N <= nextC) continue;

      if (!visited[nextR][nextC] && banner[nextR][nextC] == 1) {
        visited[nextR][nextC] = true;
        q.push(make_pair(nextR, nextC));
      }
    }
  }
}

void solve() {
  int cnt = 0;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (banner[i][j] == 1 && !visited[i][j]) {
        bfs(i, j);
        cnt++;
      }
    }
  }

  cout << cnt;
}

void input() {
  cin >> M >> N;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> banner[i][j];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
