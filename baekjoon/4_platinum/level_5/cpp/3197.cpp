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
#define COOR_TO_ARRAY(name, coor) name[coor.r][coor.c]

typedef long long ll;

typedef struct two_num {
  int first, second;
} two_num;

typedef struct point_coor {
  int r, c;
} point_coor;

int R, C;
int space_map[MAX_RC][MAX_RC];

int area_num = 0;
bool visited[MAX_RC][MAX_RC];
int parent[(SQUARE(MAX_RC) >> 1) + 1];
vector<int> swan_area;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

/* union */
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

/* bfs */
bool check_coor_in_range(point_coor __coor) {
  if (__coor.r < 1 || R < __coor.r || __coor.c < 1 || C < __coor.c) return false;
  return true;
}

int calcul_days_swans_meet() {
  int days = 0;

  if (is_same_parent({ swan_area[0], swan_area[1] })) return days;

  queue<pair<point_coor, int>> q;

  for (int r = 1; r <= R; r++) {
    for (int c = 1; c <= C; c++) {
      if (space_map[r][c] == -1) continue;

      for (int i = 0; i < 4; i++) {
        point_coor next_coor;
        next_coor.r = r + dr[i];
        next_coor.c = c + dc[i];

        if (!check_coor_in_range(next_coor)) continue;
        if (COOR_TO_ARRAY(visited, next_coor)) continue;

        COOR_TO_ARRAY(visited, next_coor) = true;
        q.push(make_pair(next_coor, space_map[r][c]));
      }
    }
  }

  while (!q.empty()) {
    days++;

    int queue_size = q.size();
    while (queue_size--) {
      point_coor coor = q.front().first;
      COOR_TO_ARRAY(space_map, coor) = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
        point_coor next_coor;
        next_coor.r = coor.r + dr[i];
        next_coor.c = coor.c + dc[i];

        if (!check_coor_in_range(next_coor)) continue;

        if (COOR_TO_ARRAY(visited, next_coor)) {
          if (COOR_TO_ARRAY(space_map, next_coor) == -1) continue;

          if (is_same_parent({ COOR_TO_ARRAY(space_map, coor), COOR_TO_ARRAY(space_map, next_coor) })) continue;
          union_set({ COOR_TO_ARRAY(space_map, coor), COOR_TO_ARRAY(space_map, next_coor) });
        } else {
          COOR_TO_ARRAY(visited, next_coor) = true;
          q.push(make_pair(next_coor, COOR_TO_ARRAY(space_map, coor)));
        }
      }
    }

    if (is_same_parent({ swan_area[0], swan_area[1] })) return days;
  }

  return -1;
}

void area_check_bfs(point_coor __coor) {
  area_num++;

  COOR_TO_ARRAY(visited, __coor) = true;

  queue<point_coor> q;
  q.push(__coor);

  while (!q.empty()) {
    point_coor coor = q.front();
    q.pop();

    if (COOR_TO_ARRAY(space_map, coor) == -2) {
      swan_area.push_back(area_num);
    }
    COOR_TO_ARRAY(space_map, coor) = area_num;

    for (int i = 0; i < 4; i++) {
      point_coor next_coor;
      next_coor.r = coor.r + dr[i];
      next_coor.c = coor.c + dc[i];

      if (!check_coor_in_range(next_coor)) continue;
      if (COOR_TO_ARRAY(visited, next_coor) || COOR_TO_ARRAY(space_map, next_coor) == -1) continue;

      COOR_TO_ARRAY(visited, next_coor) = true;
      q.push(next_coor);
    }
  }
}

/* main */
void solve() {
  for (int r = 1; r <= R; r++) {
    for (int c = 1; c <= C; c++) {
      if (!visited[r][c] && space_map[r][c] != -1) {
        area_check_bfs({ r, c });
      }
    }
  }

  init_parent(area_num);

  cout << calcul_days_swans_meet();
}

void input() {
  cin >> R >> C;

  for (int r = 1; r <= R; r++) {
    memset(space_map[r], -1, sizeof(space_map[r]));
    for (int c = 1; c <= C; c++) {
      char space; cin >> space;
      if (space == 'X') continue;
      else if (space == 'L') space_map[r][c] = -2;
      else space_map[r][c] = 0;
    }
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}