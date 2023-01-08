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

#define MAX_N 10004
#define MAX_T 1003

int n, t, m;
int s, e;
vector<pair<pair<int,int>,int>> adjByTime[MAX_T];

int dp[MAX_T][MAX_N];

void solve() {
  memset(dp, 0x3f, sizeof(dp));

  dp[0][s] = 0;
  
  for (int now = 1; now <= t; now++) {
    for (pair<pair<int,int>,int> adj : adjByTime[now]) {
      int u = adj.first.first;
      int v = adj.first.second;
      int w = adj.second;

      dp[now][v] = min(dp[now][v], dp[now - 1][u] + w);
      dp[now][u] = min(dp[now][u], dp[now - 1][v] + w);
    }

    for (int i = 0; i < n; i++) {
      dp[now][i] = min(dp[now][i], dp[now - 1][i]);
    }
  }

  cout << (dp[t][e] != INF ? dp[t][e] : -1);
}

void input() {
  cin >> n >> t >> m;
  cin >> s >> e;

  for (int i = 1; i <= t; i++) {
    for (int j = 0; j < m; j++) {
      int u, v, w; cin >> u >> v >> w;
      adjByTime[i].push_back({ { u, v }, w });
    }
  }
}

int main() {
  fastio;

  input();
  solve();

  return 0;
}
