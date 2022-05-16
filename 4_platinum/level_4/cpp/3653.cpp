/**
 * @ref https://imnotabear.tistory.com/497
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
#define MAX_N 100005
#define MAX_M 100005
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx

int n, m;

int segTree[1 << 19];  // int segTree[4 * (MAX_N + MAX_M)];
int dvdLoc[MAX_N];

int sum_queries(int node, int tl, int tr, int l, int r) {
  if (r < l) return 0;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  //int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  int leftChild = sum_queries(doubleNode, tl, tm, l, min(tm, r));
  int rightChild = sum_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  return leftChild + rightChild;
}

void update_query(int node, int tl, int tr, int idx, int delta) {
  if (idx < tl || tr < idx) return;
  
  segTree[node] += delta;

  if (tl == tr) return;

  int doubleNode = node << 1;  //int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_query(doubleNode, tl, tm, idx, delta);
  update_query(doubleNode + 1, tm + 1, tr, idx, delta);
}

void build_seg_tree(int node, int tl, int tr) {
  if (tl == tr) {
    if (tl <= n) {
      segTree[node] = 1;
    } else {
      segTree[node] = 0;
    }
    return;
  }

  int doubleNode = node << 1;  //int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  build_seg_tree(doubleNode, tl, tm);
  build_seg_tree(doubleNode + 1, tm + 1, tr);

  segTree[node] = segTree[doubleNode] + segTree[doubleNode + 1];
}

void solve() {
  for (int i = 1; i <= n; i++) {
    dvdLoc[i] = n - i + 1;
  }

  int nm = n + m;

  build_seg_tree(1, 1, nm);

  int dvdLastLoc = n;
  for (int i = 0; i < m; i++) {
    int movieNum;
    cin >> movieNum;

    int dvdCurLoc = dvdLoc[movieNum];

    cout << sum_queries(1, 1, nm, dvdCurLoc + 1, dvdLastLoc) << ' ';

    dvdLastLoc++;
    dvdLoc[movieNum] = dvdLastLoc;

    update_query(1, 1, nm, dvdCurLoc, -1);
    update_query(1, 1, nm, dvdLastLoc, 1);
  }
}

void input() {
  cin >> n >> m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int testCase;
  for (cin >> testCase; testCase > 0; testCase--) {
    input();
    solve();
    cout << '\n';
  }

  return 0;
}
