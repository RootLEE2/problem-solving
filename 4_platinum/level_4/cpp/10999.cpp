/**
 * @ref https://www.acmicpc.net/blog/view/26
 * 
 */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 1000006
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
typedef long long ll;

int N, M, K;
ll numArr[MAX_N];

ll segTree[4 * MAX_N];
ll lazyTree[4 * MAX_N];

void lazy_update(int node, int tl, int tr) {
  if (lazyTree[node] != 0) {
    segTree[node] += (tr - tl + 1) * lazyTree[node];

    if (tl != tr) {
      lazyTree[2 * node] += lazyTree[node];
      lazyTree[2 * node + 1] += lazyTree[node];
    }

    lazyTree[node] = 0;
  }
}

ll sum_queries(int node, int tl, int tr, int l, int r) {
  lazy_update(node, tl, tr);

  if (r < l) return 0;
  if (tl == l && tr == r) return segTree[node];

  int tm = (tl + tr) / 2;

  ll leftChild = sum_queries(2 * node, tl, tm, l, min(tm, r));
  ll rightChild = sum_queries(2 * node + 1, tm + 1, tr, max(tm + 1, l), r);

  return leftChild + rightChild;
}

void update_query(int node, int tl, int tr, int l, int r, ll delta) {
  lazy_update(node, tl, tr);

  if (r < l) return;
  if (tl == l && tr == r) {
    segTree[node] += (tr - tl + 1) * delta;

    if (tl != tr) {
      lazyTree[2 * node] += delta;
      lazyTree[2 * node + 1] += delta;
    }

    return;
  }

  int tm = (tl + tr) / 2;

  update_query(2 * node, tl, tm, l, min(tm, r), delta);
  update_query(2 * node + 1, tm + 1, tr, max(tm + 1, l), r, delta);

  segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

ll build_seg_tree(int node, int tl, int tr) {
  if (tl == tr) {
    return segTree[node] = numArr[tl];
  }

  int tm = (tl + tr) / 2;

  ll leftChild = build_seg_tree(2 * node, tl, tm);
  ll rightChild = build_seg_tree(2 * node + 1, tm + 1, tr);

  return segTree[node] = leftChild + rightChild;
}

void solve() {
  build_seg_tree(1, 1, N);

  int sumOfMK = M + K;

  for (int i = 0; i < sumOfMK; i++) {
    int a, b, c;
    cin >> a;

    if (a == 1) {
      ll d;
      cin >> b >> c >> d;

      update_query(1, 1, N, b, c, d);
    } else if (a == 2) {
      cin >> b >> c;

      cout << sum_queries(1, 1, N, b, c) << '\n';
    }
  }
}

void input() {
  cin >> N >> M >> K;

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
