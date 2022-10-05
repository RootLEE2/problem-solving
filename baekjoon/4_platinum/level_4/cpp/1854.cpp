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

#define MAX_N 1003
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

/* struct */
typedef struct two_nums {
  int first, second;
} two_nums;

/* main */
#define to path_value.first
#define cost path_value.second

typedef struct path {
  two_nums path_value;

  bool operator<(const path &o) const {
    return cost > o.cost;
  }
} path;

int n, m, k;
vector<path> adj_list[MAX_N];

priority_queue<int> heap_kth_path[MAX_N];

void kth_path_dijkstra() {
  priority_queue<path> pq;
  pq.push({ { 1, 0 } });
  heap_kth_path[1].push(0);

  while (!pq.empty()) {
    path cur_city = pq.top();
    pq.pop();

    for (path nxt_city : adj_list[cur_city.to]) {
      int nxt_city_num = nxt_city.to;
      int nxt_cost = cur_city.cost + nxt_city.cost;

      if (heap_kth_path[nxt_city_num].size() < k) {
        heap_kth_path[nxt_city_num].push(nxt_cost);
        pq.push({ { nxt_city_num, nxt_cost } });
      }
      else if (nxt_cost < heap_kth_path[nxt_city_num].top()){
        heap_kth_path[nxt_city_num].pop();
        heap_kth_path[nxt_city_num].push(nxt_cost);
        pq.push({ { nxt_city_num, nxt_cost } });
      }
    }
  }
}

void solve() {
  kth_path_dijkstra();

  for (int i = 1; i <= n; i++) {
    if (heap_kth_path[i].size() < k) cout << "-1\n";
    else cout << heap_kth_path[i].top() << '\n';
  }
}

void input() {
  cin >> n >> m >> k;

  for (int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    adj_list[a].push_back({ { b, c } });
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}