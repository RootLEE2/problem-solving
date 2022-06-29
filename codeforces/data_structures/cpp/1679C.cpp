#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <math.h>
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

int n, q;

int cntOnX[MAX_N];
int cntOnY[MAX_N];

int segTreeForX[1 << 18];
int segTreeForY[1 << 18];

int sum_queries(int *tree, int node, int tl, int tr, int l, int r) {
  if (r < l) return 0;
  if (tl == l && tr == r) return tree[node];

  int doubleNode = node << 1;
  int tm = (tl + tr) >> 1;

  int leftChild = sum_queries(tree, doubleNode, tl, tm, l, min(tm, r));
  int rightChild = sum_queries(tree, doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  return leftChild + rightChild;
}

void update_query(int *tree, int node, int tl, int tr, int idx, int delta) {
  if (idx < tl || tr < idx) return;

  tree[node] += delta;

  if (tl == tr) return;

  int doubleNode = node << 1;
  int tm = (tl + tr) >> 1;

  update_query(tree, doubleNode, tl, tm, idx, delta);
  update_query(tree, doubleNode + 1, tm + 1, tr, idx, delta);
}

void solve() {
  int t;
  cin >> t;

  if (t == 1) {
    int x, y;
    cin >> x >> y;

    cntOnX[x]++;
    if (cntOnX[x] == 1) {
      update_query(segTreeForX, 1, 1, n, x, 1);
    }

    cntOnY[y]++;
    if (cntOnY[y] == 1) {
      update_query(segTreeForY, 1, 1, n, y, 1);
    }
  } else if (t == 2) {
    int x, y;
    cin >> x >> y;

    cntOnX[x]--;
    if (cntOnX[x] == 0) {
      update_query(segTreeForX, 1, 1, n, x, -1);
    }

    cntOnY[y]--;
    if (cntOnY[y] == 0) {
      update_query(segTreeForY, 1, 1, n, y, -1);
    }
  } else if (t == 3) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (sum_queries(segTreeForX, 1, 1, n, x1, x2) == x2 - x1 + 1
      || sum_queries(segTreeForY, 1, 1, n, y1, y2) == y2 - y1 + 1) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}

void input() {
  cin >> n >> q;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  
  for (int Q = 0; Q < q; Q++) {
    solve();
  }

  return 0;
}
