#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 101

int N, maxHeight = -1, h; 

int graph[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int y, int x) {
  visited[y][x] = true;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (0 <= nx && 0 <= ny && nx < N && ny < N)
      if (!visited[ny][nx] && h < graph[ny][nx])
        dfs(ny,nx);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> graph[i][j];
      if (maxHeight < graph[i][j])
        maxHeight = graph[i][j];
    }
  }

  int result = 1;
  for (h = 1; h < maxHeight; h++) {
    memset(visited, false, sizeof(visited));

    int cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (!visited[i][j] && h < graph[i][j]) {
          dfs(i,j);
          cnt++;
        }
      }
    }

    result = max(result, cnt);
  }

  cout << result;

  return 0;
}
