#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 200005
#define MAX_COOR 200000 - 1
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
  int cnt;
  ll cost;
};

int N;
int tree[MAX_N];

element segTree[1 << 19];  // int segTree[4 * MAX_N];

element find_queries(int node, int tl, int tr, int l, int r) {
  if (r < l) return { 0, 0 };
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  element leftChild = find_queries(doubleNode, tl, tm, l, min(tm, r));
  element rightChild = find_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  return { leftChild.cnt + rightChild.cnt, leftChild.cost + rightChild.cost };
}

void update_query(int node, int tl, int tr, int idx) {
  if (idx < tl || tr < idx) return;

  segTree[node].cnt++;
  segTree[node].cost += idx;

  if (tl == tr) return;

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_query(doubleNode, tl, tm, idx);
  update_query(doubleNode + 1, tm + 1, tr, idx);
}

void solve() {
  update_query(1, 0, MAX_COOR, tree[1]);

  ll ans = 1;

  for (int i = 2; i <= N; i++) {
    element result = find_queries(1, 0, MAX_COOR, 0, tree[i] - 1);
    ll temp = (ll)result.cnt * tree[i] - result.cost;
    
    result = find_queries(1, 0, MAX_COOR, tree[i] + 1, MAX_COOR);
    temp += result.cost - (ll)result.cnt * tree[i];

    update_query(1, 0, MAX_COOR, tree[i]);

    temp = MOD(temp);
    ans = MOD(ans * temp);
  }

  cout << ans;
}

void input() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> tree[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
