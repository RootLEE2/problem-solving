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

ll sum_queries(ll idx, int tl, int tr, int l, int r) {
  if (r < l) return 0;
  if (l == tl && r == tr) return segTree[idx];

  int tm = (tl + tr) / 2;

  return sum_queries(2 * idx, tl, tm, l, min(r, tm)) + sum_queries(2 * idx + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update_query(ll idx, int tl, int tr, ll pos, ll newVal) {
  if (tl == tr) {
    segTree[idx] = newVal;
  } else {
    int tm = (tl + tr) / 2;

    if (pos <= tm)
      update_query(2 * idx, tl, tm, pos, newVal);
    else
      update_query(2 * idx + 1, tm + 1, tr, pos, newVal);

    segTree[idx] = segTree[2 * idx] + segTree[2 * idx + 1];
  }
}

void build_seg_tree(ll idx, int tl, int tr) {
  if (tl == tr) {
    segTree[idx] = numArr[tl];
  } else {
    int tm = (tl + tr) / 2;

    build_seg_tree(2 * idx, tl, tm);
    build_seg_tree(2 * idx + 1, tm + 1, tr);

    segTree[idx] = segTree[2 * idx] + segTree[2 * idx + 1];
  }
}

void solve() {
  build_seg_tree(1, 1, N);

  int sumOfMK = M + K;

  for (int i = 0; i < sumOfMK; i++) {
    ll a, b, c;
    cin >> a >> b >> c;

    if (a == 1) {
      update_query(1, 1, N, b, c);
    } else if (a == 2) {
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
