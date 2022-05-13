#include <iostream>
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
typedef long long ll;

int n;
int heightArr[MAX_N];

// log2(100000) == 16.609
int segTree[1 << 18];  // int segTree[4 * MAX_N];

int min_queries(int node, int tl, int tr, int l, int r) {
  if (r < l) return -1;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  int leftChild = min_queries(doubleNode, tl, tm, l, min(tm, r));
  int rightChild = min_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  if (leftChild == -1) return rightChild;
  else if (rightChild == -1) return leftChild;

  return (heightArr[leftChild] < heightArr[rightChild]) ? leftChild : rightChild;
}

ll find_max_area(int tl, int tr) {
  if (tl == tr) return heightArr[tl];
  
  int minNode = min_queries(1, 1, n, tl, tr);

  if (minNode == -1) return 0;

  ll result = (ll)(tr - tl + 1) * heightArr[minNode];

  result = max(result, find_max_area(tl, minNode - 1));
  result = max(result, find_max_area(minNode + 1, tr));

  return result;
}

int build_seg_tree(int node, int tl, int tr) {
  if (tl == tr) {
    return segTree[node] = tl;
  }

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  int leftChild = build_seg_tree(doubleNode, tl, tm);
  int rightChild = build_seg_tree(doubleNode + 1, tm + 1, tr);

  return segTree[node] = (heightArr[leftChild] < heightArr[rightChild]) ? leftChild : rightChild;
}

void solve() {
  build_seg_tree(1, 1, n);

  cout << find_max_area(1, n) << '\n';
}

void input() {
  for (int i = 1; i <= n; i++) {
    cin >> heightArr[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while (true) {
    cin >> n;
    if (n == 0) break;

    input();
    solve();
  }

  return 0;
}
