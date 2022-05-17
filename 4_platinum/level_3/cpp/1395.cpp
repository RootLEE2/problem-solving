/**
 * @ref https://www.acmicpc.net/blog/view/26
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
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx

int N, M;

int segTree[1 << 18];  // int segTree[4 * MAX_N];
int lazyTree[1 << 18];  // int lazyTree[4 * MAX_N];

void lazy_propagation(int node, int tl, int tr) {
  segTree[node] = (tr - tl + 1) - segTree[node];

  if (tl != tr) {
    int doubleNode = node << 1;  // int doubleNode = 2 * node;

    lazyTree[doubleNode] += 1;
    lazyTree[doubleNode + 1] += 1;
  }
}

void lazy_update(int node, int tl, int tr) {
  // & 연산자보다 == 연산자의 우선순위가 더 높으므로 ( ) 반드시 필요. 
  if ((lazyTree[node] & 1) == 0) return;  // if (lazyTree[node] % 2 == 0) return;

  lazy_propagation(node, tl, tr);

  lazyTree[node] = 0;
}

int sum_queries(int node, int tl, int tr, int l, int r) {
  lazy_update(node, tl, tr);

  if (r < l) return 0;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  int leftChild = sum_queries(doubleNode, tl, tm, l, min(tm, r));
  int rightChild = sum_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  return leftChild + rightChild;
}

void update_queries(int node, int tl, int tr, int l, int r) {
  lazy_update(node, tl, tr);

  if (r < l) return;
  if (tl == l && tr == r) {
    lazy_propagation(node, tl, tr);
    return;
  }

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_queries(doubleNode, tl, tm, l, min(tm, r));
  update_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  segTree[node] = segTree[doubleNode] + segTree[doubleNode + 1];
}

void solve() {
  for (int i = 0; i < M; i++) {
    int O, S, T;
    cin >> O >> S >> T;

    if (O == 0) {
      update_queries(1, 1, N, S, T);
    } else if (O == 1) {
      cout << sum_queries(1, 1, N, S, T) << '\n';
    }
  }
}

void input() {
  cin >> N >> M;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
