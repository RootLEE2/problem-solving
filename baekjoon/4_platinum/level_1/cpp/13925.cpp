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
int A[MAX_N];

ll segTree[1 << 18];  // ll segTree[4 * MAX_N];
ll lazyTree[1 << 18][2];  // ll segTree[4 * MAX_N];

void lazy_propagation(int node, int tl, int tr) {
  ll nodeLazyAdd = lazyTree[node][0];
  ll nodeLazyMul = lazyTree[node][1];
  
  segTree[node] = MOD((tr - tl + 1) * nodeLazyAdd + segTree[node] * nodeLazyMul);

  if (tl != tr) {
    int doubleNode = node << 1;  // int doubleNode = 2 * node;

    for (int i = doubleNode; i <= doubleNode + 1; i++) {
      ll ithLazyAdd = lazyTree[i][0];
      ll ithLazyMul = lazyTree[i][1];

      lazyTree[i][0] = MOD(nodeLazyMul * ithLazyAdd + nodeLazyAdd);
      lazyTree[i][1] = MOD(nodeLazyMul * ithLazyMul);
    }
  }
}

void lazy_update(int node, int tl, int tr) {
  if (lazyTree[node][0] == 0
    && lazyTree[node][1] == 1) return;

  lazy_propagation(node, tl, tr);

  lazyTree[node][0] = 0;
  lazyTree[node][1] = 1;
}

ll sum_queries(int node, int tl, int tr, int l, int r) {
  lazy_update(node, tl, tr);

  if (r < l) return 0;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  ll leftChild = sum_queries(doubleNode, tl, tm, l, min(tm, r));
  ll rightChild = sum_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  return MOD(leftChild + rightChild);
}

void update_queries(int node, int tl, int tr, int l, int r, int addVal, int mulVal) {
  lazy_update(node, tl, tr);

  if (r < l) return;
  if (tl == l && tr == r) {
    lazyTree[node][0] = MOD(lazyTree[node][0] * mulVal + addVal);
    lazyTree[node][1] = MOD(lazyTree[node][1] * mulVal);

    lazy_update(node, tl, tr);

    return;
  }

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_queries(doubleNode, tl, tm, l, min(tm, r), addVal, mulVal);
  update_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r, addVal, mulVal);

  segTree[node] = MOD(segTree[doubleNode] + segTree[doubleNode + 1]);
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

  segTree[node] = MOD(segTree[doubleNode] + segTree[doubleNode + 1]);
}

void solve() {
  build_seg_tree(1, 1, N);

  for (int m = 0; m < M; m++) {
    int c;
    cin >> c;

    int x, y, v;
    cin >> x >> y;
    if (c != 4) cin >> v;

    if (c == 1) {
      update_queries(1, 1, N, x, y, v, 1);
    } else if (c == 2) {
      update_queries(1, 1, N, x, y, 0, v);
    } else if (c == 3) {
      update_queries(1, 1, N, x, y, v, 0);
    } else if (c == 4) {
      cout << sum_queries(1, 1, N, x, y) << '\n';
    }
  }
}

void input() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  cin >> M;

  int tempSize = 1 << 18;
  for (int i = 0; i < tempSize; i++) {
    lazyTree[i][1] = 1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
