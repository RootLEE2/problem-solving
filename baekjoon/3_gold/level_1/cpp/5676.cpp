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

int N, K;
int X[MAX_N];

int segTree[1 << 18];  // int segTree[4 * MAX_N];

int positive_zero_negative(int val) {
  if (0 < val) return 1;
  else if (val == 0) return 0;
  else return -1;
}

int product_queries(int node, int tl, int tr, int l, int r) {
  if (r < l) return 1;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  int leftChild = product_queries(doubleNode, tl, tm, l, min(tm, r));
  int rightChild = product_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  return leftChild * rightChild;
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

  segTree[node] = segTree[doubleNode] * segTree[doubleNode + 1];
}

void build_seg_tree(int node, int tl, int tr) {
  if (tl == tr) {
    segTree[node] = X[tl];
    return;
  }

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  build_seg_tree(doubleNode, tl, tm);
  build_seg_tree(doubleNode + 1, tm + 1, tr);

  segTree[node] = segTree[doubleNode] * segTree[doubleNode + 1];
}

void solve() {
  build_seg_tree(1, 1, N);

  for (int i = 0; i < K; i++) {
    char a;
    int b, c;
    cin >> a >> b >> c;

    if (a == 'C') {
      int temp = positive_zero_negative(c);

      if (X[b] == temp) continue;
      
      update_query(1, 1, N, b, temp);
      X[b] = temp;
    }
    else if (a == 'P') {
      int temp = product_queries(1, 1, N, b, c);
      char result;

      if (0 < temp) result = '+';
      else if (temp == 0) result = '0';
      else result = '-';

      cout << result;
    }
  }
  cout << '\n';
}

void input() {
  for (int i = 1; i <= N; i++) {
    int temp;
    cin >> temp;

    X[i] = positive_zero_negative(temp);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while (cin >> N >> K) {
    input();
    solve();
  }

  return 0;
}
