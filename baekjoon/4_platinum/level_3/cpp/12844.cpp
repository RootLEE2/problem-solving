#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 500005
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
int A[MAX_N];

int segTree[1 << 20];  // int segTree[4 * MAX_N];
int lazyTree[1 << 20];  // int lazyTree[4 * MAX_N];

void lazy_propagation(int node, int tl, int tr) {
  segTree[node] ^= ((tr - tl + 1) & 1) * lazyTree[node];

  if (tl != tr) {
    int doubleNode = node << 1;  // int doubleNode = 2 * node;

    lazyTree[doubleNode] ^= lazyTree[node];
    lazyTree[doubleNode + 1] ^= lazyTree[node];
  }
}

void lazy_update(int node, int tl, int tr) {
  if (lazyTree[node] == 0) return;

  lazy_propagation(node, tl, tr);

  lazyTree[node] = 0;
}

int xor_queries(int node, int tl, int tr, int l, int r) {
  lazy_update(node, tl, tr);

  if (r < l) return 0;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  int leftChild = xor_queries(doubleNode, tl, tm, l, min(tm, r));
  int rightChild = xor_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  return leftChild ^ rightChild;
}

void update_queries(int node, int tl, int tr, int l, int r, int delta) {
  lazy_update(node, tl, tr);

  if (r < l) return;
  if (tl == l && tr == r) {
    lazyTree[node] = delta;
    lazy_propagation(node, tl, tr);
    lazyTree[node] = 0;
    return;
  }

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_queries(doubleNode, tl, tm, l, min(tm, r), delta);
  update_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r, delta);

  segTree[node] = segTree[doubleNode] ^ segTree[doubleNode + 1];
}

void build_seg_tree(int node, int tl, int tr) {
  if (tl == tr) {
    segTree[node] = A[tl];
    return;
  }

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  build_seg_tree(doubleNode, tl, tm);
  build_seg_tree(doubleNode + 1, tm + 1, tr);

  segTree[node] = segTree[doubleNode] ^ segTree[doubleNode + 1];
}

void solve() {
  build_seg_tree(1, 0, N - 1);

  for (int m = 0; m < M; m++) {
    int c;
    cin >> c;

    if (c == 1) {
      int i, j, k;
      cin >> i >> j >> k;

      update_queries(1, 0, N - 1, i, j, k);
    }
    else if (c == 2) {
      int i, j;
      cin >> i >> j;

      cout << xor_queries(1, 0, N - 1, i, j) << '\n';
    }
  }
}

void input() {
  cin >> N;

  for (int i = 0; i < N; i++) {
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
