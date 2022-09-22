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
#define MAX_M 10004
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

typedef struct friends {
  int v, w;
} friends;

int N, M, k;
int A[MAX_N];
friends relation[MAX_M];

int parent[MAX_N];

int __find_parent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = __find_parent(parent[x]);
}

void union_set(friends rel) {
  int vParent = __find_parent(rel.v);
  int wParent = __find_parent(rel.w);

  if (A[vParent] < A[wParent]) {
    parent[wParent] = vParent;
  } else {
    parent[vParent] = wParent;
  }
}

void solve() {
  for (int i = 0; i < M; i++) {
    union_set(relation[i]);
  }

  int money = 0;

  for (int i = 1; i <= N; i++) {
    if (parent[i] == i) money += A[i];
  }

  if (k < money) cout << "Oh no";
  else cout << money;
}

void input() {
  cin >> N >> M >> k;

  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    parent[i] = i;
  }

  for (int i = 0; i < M; i++) {
    int v, w; cin >> v >> w;
    relation[i].v = v;
    relation[i].w = w;
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}