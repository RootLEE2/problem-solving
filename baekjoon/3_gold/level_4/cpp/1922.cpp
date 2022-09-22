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
#define MAX_N 1003
#define MAX_M 100005
#define MAX_LENGTH 2503
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD(x) ((x) % 1000000007)
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

typedef struct edge {
  int u, v, cost;

  bool operator<(const edge &o) const {
    return cost > o.cost;
  }
} edge;

int N, M;
priority_queue<edge> cables;

int parent[MAX_N];

int __find_parent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = __find_parent(parent[x]);
}

void init_parent(int __size) {
  for (int i = 1; i <= __size; i++) {
    parent[i] = i;
  }
}

bool is_same_parent(edge e) {
  if (__find_parent(e.u) == __find_parent(e.v)) return true;
  return false;
}

void union_set(edge e) {
  int uParent = __find_parent(e.u);
  int vParent = __find_parent(e.v);

  parent[uParent] = vParent;
}

void solve() {
  init_parent(N);

  ll ans = 0;

  while (!cables.empty()) {
    edge cable = cables.top();
    cables.pop();

    if (!is_same_parent(cable)) {
      union_set(cable);
      ans += cable.cost;
    }
  }

  cout << ans;
}

void input() {
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    cables.push({ a, b, c });
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}