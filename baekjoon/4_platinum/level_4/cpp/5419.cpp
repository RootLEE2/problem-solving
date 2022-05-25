#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 75003
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

struct coor {
  int x, y;
};

bool y_base_compare(coor a, coor b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y > b.y;
}

bool x_base_compare(coor a, coor b) {
  if (a.x == b.x) return a.y > b.y;
  return a.x > b.x;
}

int n;
coor island[MAX_N];

int segTree[1 << 18];  // int segTree[4 * MAX_N];

void update_query(int node, int tl, int tr, int idx) {
  if (idx < tl || tr < idx) return;

  segTree[node]++;

  if (tl == tr) return;

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_query(doubleNode, tl, tm, idx);
  update_query(doubleNode + 1, tm + 1, tr, idx);
}

int sum_queries(int node, int tl, int tr, int l, int r) {
  if (r < l) return 0;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  int leftChild = sum_queries(doubleNode, tl, tm, l, min(tm, r));
  int rightChild =sum_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  return leftChild + rightChild;
}

void coor_compress() {
  for (int i = 0; i < n; i++) {
    island[i].y = i + 1;
  }
}

void solve() {
  sort(island, island + n, y_base_compare);

  coor_compress();

  sort(island, island + n, x_base_compare);

  ll pairSum = 0;

  for (int i = 0; i < n; i++) {
    pairSum += sum_queries(1, 1, n, island[i].y, n);
    update_query(1, 1, n, island[i].y);
  }

  cout << pairSum << '\n';
}

void input() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> island[i].x >> island[i].y;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;
  for (cin >> t; t > 0; t--) {
    memset(segTree, 0, sizeof(segTree));

    input();
    solve();
  }

  return 0;
}
