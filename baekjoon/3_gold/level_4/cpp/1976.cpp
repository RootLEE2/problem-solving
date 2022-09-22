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
#define MAX_N 202
#define MAX_M 1003
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
  int u, v;
} edge;

int N, M;
vector<edge> roads;
int plan[MAX_M];

int parent[MAX_N];

int __find_parent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = __find_parent(parent[x]);
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
  for (edge road : roads) {
    union_set(road);
  }

  for (int i = 1; i < M; i++) {
    edge tmp = { plan[i - 1], plan[i] };
    if (is_same_parent(tmp)) {
      continue;
    }

    cout << "NO";
    return;
  }

  cout << "YES";
}

void input() {
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    parent[i] = i;
    for (int j = 1; j <= N; j++) {
      int road; cin >> road;
      if (road == 1) {
        edge tmp = { i, j };
        roads.push_back(tmp);
      }
    }
  }

  for (int i = 0; i < M; i++) {
    cin >> plan[i];
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}