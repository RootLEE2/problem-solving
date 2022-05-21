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
#define NUM_OF_CANDY 1000000
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

int n;

int segTree[1 << 21];  // int segTree[4 * NUM_OF_CANDY];

void update_query(int node, int tl, int tr, int idx, int delta) {
  if (idx < tl || tr < idx) return;

  segTree[node] += delta;

  if (tl == tr) return;

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_query(doubleNode, tl, tm, idx, delta);
  update_query(doubleNode + 1, tm + 1, tr, idx, delta);
}

int find_query(int node, int tl, int tr, int rank) {
  if (tl == tr) return tl;

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  if (rank <= segTree[doubleNode]) {
    return find_query(doubleNode , tl, tm, rank);
  } else {
    return find_query(doubleNode + 1, tm + 1, tr, rank - segTree[doubleNode]);
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    int A, B, C;
    cin >> A;

    if (A == 1) {
      cin >> B;

      int idx = find_query(1, 1, NUM_OF_CANDY, B);
      cout << idx << '\n';
      
      update_query(1, 1, NUM_OF_CANDY, idx, -1);
    } else if (A == 2) {
      cin >> B >> C;
      update_query(1, 1, NUM_OF_CANDY, B, C);
    }
  }
}

void input() {
  cin >> n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
