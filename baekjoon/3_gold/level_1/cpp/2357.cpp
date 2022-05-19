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

struct node {
  int minVal;
  int maxVal;
};

int N, M;
int numArr[MAX_N];
node segTree[4 * MAX_N];

node min_max_queries(int idx, int tl, int tr, int l, int r) {
  if (r < l) return {INF, 0};
  if (l == tl && r == tr) return segTree[idx];

  int tm = (tl + tr) / 2;
  node leftChild, rightChild;

  leftChild = min_max_queries(2 * idx, tl, tm, l, min(tm, r));
  rightChild = min_max_queries(2 * idx + 1, tm + 1, tr, max(tm + 1, l), r);

  return { min(leftChild.minVal, rightChild.minVal), max(leftChild.maxVal, rightChild.maxVal) };
}

void build_seg_tree(int idx, int tl, int tr) {
  if (tl == tr) {
    segTree[idx].maxVal = numArr[tl];
    segTree[idx].minVal = numArr[tl];
    return;
  }

  int tm = (tl + tr) / 2;

  build_seg_tree(2 * idx, tl, tm);
  build_seg_tree(2 * idx + 1, tm + 1, tr);

  segTree[idx].maxVal = max(segTree[2 * idx].maxVal, segTree[2 * idx + 1].maxVal);
  segTree[idx].minVal = min(segTree[2 * idx].minVal, segTree[2 * idx + 1].minVal);
}

void solve() {
  build_seg_tree(1, 1, N);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    node result = min_max_queries(1, 1, N, a, b);
    cout << result.minVal << ' ' << result.maxVal << '\n';
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
