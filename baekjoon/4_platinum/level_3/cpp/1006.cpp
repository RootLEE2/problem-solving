/**
 * @ref https://casterian.net/algo-prob/boj1006.html
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
#define MAX_N 10004
#define MAX_M 21
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

int N, W;
int enemy[MAX_N][2];

int ful[MAX_N];
int bot[MAX_N];
int top[MAX_N];

void calc_cycle(int startLineIdx) {
  for (int i = startLineIdx; i <= N; i++) {
    ful[i + 1] = min(bot[i] + 1, top[i] + 1);

    // both(full) empty
    if (enemy[i][0] + enemy[i][1] <= W) ful[i + 1] = min(ful[i + 1], ful[i] + 1);
    if (1 < i && enemy[i - 1][0] + enemy[i][0] <= W && enemy[i - 1][1] + enemy[i][1] <= W) ful[i + 1] = min(ful[i + 1], ful[i - 1] + 2);

    if (i < N) {
      // bottom empty
      bot[i + 1] = ful[i + 1] + 1;
      if (enemy[i][0] + enemy[i + 1][0] <= W) bot[i + 1] = min(bot[i + 1], top[i] + 1);

      // top empty
      top[i + 1] = ful[i + 1] + 1;
      if (enemy[i][1] + enemy[i + 1][1] <= W) top[i + 1] = min(top[i + 1], bot[i] + 1);
    }
  }
}

void solve() {
  int ans = INF;

  ful[1] = 0;
  bot[1] = top[1] = 1;
  calc_cycle(1);
  ans = min(ans, ful[N + 1]);

  if (N == 1) {
    cout << ans << '\n';
    return;
  }

  if (enemy[0][0] + enemy[1][0] <= W) {
    ful[2] = 1;
    bot[2] = 2;
    top[2] = (enemy[1][1] + enemy[2][1] <= W) ? 1 : 2;
    calc_cycle(2);
    ans = min(ans, top[N] + 1);
  }

  if (enemy[0][1] + enemy[1][1] <= W) {
    ful[2] = 1;
    bot[2] = (enemy[1][0] + enemy[2][0] <= W) ? 1 : 2;
    top[2] = 2;
    calc_cycle(2);
    ans = min(ans, bot[N] + 1);
  }

  if (enemy[0][0] + enemy[1][0] <= W && enemy[0][1] + enemy[1][1] <= W) {
    ful[2] = 0;
    bot[2] = top[2] = 1;
    calc_cycle(2);
    ans = min(ans, ful[N] + 2);
  }

  cout << ans << '\n';
}

void input() {
  cin >> N >> W;

  for (int i = 1; i <= N; i++) cin >> enemy[i][0];
  for (int i = 1; i <= N; i++) cin >> enemy[i][1];

  enemy[0][0] = enemy[N][0];
  enemy[0][1] = enemy[N][1];
}

int main() {
  fastio;

  int T; cin >> T;
  while (T--) {
    input();
    solve();
  }

  return 0;
}