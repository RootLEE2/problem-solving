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

#define MAX_N 100005
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
typedef struct two_num {
  int first, second;
} two_num;

typedef struct point {
  int num_planet;
  int coor_axis;

  bool operator<(const point &o) const {
    return coor_axis < o.coor_axis;
  }
} point;

typedef struct edge {
  two_num num_planets;
  int cost;

  bool operator<(const edge &o) const {
    return cost < o.cost;
  }
} edge;

int N;
vector<point> x_axis;
vector<point> y_axis;
vector<point> z_axis;

vector<edge> edge_list;
int parent[MAX_N];

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

/* graph */
void create_edge_list() {
  for (int i = 1; i < N; i++) {
    /* X-axis*/
    edge_list.push_back({
      { x_axis[i - 1].num_planet, x_axis[i].num_planet },
      x_axis[i].coor_axis - x_axis[i - 1].coor_axis
    });

    /* Y-axis*/
    edge_list.push_back({
      { y_axis[i - 1].num_planet, y_axis[i].num_planet },
      y_axis[i].coor_axis - y_axis[i - 1].coor_axis
    });

    /* Z-axis*/
    edge_list.push_back({
      { z_axis[i - 1].num_planet, z_axis[i].num_planet },
      z_axis[i].coor_axis - z_axis[i - 1].coor_axis
    });
  }
}

int minimum_spanning_tree() {
  int num_edges_should_linked = N - 1;
  int total_cost = 0;

  for (edge edge : edge_list) {
    if (is_same_parent(edge.num_planets)) continue;

    union_set(edge.num_planets);
    num_edges_should_linked--;
    total_cost += edge.cost;

    if (!num_edges_should_linked) break;
  }

  return total_cost;
}

/* main */
void solve() {
  sort(x_axis.begin(), x_axis.end());
  sort(y_axis.begin(), y_axis.end());
  sort(z_axis.begin(), z_axis.end());

  create_edge_list();

  sort(edge_list.begin(), edge_list.end());

  init_parent(N);
  cout << minimum_spanning_tree();
}

void input() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int x, y, z; cin >> x >> y >> z;
    x_axis.push_back({ i, x });
    y_axis.push_back({ i, y });
    z_axis.push_back({ i, z });
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}