#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

#define MAX_RC 102
#define MAX_N 102

int R, C;
char cave[MAX_RC][MAX_RC];

int N;
int stickHeight[MAX_N];

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

vector<pair<int,int>> clusters;
bool isCluster[MAX_RC][MAX_RC];
bool visited[MAX_RC][MAX_RC];

void fallOffCluster() {
  bool isBottom = false;

  while (true) {
    for (int i = 0; i < clusters.size(); i++) {
      int r = clusters[i].first;
      int c = clusters[i].second;

      if (r <= 1 || (cave[r - 1][c] == 'x' && !isCluster[r - 1][c])) {
        isBottom = true;
        break;
      }
    }

    if (isBottom) break;

    for (int i = 0; i < clusters.size(); i++) {
      int r = clusters[i].first;
      int c = clusters[i].second;

      cave[r][c] = '.';
      isCluster[r][c] = false;
    }

    for (int i = 0; i < clusters.size(); i++) {
      int r = clusters[i].first;
      int c = clusters[i].second;

      cave[r - 1][c] = 'x';
      clusters[i] = { r - 1, c };
      isCluster[r - 1][c] = true;
    }
  }
}

void findCluster(int r, int c) {
  queue<pair<int,int>> q;
  q.push({ r, c });
  clusters.push_back({ r, c });
  isCluster[r][c] = true;
  visited[r][c] = true;

  while (!q.empty()) {
    int curR = q.front().first;
    int curC = q.front().second;
    q.pop();

    if (curR == 1) {
      clusters.clear();
      break;
    }

    for (int i = 0; i < 4; i++) {
      int nextR = curR + dr[i];
      int nextC = curC + dc[i];

      if (nextR < 1 || nextR > R || nextC < 0 || nextC >= C) continue;
      if (visited[nextR][nextC]) continue;
      if (cave[nextR][nextC] == '.') continue;

      visited[nextR][nextC] = true;
      q.push({ nextR, nextC });
      clusters.push_back({ nextR, nextC });
      isCluster[nextR][nextC] = true;
    }
  }
}

int findMineral(int turn, int height) {
  if ((turn & 1) == 0) {
    // left to right
    for (int i = 0; i < C; i++) {
      if (cave[height][i] == 'x') {
        return i;
      }
    }
  } else {
    // right to left
    for (int i = C - 1; i >= 0; i--) {
      if (cave[height][i] == 'x') {
        return i;
      }
    }
  }
  return -1;
}

void destoryMineral(int turn, int height) {
  int idxC = findMineral(turn, height);

  if (idxC == -1) return;
  cave[height][idxC] = '.';

  for (int i = 0; i < 4; i++) {
    int nextR = height + dr[i];
    int nextC = idxC + dc[i];

    if (nextR < 1 || nextR > R || nextC < 0 || nextC >= C) continue;
    if (cave[nextR][nextC] == '.') continue;

    clusters.clear();
    memset(isCluster, 0, sizeof(isCluster));
    memset(visited, 0, sizeof(visited));

    findCluster(nextR, nextC);
    if (!clusters.empty()) fallOffCluster();
  }
}

void solve() {
  for (int i = 0; i < N; i++) {
    destoryMineral(i, stickHeight[i]);
  }

  for (int i = 0; i < R; i++) {
    cout << cave[R - i] << '\n';
  }
}

void input() {
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    cin >> cave[R - i];
  }

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> stickHeight[i];
  }
}

int main() {
  fastio;

  input();
  solve();

  return 0;
}
