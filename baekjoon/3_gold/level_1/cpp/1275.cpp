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

int N, Q;
ll numArr[MAX_N];  // 모든 수의 범위가 -2^31 ~ (2^31)-1인데, 왜 ll이어야 하는지 모르겠다. 왜 int로 하면 오류가 나지?

ll segTree[1 << 18];  // int segTree[4 * MAX_N];

void update_query(int node, int tl, int tr, int idx, ll delta) {
  if (idx < tl || tr < idx) return;

  segTree[node] += delta;

  if (tl == tr) return;

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_query(doubleNode, tl, tm, idx, delta);
  update_query(doubleNode + 1, tm + 1, tr, idx, delta);
}

ll sum_queries(int node, int tl, int tr, int l, int r) {
  if (r < l) return 0;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  ll leftChild = sum_queries(doubleNode, tl, tm, l, min(tm, r));
  ll rightChild = sum_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  return leftChild + rightChild;
}

void build_seg_tree(int node, int tl, int tr) {
  if (tl == tr) {
    segTree[node] = numArr[tl];
    return;
  }

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  build_seg_tree(doubleNode, tl, tm);
  build_seg_tree(doubleNode + 1, tm + 1, tr);

  segTree[node] = segTree[doubleNode] + segTree[doubleNode + 1];
}

void solve() {
  build_seg_tree(1, 1, N);

  for (int i = 0; i < Q; i++) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    if (y < x) swap(x, y);

    cout << sum_queries(1, 1, N, x, y) << '\n';

    ll delta = b - numArr[a];
    update_query(1, 1, N, a, delta);
    numArr[a] = b;
  }
}

void input() {
  cin >> N >> Q;

  for (int i = 1; i <= N; i++) {
    cin >> numArr[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
