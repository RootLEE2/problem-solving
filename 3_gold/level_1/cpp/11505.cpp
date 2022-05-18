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
#define MOD(x) ((x) % 1000000007)
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

int N, M, K;
int numArr[MAX_N];

int segTree[1 << 21];  // int segTree[4 * MAX_N];

int product_queries(int node, int tl, int tr, int l, int r) {
  if (r < l) return 1;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  int leftChild = product_queries(doubleNode, tl, tm, l, min(tm, r));
  int rightChild = product_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  return (int)MOD((ll)leftChild * (ll)rightChild);
}

void update_query(int node, int tl, int tr, int idx, int newVal) {
  if (idx < tl || tr < idx) return;

  if (tl == tr) {
    segTree[node] = newVal;
    return;
  }

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_query(doubleNode, tl, tm, idx, newVal);
  update_query(doubleNode + 1, tm + 1, tr, idx, newVal);

  segTree[node] = (int)MOD((ll)segTree[doubleNode] * (ll)segTree[doubleNode + 1]);
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

  segTree[node] = (int)MOD((ll)segTree[doubleNode] * (ll)segTree[doubleNode + 1]);
}

void solve() {
  build_seg_tree(1, 1, N);

  int MK = M + K;

  for (int i = 0; i < MK; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 1) {
      update_query(1, 1, N, b, c);
    } else if (a == 2) {
      cout << product_queries(1, 1, N, b, c) << '\n';
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
