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

int N, M;
int numArr[MAX_N];

int segTree[1 << 18];  // int segTree[4 * MAX_N];

int min_queries(int node, int tl, int tr, int l, int r) {
  if (r < l) return INF;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  int leftChild = min_queries(doubleNode, tl, tm, l, min(r, tm));
  int rightChild = min_queries(doubleNode + 1, tm + 1, tr, max(l, tm + 1), r);

  return min(leftChild, rightChild);
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

  segTree[node] = min(segTree[doubleNode], segTree[doubleNode + 1]);
}

void solve() {
  build_seg_tree(1, 1, N);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    cout << min_queries(1, 1, N, a, b) << '\n';
  }
}

void input() {
  cin >> N >> M;

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
