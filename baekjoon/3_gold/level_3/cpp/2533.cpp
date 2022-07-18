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
#define MAX_N 1000006
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD(x) ((x) % 1000000007)
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

int N;
vector<int> edge[MAX_N];

int dp[MAX_N][2];
bool visited[MAX_N];

void dfs(int node) {
  visited[node] = true;
  dp[node][1] = 1;
  
  for (int childNode : edge[node]) {
    if (visited[childNode]) continue;
    
    dfs(childNode);
    
    dp[node][0] += dp[childNode][1];
    dp[node][1] += min(dp[childNode][0], dp[childNode][1]);
  }
}

void solve() {
  dfs(1);
  
  cout << min(dp[1][0], dp[1][1]);
}

void input() {
  cin >> N;
  
  for (int i = 1; i < N; i++) {
    int u, v; cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}