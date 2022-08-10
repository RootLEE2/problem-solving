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

int dp[MAX_LENGTH];

void solve() {
  dp[0] = dp[1] = 1;
  for (int i = 2; i < MAX_LENGTH; i++) {
    ll tmp = 0;
    for (int j = 1; j <= i >> 1; j++) {
      tmp += (ll)dp[i - j] * dp[j - 1] % MOD;
    }
    dp[i] = (2 * tmp + ((i & 1) ? (ll)dp[i >> 1] * dp[i >> 1] : 0)) % MOD;
  }

  int T; cin >> T;
  while (T--) {
    int L; cin >> L;
    cout << ((L & 1) ? 0 : dp[L >> 1]) << '\n';
  }
}

void input() {
  
}

int main() {
  fastio;

  input();
  solve();
  
  return 0;
}