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

#define MAX_N 11
#define MAX_M 100005
#define MAX_NM 15
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
#define CALCUL_DIST(A, B) (sqrt(pow(A.first - B.first, 2) + pow(A.second - B.second, 2)))
#define COOR_TO_ARRAY(name, coor) name[coor.first][coor.second]

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
typedef struct bridge {
  two_num num_island;
  int cost;

  bool operator<(const bridge &o) const {
    return cost > o.cost;
  }
} bridge;

int N, M;
int map_info[MAX_NM][MAX_NM];

int cnt_island = 0;
priority_queue<bridge> bridge_list;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool check_coor_in_range(two_num __coor) {
  if (__coor.first < 1 || N < __coor.first || __coor.second < 1 || M < __coor.second) return false;
  return true;
}

void bfs(two_num start_coor) {
  queue<two_num> q;
  q.push(start_coor);

  cnt_island++;

  while (!q.empty()) {
    two_num coor = q.front();
    q.pop();

    COOR_TO_ARRAY(map_info, coor) = cnt_island;

    for (int i = 0; i < 4; i++) {
      two_num next_coor;
      next_coor.first = coor.first + dr[i];
      next_coor.second = coor.second + dc[i];

      if (!check_coor_in_range(next_coor)) continue;
      if (COOR_TO_ARRAY(map_info, next_coor) != -1) continue;

      q.push(next_coor);
    }
  }
}

void search_dist(two_num coor) {
  for (int i = 0; i < 4; i++) {
    two_num next_coor;
    next_coor.first = coor.first + dr[i];
    next_coor.second = coor.second + dc[i];

    bool flag = false;
    int cnt = -1;

    while (check_coor_in_range(next_coor)) {
      cnt++;
      if (COOR_TO_ARRAY(map_info, next_coor) == 0) {
        next_coor.first += dr[i];
        next_coor.second += dc[i];
        continue;
      }
      else if (COOR_TO_ARRAY(map_info, next_coor) == COOR_TO_ARRAY(map_info, coor)) break;
      else {
        flag = true;
        break;
      }
    }

    if (flag && 1 < cnt) {
      bridge_list.push({{COOR_TO_ARRAY(map_info, coor), COOR_TO_ARRAY(map_info, next_coor)}, cnt});
    }
  }
}

int kruskal() {
  int ret = 0;
  int linked_island_cnt = 0;

  while (linked_island_cnt < cnt_island - 1) {
    if (bridge_list.empty()) return -1;

    bridge bridge_info = bridge_list.top();
    bridge_list.pop();

    if (is_same_parent(bridge_info.num_island)) continue;

    union_set(bridge_info.num_island);
    ret += bridge_info.cost;
    linked_island_cnt++;
  }

  return ret;
}

void solve() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (map_info[i][j] == -1) bfs({ i, j });
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (map_info[i][j] != 0) search_dist({ i, j });
    }
  }

  init_parent(cnt_island);

  cout << kruskal();
}

void input() {
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> map_info[i][j];
      if (map_info[i][j] == 1) map_info[i][j] = -1;
    }
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}