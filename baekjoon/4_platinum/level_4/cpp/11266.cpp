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

set<int> set_articulation_point;

int id_cnt = 0;
int order_id[MAX_V];
int upper_id[MAX_V];
int parent_node[MAX_V];

/* SCC */
void scc_dfs(int node) {
  order_id[node] = upper_id[node] = ++id_cnt;

  int num_child = 0;

  for (int next_node : adj_list[node]) {
    if (parent_node[node] == next_node) continue;

    if (order_id[next_node] == 0) {
      parent_node[next_node] = node;
      num_child++;

      scc_dfs(next_node);

      if (parent_node[node] != 0 && order_id[node] <= upper_id[next_node]) set_articulation_point.insert(node);

      upper_id[node] = min(upper_id[node], upper_id[next_node]);
    } else {
      upper_id[node] = min(upper_id[node], order_id[next_node]);
    }
  }

  if (parent_node[node] == 0 && 1 < num_child) set_articulation_point.insert(node);
}

/* main */
void solve() {
  for (int i = 1; i <= V; i++) {
    if (parent_node[i] == 0) {
      scc_dfs(i);
    }
  }

  cout << set_articulation_point.size() << '\n';
  for (int node : set_articulation_point) {
    cout << node << ' ';
  }
}

void input() {
  cin >> V >> E;

  for (int i = 0; i < E; i++) {
    int A, B; cin >> A >> B;
    adj_list[A].push_back(B);
    adj_list[B].push_back(A);
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}