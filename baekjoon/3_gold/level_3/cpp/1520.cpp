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
#define MAX_N_M 502
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD(x) ((x) % 1000000007)
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

int M, N;
int heightArr[MAX_N_M][MAX_N_M];

int dp[MAX_N_M][MAX_N_M];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int dfs(int r, int c) {
  if (r == M - 1 && c == N - 1) return 1;
  if (dp[r][c] != -1) return dp[r][c];

  int &ret = dp[r][c];
  ret = 0;

  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];

    if (nr < 0 || M <= nr || nc < 0 || N <= nc) continue;
    if (!(heightArr[nr][nc] < heightArr[r][c])) continue;

    ret += dfs(nr, nc);
  }

  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));

  cout << dfs(0, 0);
}

void input() {
  cin >> M >> N;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> heightArr[i][j];
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