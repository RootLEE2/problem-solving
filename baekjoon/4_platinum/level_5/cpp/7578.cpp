#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 500005
#define MAX_CODE 1000006
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
typedef long long ll;

int N;
int A[MAX_N];
int B[MAX_CODE];

// log2(500000) == 18.931
int segTree[1 << 20];  // int segTree[4 * MAX_N];

ll sum_queries(int node, int tl, int tr, int l, int r) {
  if (r < l) return 0;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  int leftChild = sum_queries(doubleNode, tl, tm, l, min(tm, r));
  int rightChild = sum_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  return leftChild + rightChild;
}

void update_query(int node, int tl, int tr, int idx) {
  if (idx < tl || tr < idx) return;
  
  segTree[node]++;
  
  if (tl == tr) return;
  
  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_query(doubleNode, tl, tm, idx);
  update_query(doubleNode + 1, tm + 1, tr, idx);
}

void solve() {
  ll ans = 0;
  
  for (int i = 1; i <= N; i++) {
    int bIdx = B[A[i]];
    ans += sum_queries(1, 1, N, bIdx, N);
    update_query(1, 1, N, bIdx);
  }
  
  cout << ans;
}

void input() {
  cin >> N;
  
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  
  for (int i = 1; i <= N; i++) {
    int bCode;
    cin >> bCode;
    
    B[bCode] = i;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
