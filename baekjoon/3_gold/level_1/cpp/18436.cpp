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

int segTree[1 << 18][2];  // int segTree[4 * MAX_N][2];

void update_query(int node, int tl, int tr, int idx, int val) {
  if (idx < tl || tr < idx) return;
  
  if (tl == tr) {
    int A_i = A[idx] & 1;
    int newA_i = val & 1;

    if (A_i != newA_i) {
      segTree[node][A_i]--;
      segTree[node][newA_i]++;
    }
    
    return;
  }

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_query(doubleNode, tl, tm, idx, val);
  update_query(doubleNode + 1, tm + 1, tr, idx, val);

  segTree[node][0] = segTree[doubleNode][0] + segTree[doubleNode + 1][0];
  segTree[node][1] = segTree[doubleNode][1] + segTree[doubleNode + 1][1];
}

int cnt_queries(int node, int tl, int tr, int l, int r, int flag) {
  if (r < l) return 0;
  if (tl == l && tr == r) return segTree[node][flag];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  int leftChild = cnt_queries(doubleNode, tl, tm, l, min(tm, r), flag);
  int rightChild = cnt_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r, flag);

  return leftChild + rightChild;
}

void build_seg_tree(int node, int tl, int tr) {
  if (tl == tr) {
    segTree[node][A[tl] & 1]++;
    return;
  }

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  build_seg_tree(doubleNode, tl, tm);
  build_seg_tree(doubleNode + 1, tm + 1, tr);

  segTree[node][0] = segTree[doubleNode][0] + segTree[doubleNode + 1][0];
  segTree[node][1] = segTree[doubleNode][1] + segTree[doubleNode + 1][1];
}

void solve() {
  build_seg_tree(1, 1, N);

  for (int m = 0; m < M; m++) {
    int type;
    cin >> type;

    if (type == 1) {
      int i, x;
      cin >> i >> x;

      update_query(1, 1, N, i, x);
      A[i] = x;
    } else {
      int l, r;
      cin >> l >> r;

      cout << cnt_queries(1, 1, N, l, r, type & 1) << '\n';
    }
  }
}

void input() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  cin >> M;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
