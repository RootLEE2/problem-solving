/**
 * This use segment tree.
 * But if want to use merge-sort,
 * 
 * @ref https://www.geeksforgeeks.org/counting-inversions/
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
#define MAX_N 500005
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

struct element {
  int idx;
  int value;

  bool operator<(const element& o) const {
    if (value == o.value)  // 해당 조건문 중요. 없을 시 틀림. 
      return idx < o.idx;
    
    return value < o.value;
  }
};

int N;
element numArr[MAX_N];

int segTree[1 << 21];  // int segTree[4 * MAX_N];

void update_query(int node, int tl, int tr, int idx) {
  if (idx < tl || tr < idx) return;

  segTree[node]++;

  if (tl == tr) return;

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_query(doubleNode, tl, tm, idx);
  update_query(doubleNode + 1, tm + 1, tr, idx);
}

int sum_queries(int node, int tl, int tr, int l, int r) {
  if (r < l) return 0;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  int leftChild = sum_queries(doubleNode, tl, tm, l, min(tm, r));
  int rightChild = sum_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  return leftChild + rightChild;
}

void solve() {
  sort(numArr + 1, numArr + N + 1);

  ll cnt = 0;
  for (int i = 1; i <= N; i++) {
    cnt += (ll)sum_queries(1, 1, N, numArr[i].idx + 1, N);
    update_query(1, 1, N, numArr[i].idx);
  }

  cout << cnt;
}

void input() {
  cin >> N;
  
  for (int i = 1; i <= N; i++) {
    numArr[i].idx = i;
    cin >> numArr[i].value;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
