#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX_N 22
#define MAX_LENGTH 100005
#define CENTER_COOR 50
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD(x) ((x) % 1000000007)
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

struct point {
  int r, c;

  bool operator==(const point &o) const {
    return (r == o.r && c == o.c);
  }
};

int N;

bool visited[2 * CENTER_COOR][2 * CENTER_COOR];

int dr[][3] = {
  { -1, 1, 1 },
  { -1, -1, 1 }
};
int dc[][3] = {
  { 0, 1, -1 },
  { -1, 1, 0 }
};

int dfs(point prev, point cur, int rest_move) {
  if (visited[cur.r][cur.c]) {
    if (rest_move == 0) return 1;
    else return 0;
  }
  if (rest_move <= 0) return 0;

  visited[cur.r][cur.c] = true;
  int move_type = cur.r & 1;

  int ret = 0;

  for (int i = 0; i < 3; i++) {
    point next = { cur.r + dr[move_type][i], cur.c + dc[move_type][i] };

    if (next == prev) continue;

    ret += dfs(cur, next, rest_move - 1);
  }

  visited[cur.r][cur.c] = false;

  return ret;
}

void solve() {
  visited[CENTER_COOR][CENTER_COOR] = true;

  if (N < 5)
    cout << 0;
  else
    cout << dfs({ CENTER_COOR, CENTER_COOR }, { CENTER_COOR - 1, CENTER_COOR }, N);
}

void input() {
  cin >> N;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}