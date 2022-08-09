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

int n;
int weight[MAX_N];
vector<int> adjList[MAX_N];

int dp[MAX_N][2];

vector<int> ansRoute;

void trace(int node, int parent, bool isIncluded) {
  if (isIncluded) {
    ansRoute.push_back(node);

    for (int child : adjList[node]) {
      if (child == parent) continue;
      trace(child, node, false);
    }

    return;
  }

  for (int child : adjList[node]) {
    if (child == parent) continue;
    
    trace(child, node, (dp[child][0] < dp[child][1]) ? true : false);
  }
}

void dfs(int node, int parent) {
  dp[node][0] = 0;
  dp[node][1] = weight[node];

  for (int child : adjList[node]) {
    if (child == parent) continue;

    dfs(child, node);

    dp[node][0] += max(dp[child][0], dp[child][1]);
    dp[node][1] += dp[child][0];
  }
}

void solve() {
  dfs(1, 0);
  trace(1, 0, (dp[1][0] < dp[1][1]) ? true : false);

  sort(ansRoute.begin(), ansRoute.end());

  cout << max(dp[1][0], dp[1][1]) << '\n';
  for (int route : ansRoute) cout << route << ' ';
}

void input() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> weight[i];
  }

  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
}

int main() {
  fastio;

  input();
  solve();
  
  return 0;
}