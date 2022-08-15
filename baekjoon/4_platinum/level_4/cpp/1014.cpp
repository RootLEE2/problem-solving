/**
 * @ref https://velog.io/@ks1ksi/%EB%B0%B1%EC%A4%80-1014%EB%B2%88-%EC%BB%A8%EB%8B%9D
 * @ref https://www.secmem.org/blog/2019/10/19/handy-function-about-bit/
 */

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
#define MAX_N 11
#define MAX_LENGTH 5003 >> 1
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
int cantSit[MAX_N];

int dp[MAX_N][1 << MAX_N];

int dfs(int row, int state) {
  if (row == N) return 0;

  int &ret = dp[row][state];
  if (ret != -1) return ret;

  for (int s = 0; s < (1 << M); s++) {
    if (s & cantSit[row]) continue;

    bool flag = true;

    for (int c = 0; c < M; c++) {
      if ((s & (1 << c)) == 0) continue;

      if (0 < c && (state & (1 << (c - 1))) || (s & (1 << (c - 1)))) {
        flag = false;
        break;
      } else if (c < M - 1 && (state & (1 << (c + 1))) || (s & (1 << (c + 1)))) {
        flag = false;
        break;
      }
    }

    if (flag) ret = max(ret, dfs(row + 1, s) + __builtin_popcount(s));
  }

  return ret;
}

void solve() {
  cout << dfs(0, 0) << '\n';
}

void input() {
  cin >> N >> M;

  for (int r = 0; r < N; r++) {
    for (int c = 0; c < M; c++) {
      char seat; cin >> seat;
      if (seat == 'x') cantSit[r] |= (1 << c);
    }
  }
}

int main() {
  fastio;

  int C; cin >> C;
  while (C--) {
    memset(dp, -1, sizeof(dp));
    memset(cantSit, 0, sizeof(cantSit));
    
    input();
    solve();
  }
  
  return 0;
}