#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 100005
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

int N, M;
ll A[MAX_N];

ll segTree[1 << 18];  // int segTree[4 * MAX_N];

void lazy_update(int node, int tl, int tr) {
  if (segTree[node] != 0) {
    if (tl == tr) return;

    int doubleNode = node << 1;  // int doubleNode = 2 * node;

    segTree[doubleNode] += segTree[node];
    segTree[doubleNode + 1] += segTree[node];

    segTree[node] = 0;
  }
}

ll value_queries(int node, int tl, int tr, int idx) {
  lazy_update(node, tl, tr);

  if (idx < tl || tr < idx) return 0;
  if (tl == tr) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  //int tm = (tl + tr) / 2;

  ll leftChild = value_queries(doubleNode, tl, tm, idx);
  ll rightChild = value_queries(doubleNode + 1, tm + 1, tr, idx);

  return leftChild + rightChild;
}

void update_queries(int node, int tl, int tr, int l, int r, int delta) {
  lazy_update(node, tl, tr);

  if (r < l) return;
  if (tl == l && tr == r) {
    if (tl == tr) {
      segTree[node] += delta;
    } else {
      int doubleNode = node << 1;  // int doubleNode = 2 * node;

      segTree[doubleNode] += delta;
      segTree[doubleNode + 1] += delta;
    }

    return;
  }

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  //int tm = (tl + tr) / 2;

  update_queries(doubleNode, tl, tm, l, min(tm, r), delta);
  update_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r, delta);
}

void build_seg_tree(int node, int tl, int tr) {
  if (tl == tr) {
    segTree[node] = A[tl];
    return;
  }

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  //int tm = (tl + tr) / 2;

  build_seg_tree(doubleNode, tl, tm);
  build_seg_tree(doubleNode + 1, tm + 1, tr);
}

void solve() {
  build_seg_tree(1, 1, N);

  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;

    if (a == 1) {
      int i, j, k;
      cin >> i >> j >> k;

      update_queries(1, 1, N, i, j, k);
    }
    else if (a == 2) {
      int x;
      cin >> x;

      cout << value_queries(1, 1, N, x) << '\n';
    }
  }
}

void input() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  cin >> M;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
