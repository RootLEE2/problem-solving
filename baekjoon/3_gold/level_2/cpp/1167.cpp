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

int V;
vector<pair<int,int>> adjList[100005];

int maxDist, maxVertex;
bool visited[100005];

void dfs(int vertex, int dist) {
  if (maxDist < dist) {
    maxVertex = vertex;
    maxDist = dist;
  }

  for (pair<int,int> adj : adjList[vertex]) {
    int nextVert = adj.first;
    int nextDist = dist + adj.second;

    if (visited[nextVert]) continue;

    visited[nextVert] = true;
    dfs(nextVert, nextDist);
    visited[nextVert] = false;
  }
}

void solve() {
  cin >> V;
  for (int i = 0; i < V; i++) {
    int v; cin >> v;
    while (true) {
      int u, cost;
      cin >> u;
      if (u == -1) break;
      cin >> cost;
      adjList[v].push_back({ u, cost });
    }
  }

  visited[1] = true;
  dfs(1, 0);
  visited[1] = false;

  memset(visited, 0, sizeof(visited));
  maxDist = 0;

  visited[maxVertex] = true;
  dfs(maxVertex, 0);
  visited[maxVertex] = false;

  cout << maxDist;
}

int main() {
  fastio;

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
