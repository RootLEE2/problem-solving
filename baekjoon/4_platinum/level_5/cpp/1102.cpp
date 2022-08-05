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
#define MAX_N 16
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

int N, P;
int cost[MAX_N][MAX_N];
string curState;

int dp[MAX_N][1 << MAX_N];

bool check_condition(int state) {
  int cnt = 0;

  while (state) {
    cnt += state & 1;
    state >>= 1;
  }

  return P <= cnt;
}

int find_min_repair_cost(int generator, int state) {
  if (check_condition(state)) return 0;

  int &ret = dp[generator][state];

  if (ret != -1) return ret;

  ret = INF;
  for (int i = 0; i < N; i++) {
    if (((state >> i) & 1) == 0) {
      int nextState = state | (1 << i);

      for (int j = 0; j < N; j++) {
        if (((nextState >> j) & 1) == 1) {
          ret = min(ret, cost[generator][i] + find_min_repair_cost(j, nextState));
        }
      }
    }
  }

  return ret;
}

void solve() {
  int startState = 0;
  int numOfNotBroken = 0;

  for (int i = 0; i < N; i++) {
    if (curState[i] == 'Y') {
      startState |= (1 << i);
      numOfNotBroken++;
    }
  }

  if (P <= numOfNotBroken) {
    cout << 0;
    return;
  }

  memset(dp, -1, sizeof(dp));
  int ans = INF;

  for (int i = 0; i < N; i++) {
    if (((startState >> i) & 1) == 1) {
      ans = min(ans, find_min_repair_cost(i, startState));
    }
  }

  if (ans == INF) cout << -1;
  else cout << ans;
}

void input() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> cost[i][j];
    }
  }

  cin >> curState;

  cin >> P;
}

int main() {
  fastio;

  input();
  solve();
  
  return 0;
}