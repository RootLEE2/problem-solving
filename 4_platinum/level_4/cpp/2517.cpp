/**
 * @ref https://jaimemin.tistory.com/1476
 * 
 */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 500005
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
typedef long long ll;

struct runner {
  int ranking;
  int ability;
};

bool compare_by_ranking(runner a, runner b) {
  return a.ranking < b.ranking;
}

bool compare_by_ability(runner a, runner b) {
  return a.ability < b.ability;
}

int N;
runner runnerArr[MAX_N];

// log2(500000) == 18.931xxx
int segTree[1 << 20];  // int segTree[4 * MAX_N];

void update_query(int node, int tl, int tr, int idx) {
  if (idx < tl || tr < idx) return;

  segTree[node]++;

  if (tl == tr) return;

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_query(doubleNode, tl, tm, idx);
  update_query(doubleNode + 1, tm + 1, tr, idx);
}

int better_ability_queries(int node, int tl, int tr, int l, int r) {
  if (r < l) return 0;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  // int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  int leftChild = better_ability_queries(doubleNode, tl, tm, l, min(r, tm));
  int rightChild = better_ability_queries(doubleNode + 1, tm + 1, tr, max(l, tm + 1), r);

  return leftChild + rightChild;
}

void solve() {
  sort(runnerArr, runnerArr + N, compare_by_ability);

  for (int i = 0; i < N; i++) {
    runnerArr[i].ability = i + 1;
  }

  sort(runnerArr, runnerArr + N, compare_by_ranking);

  for (int i = 0; i < N; i++) {
    int numOfCanOutrun = better_ability_queries(1, 1, N, 1, runnerArr[i].ability);
    cout << runnerArr[i].ranking - numOfCanOutrun << '\n';
    
    update_query(1, 1, N, runnerArr[i].ability);
  }
}

void input() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    runnerArr[i].ranking = i + 1;
    cin >> runnerArr[i].ability;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
