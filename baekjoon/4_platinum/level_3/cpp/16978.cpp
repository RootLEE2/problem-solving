#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_NM 100005
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

struct query {
  int num;
  int idx;
  int type;
  int i, v, j;

  bool operator<(const query& o) const {
    if (num == o.num) return type < o.type;
    return num < o.num;
  }
};

int N, M;
vector<query> queryList;

int numOfQuery1 = 1;
int numOfQuery2;

ll segTree[1 << 18];  // ll segTree[4 * MAX_NM];

ll sum_queries(int node, int tl, int tr, int l, int r) {
  if (r < l) return 0;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  ll leftChild = sum_queries(doubleNode, tl, tm, l, min(tm, r));
  ll rightChild = sum_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  return leftChild + rightChild;
}

void update_query(int node, int tl, int tr, int idx, int val) {
  if (idx < tl || tr < idx) return;
  if (tl == tr) {
    segTree[node] = val;
    return;
  }

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_query(doubleNode, tl, tm, idx, val);
  update_query(doubleNode + 1, tm + 1, tr, idx, val);

  segTree[node] = segTree[doubleNode] + segTree[doubleNode + 1];
}

void solve() {
  sort(queryList.begin(), queryList.end());

  vector<ll> sum(numOfQuery2);

  for (query q : queryList) {
    int type = q.type;

    if (type == 1) {
      update_query(1, 1, N, q.i, q.v);
    }
    else if (type == 2) {
      sum[q.idx] = sum_queries(1, 1, N, q.i, q.j);
    }
  }

  for (ll s : sum) {
    cout << s << '\n';
  }
}

void input() {
  cin >> N;
  
  for (int i = 1; i <= N; i++) {
    int A_i;
    cin >> A_i;

    update_query(1, 1, N, i, A_i);
  }

  cin >> M;

  for (int m = 0; m < M; m++) {
    int t;
    cin >> t;

    query temp;
    temp.type = t;

    if (t == 1) {
      temp.num = numOfQuery1++;
      cin >> temp.i >> temp.v;
    }
    else if (t == 2) {
      temp.idx = numOfQuery2++;
      cin >> temp.num >> temp.i >> temp.j;
    }

    queryList.push_back(temp);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
