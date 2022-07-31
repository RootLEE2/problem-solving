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

int N;
int people[MAX_N];
vector<int> adjTown[MAX_N];

int dp[MAX_N][2];
bool visited[MAX_N];

void dfs(int curTown) {
  if (visited[curTown]) return;

  visited[curTown] = true;

  dp[curTown][0] = 0;
  dp[curTown][1] = people[curTown];

  for (int nextTown : adjTown[curTown]) {
    if (visited[nextTown]) continue;

    dfs(nextTown);

    dp[curTown][0] += max(dp[nextTown][0], dp[nextTown][1]);
    dp[curTown][1] += dp[nextTown][0];
  }

  visited[curTown] = false;
}

void solve() {
  dfs(1);
  cout << max(dp[1][0], dp[1][1]);
}

void input() {
  cin >> N;
  
  for (int i = 1; i <= N; i++) {
    cin >> people[i];
  }

  for (int i = 1; i < N; i++) {
    int u, v; cin >> u >> v;

    adjTown[u].push_back(v);
    adjTown[v].push_back(u);
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}