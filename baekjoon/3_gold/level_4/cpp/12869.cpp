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

#define MAX_HEALTH 61

int N;
int scvHealth[3];

int dp[MAX_HEALTH][MAX_HEALTH][MAX_HEALTH];

int dfs(int aHealth, int bHealth, int cHealth) {
  if (aHealth < 0) aHealth = 0;
  if (bHealth < 0) bHealth = 0;
  if (cHealth < 0) cHealth = 0;

  int &ret = dp[aHealth][bHealth][cHealth];

  if (ret != -1) return ret;

  ret = INF;
  ret = min(ret, dfs(aHealth - 9, bHealth - 3, cHealth - 1) + 1);
  ret = min(ret, dfs(aHealth - 9, bHealth - 1, cHealth - 3) + 1);
  ret = min(ret, dfs(aHealth - 3, bHealth - 9, cHealth - 1) + 1);
  ret = min(ret, dfs(aHealth - 3, bHealth - 1, cHealth - 9) + 1);
  ret = min(ret, dfs(aHealth - 1, bHealth - 9, cHealth - 3) + 1);
  ret = min(ret, dfs(aHealth - 1, bHealth - 3, cHealth - 9) + 1);

  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 0;

  cout << dfs(scvHealth[0], scvHealth[1], scvHealth[2]);
}

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> scvHealth[i];
  }
}

int main() {
  fastio;

  input();
  solve();

  return 0;
}
