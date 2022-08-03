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
#define MAX_N 102
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

int N, L, R;

ll dp[MAX_N][MAX_N][MAX_N];

void solve() {
  dp[1][1][1] = 1;

  for (int height = 2; height <= N; height++) {
    for (int leftVisible = 1; leftVisible <= N; leftVisible++) {
      for (int rightVisible = 1; rightVisible <= N; rightVisible++) {
        dp[height][leftVisible][rightVisible] = (dp[height - 1][leftVisible - 1][rightVisible] +
          dp[height - 1][leftVisible][rightVisible - 1] +
          dp[height - 1][leftVisible][rightVisible] * (height - 2)) % MOD;
      }
    }
  }

  cout << dp[N][L][R];
}

void input() {
  cin >> N >> L >> R;
}

int main() {
  fastio;

  input();
  solve();
  
  return 0;
}