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
#define MAX_NM 51
#define MAX_LENGTH 102
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
int board[MAX_NM][MAX_NM];

int dp[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int dfs(int r, int c) {
  if (r < 1 || N < r || c < 1 || M < c || board[r][c] == 0) return 0;
  if (visited[r][c]) {
    cout << -1;
    exit(0);
  }

  int &ret = dp[r][c];

  if (ret != -1) return ret;

  const int moveRange = board[r][c];
  visited[r][c] = true;

  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i] * moveRange;
    int nc = c + dc[i] * moveRange;

    ret = max(ret, dfs(nr, nc) + 1);
  }

  visited[r][c] = false;

  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));

  cout << dfs(1, 1);
}

void input() {
  cin >> N >> M;

  for (int r = 1; r <= N; r++) {
    string tempBoard; cin >> tempBoard;
    tempBoard = ' ' + tempBoard;

    for (int c = 1; c <= M; c++) {
      if (tempBoard[c] == 'H') board[r][c] = 0;
      else board[r][c] = tempBoard[c] - '0';
    }
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}