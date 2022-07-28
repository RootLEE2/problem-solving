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
#define MAX_M 10004
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

struct ticket {
  int to;
  int cost, time;

  bool operator<(const ticket &o) const {
    return time > o.time;
  }
};

int N, M, K;
vector<ticket> airport[MAX_N];

int dp[MAX_N][MAX_M];

void dijkstra() {
  priority_queue<ticket> pq;
  pq.push({ 1, 0, 0 });
  dp[1][0] = 0;

  while(!pq.empty()) {
    ticket cur = pq.top();
    pq.pop();

    if (dp[cur.to][cur.cost] < cur.time) continue;

    for (ticket t : airport[cur.to]) {
      ticket next;
      next.to = t.to;
      next.cost = cur.cost + t.cost;
      next.time = cur.time + t.time;

      if (M < next.cost) continue;
      if (dp[next.to][next.cost] <= next.time) continue;

      dp[next.to][next.cost] = next.time;
      pq.push(next);
    }
  }
}

void solve() {
  memset(dp, 0x3f, sizeof(dp));

  dijkstra();

  int ans = INF;

  for (int i = 0; i <= M; i++) {
    ans = min(ans, dp[N][i]);
  }

  if (ans != INF) cout << ans << '\n';
  else cout << "Poor KCM\n";
}

void input() {
  cin >> N >> M >> K;

  for (int i = 0; i < K; i++) {
    int u, v, c, d; cin >> u >> v >> c >> d;

    airport[u].push_back({ v, c, d });
  }
}

int main() {
  fastio;
  
  int t; cin >> t;

  while (t--) {
    input();
    solve();
    
    for (int i = 1; i <= N; i++) {
      airport[i].clear();
    }
  }
  
  return 0;
}