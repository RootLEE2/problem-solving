#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 250004
#define MAX_VAL 65535
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
int temperature[MAX_N];

int segTree[1 << 18];  // int segTree[4 * MAX_VAL];

int mid_query(int node, int tl, int tr, int idx) {
  if (tl == tr) return tl;

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  if (idx <= segTree[doubleNode]) {
    return mid_query(doubleNode, tl, tm, idx);
  } else {
    return mid_query(doubleNode + 1, tm + 1, tr, idx - segTree[doubleNode]);
  }
}

void update_query(int node, int tl, int tr, int idx, int delta) {
  if (idx < tl || tr < idx) return;

  segTree[node] += delta;

  if (tl == tr) return;

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_query(doubleNode, tl, tm, idx, delta);
  update_query(doubleNode + 1, tm + 1, tr, idx, delta);
}

void solve() {
  for (int i = 1; i < K; i++) {
    update_query(1, 0, MAX_VAL, temperature[i], 1);
  }

  ll midSum = 0;
  int idxOfMid = (K + 1) >> 1;  // idxOfMid = (K + 1) / 2;

  for (int i = K; i <= N; i++) {
    update_query(1, 0, MAX_VAL, temperature[i], 1);
    midSum += mid_query(1, 0, MAX_VAL, idxOfMid);
    update_query(1, 0, MAX_VAL, temperature[i - K + 1], -1);
  }

  cout << midSum;
}

void input() {
  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    cin >> temperature[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
