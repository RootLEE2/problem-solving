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
#define MAX_N 302
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

int N, M;
int profit[MAX_N][MAX_M];

int dp[MAX_M][MAX_N];
int invest[MAX_M][MAX_N];

void solve() {
  for (int i = 1; i <= M; i++) {
    for (int j = 0; j <= N; j++) {
      for (int k = 0; k <= j; k++) {
        if (dp[i][j] < dp[i - 1][j - k] + profit[k][i]) {
          dp[i][j] = dp[i - 1][j - k] + profit[k][i];
          invest[i][j] = k;
        }
      }
    }
  }

  vector<int> ans;
  int n = N, inv;

  for (int i = M; i > 0; i--, n -= inv) {
    inv = invest[i][n];
    ans.push_back(inv);
  }

  reverse(ans.begin(), ans.end());
  cout << dp[M][N] << '\n';
  for (int res : ans) cout << res << ' ';
}

void input() {
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    int invest; cin >> invest;
    for (int j = 1; j <= M; j++) cin >> profit[i][j];
  }
}

int main() {
  fastio;

  input();
  solve();

  return 0;
}