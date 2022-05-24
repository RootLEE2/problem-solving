#include <iostream>
#include <stdlib.h>
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
#define MOD(x) ((x) % 1000000007)
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

int N, Q;

ll segTree[1 << 21];  // int segTree[4 * MAX_N];

ll sum_queries(int node, int tl, int tr, int l, int r) {
  if (r < l) return 0;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl +tr) / 2;

  ll leftChild = sum_queries(doubleNode, tl, tm, l, min(tm, r));
  ll rightChild = sum_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  return leftChild + rightChild;
}

void update_query(int node, int tl, int tr, int idx, int delta) {
  if (idx < tl || tr < idx) return;

  segTree[node] += delta;

  if (tl == tr) return;

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl +tr) / 2;

  update_query(doubleNode, tl, tm, idx, delta);
  update_query(doubleNode + 1, tm + 1, tr, idx, delta);
}

void solve() {
  for (int i = 0; i < Q; i++) {
    int a;
    cin >> a;

    if (a == 1) {
      int p, x;
      cin >> p >> x;

      update_query(1, 1, N, p, x);
    }
    else if (a == 2) {
      int p, q;
      cin >> p >> q;

      cout << sum_queries(1, 1, N, p, q) << '\n';
    }
  }
}

void input() {
  cin >> N >> Q;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
