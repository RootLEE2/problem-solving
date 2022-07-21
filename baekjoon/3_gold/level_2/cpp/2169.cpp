#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
// #include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_NM 1003
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD 1000000007
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

int N, M;
int map[MAX_NM][MAX_NM];

int dp[MAX_NM][MAX_NM][3];
bool visited[MAX_NM][MAX_NM];

int dr[] = { 0, 1, 0 };
int dc[] = { -1, 0, 1 };

int dfs(int r, int c, int dir) {
  int &ret = dp[r][c][dir];

  if (r == N && c == M) return ret = map[r][c];
  if (ret != INF) return ret;

  int temp = -INF;

  visited[r][c] = true;

  for (int i = 0; i < 3; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];

    if (nr < 1 || N < nr || nc < 1 || M < nc) continue;
    if (visited[nr][nc]) continue;

    temp = max(temp, dfs(nr, nc, i));
  }

  visited[r][c] = false;

  return ret = map[r][c] + temp;
}

void solve() {
  memset(dp, 0x3f, sizeof(dp));

  cout << dfs(1, 1, 0);
}

void input() {
  cin >> N >> M;

  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= M; c++) {
      cin >> map[r][c];
    }
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}