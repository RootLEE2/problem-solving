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
typedef struct two_double {
  double first, second;
} two_double;

typedef struct passage {
  two_num num_gods;
  double cost;

  bool operator<(const passage &o) const {
    return cost > o.cost;
  }
} passage;

int N, M;
two_double god_list[MAX_N];

int cnt_passage = 0;
priority_queue<passage> passage_list;

double kruskal() {
  double ret = 0;

  while (cnt_passage < N - 1) {
    passage passage_info = passage_list.top();
    passage_list.pop();

    if (is_same_parent(passage_info.num_gods)) continue;

    union_set(passage_info.num_gods);
    ret += passage_info.cost;
    cnt_passage++;
  }

  return ret;
}

void solve() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      passage_list.push({ {i, j}, CALCUL_DIST(god_list[i], god_list[j])});
    }
  }

  cout << fixed;
  cout.precision(2);
  cout << kruskal();
}

void input() {
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    cin >> god_list[i].first >> god_list[i].second;
  }
  
  init_parent(N);

  for (int i = 0; i < M; i++) {
    int A, B; cin >> A >> B;
    if (is_same_parent({ A, B })) continue;
    union_set({ A, B });
    cnt_passage++;
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}