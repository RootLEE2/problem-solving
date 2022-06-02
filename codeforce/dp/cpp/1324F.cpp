#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX_N 200005
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

int n;
int treeColor[MAX_N];
vector<int> adjList[MAX_N];

bool visited[MAX_N];
int maxFromChild[MAX_N];
int maxFromParent[MAX_N];

void dfs_max_from_parent(int vertex, int fromParent) {
  visited[vertex] = true;

  maxFromParent[vertex] = fromParent;

  for (int child : adjList[vertex]) {
    if (visited[child]) continue;

    int tempFromParent = max(0,
      fromParent
      + treeColor[vertex] + maxFromChild[vertex]
      - max(0, treeColor[child] + maxFromChild[child])
    );

    dfs_max_from_parent(child, tempFromParent);
  }
}

int dfs_max_from_child(int vertex) {
  visited[vertex] = true;

  int colorSum = 0;

  for (int child : adjList[vertex]) {
    if (visited[child]) continue;

    int tempColor = dfs_max_from_child(child);

    if (0 < tempColor) {
      colorSum += tempColor;
    }
  }

  maxFromChild[vertex] = colorSum;

  return treeColor[vertex] + colorSum;
}

void solve() {
  dfs_max_from_child(1);
  memset(visited, 0, sizeof(visited));
  dfs_max_from_parent(1, 0);

  for (int i = 1; i <= n; i++) {
    cout << maxFromParent[i] + treeColor[i] + maxFromChild[i] << ' ';
  }
}

void input() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int a_i;
    cin >> a_i;

    if (a_i == 0) a_i = -1;

    treeColor[i] = a_i;
  }

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;

    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}