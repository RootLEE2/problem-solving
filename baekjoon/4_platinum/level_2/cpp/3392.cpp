#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 10004
#define MAX_COOR 30000
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

struct two_y {
  int y1, y2;
};

struct element {
  int x;
  two_y y;
  int end;

  bool operator<(const element& o) const {
    return x < o.x;
  }
};

int N;
vector<element> mapInfo;

int segTree[1 << 16];  // int segTree[4 * MAX_COOR];
int cntTree[1 << 16];  // int cntTree[4 * MAX_COOR];

void update_query(int node, int tl, int tr, int l, int r, int val) {
  if (r < l) return;
  
  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  if (tl == l && tr == r) {
    cntTree[node] += val;
  } else {
    update_query(doubleNode, tl, tm, l, min(tm, r), val);
    update_query(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r, val);
  }

  if (cntTree[node] != 0) {
    segTree[node] = tr - tl + 1;
  } else {
    if (tl == tr) segTree[node] = 0;
    else segTree[node] = segTree[doubleNode] + segTree[doubleNode + 1];
  }
}

void solve() {
  sort(mapInfo.begin(), mapInfo.end());

  int ans = 0;

  update_query(1, 0, MAX_COOR, mapInfo[0].y.y1, mapInfo[0].y.y2, mapInfo[0].end);

  for (int i = 1; i < mapInfo.size(); i++) {
    ans += segTree[1] * (mapInfo[i].x - mapInfo[i - 1].x);
    update_query(1, 0, MAX_COOR, mapInfo[i].y.y1, mapInfo[i].y.y2, mapInfo[i].end);
  }

  cout << ans;
}

void input() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    mapInfo.push_back({ x1, { y1, y2 - 1 }, 1 });
    mapInfo.push_back({ x2, { y1, y2 - 1 }, -1 });
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
