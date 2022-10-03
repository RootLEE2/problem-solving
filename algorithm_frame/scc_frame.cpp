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

#define MAX_N 100005
#define MAX_M 100005
#define MAX_V 10004
#define MAX_LENGTH 2503
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

#define SQUARE(x) ((x) * (x))
#define MOD(x) ((x) % 1000000007)

typedef long long ll;

int V, E;
vector<int> adj_list[MAX_V];

int id_cnt = 0;
int parent_id[MAX_V];
bool finished[MAX_V];
stack<int> stack_node;
vector<vector<int>> scc_list;

/* SCC */
int scc_dfs(int node) {
  parent_id[node] = ++id_cnt;
  stack_node.push(node);

  int min_parent = parent_id[node];

  for (int next_node : adj_list[node]) {
    if (parent_id[next_node] == 0) {
      min_parent = min(min_parent, scc_dfs(next_node));
    } else if (!finished[next_node]) {
      min_parent = min(min_parent, parent_id[next_node]);
    }
  }

  if (min_parent == parent_id[node]) {
    vector<int> scc;

    while (true) {
      int temp_node = stack_node.top();
      stack_node.pop();

      scc.push_back(temp_node);
      finished[temp_node] = true;

      if (temp_node == node) break;
    }

    scc_list.push_back(scc);
  }

  return min_parent;
}

/* main */
void solve() {
  for (int i = 1; i <= V; i++) {
    if (parent_id[i] == 0) scc_dfs(i);
  }
}

void input() {
  cin >> V >> E;

  for (int i = 0; i < E; i++) {
    int A, B; cin >> A >> B;
    adj_list[A].push_back(B);
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}