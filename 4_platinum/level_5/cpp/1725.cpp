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

int N;
int height[MAX_N];

int segTree[4 * MAX_N];

int min_queries(int idx, int tl, int tr, int l, int r) {
  if (r < l) return -1;
  if (tl == l && tr == r) return segTree[idx];

  int tm = (tl + tr) / 2;

  int leftChild = min_queries(2 * idx, tl, tm, l, min(tm, r));
  int rightChild = min_queries(2 * idx + 1, tm + 1, tr, max(tm + 1, l), r);

  if (leftChild == -1) return rightChild;
  else if (rightChild == -1) return leftChild;

  return (height[leftChild] < height[rightChild]) ? leftChild : rightChild;
}

ll find_max_area(int tl, int tr) {
  if (tl == tr) return height[tl];
  
  int minIdx = min_queries(1, 1, N, tl, tr);

  if (minIdx == -1) return 0;

  ll result = (ll)(tr - tl + 1) * height[minIdx];

  result = max(result, find_max_area(tl, minIdx - 1));
  result = max(result, find_max_area(minIdx + 1, tr));

  return result;
}

int build_seg_tree(int idx, int tl, int tr) {
  if (tl == tr) {
    return segTree[idx] = tl;
  }

  int tm = (tl + tr) / 2;

  int leftChild = build_seg_tree(2 * idx, tl, tm);
  int rightChild = build_seg_tree(2 * idx + 1, tm + 1, tr);

  return segTree[idx] = (height[leftChild] < height[rightChild]) ? leftChild : rightChild;
}

void solve() {
  build_seg_tree(1, 1, N);

  cout << find_max_area(1, N);
}

void input() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> height[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
