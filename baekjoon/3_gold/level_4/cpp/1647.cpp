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
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define MAX_N 200005
#define MAX_M 100005
#define MAX_RC 1502
#define MAX_LENGTH 2503
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

#define SQUARE(x) ((x) * (x))
#define MOD(x) ((x) % 1000000007)

typedef long long ll;

/* union */
typedef struct two_num {
  int first, second;
} two_num;

int parent[MAX_N];

int __find_parent(int __x) {
  if (parent[__x] == __x) return __x;
  return parent[__x] = __find_parent(parent[__x]);
}

void init_parent(int __size) {
  for (int i = 1; i <= __size; i++) {
    parent[i] = i;
  }
}

bool is_same_parent(two_num __nums) {
  if (__find_parent(__nums.first) == __find_parent(__nums.second)) return true;
  return false;
}

void union_set(two_num __nums) {
  int frstParent = __find_parent(__nums.first);
  int scndParent = __find_parent(__nums.second);

  parent[frstParent] = scndParent;
}

/* main */
typedef struct road {
  two_num num_houses;
  int cost;

  bool operator<(const road &o) const {
    return cost > o.cost;
  }
} road;

int N, M;
priority_queue<road> road_list;

int kruskal() {
  int ret = 0;
  int cnt_road = 0;

  while (cnt_road < N - 2) {
    road road_info = road_list.top();
    road_list.pop();

    if (is_same_parent(road_info.num_houses)) continue;

    union_set(road_info.num_houses);
    ret += road_info.cost;
    cnt_road++;
  }

  return ret;
}

void solve() {
  init_parent(N);

  cout << kruskal();
}

void input() {
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int A, B, C; cin >> A >> B >> C;
    road_list.push({ {A, B}, C });
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}