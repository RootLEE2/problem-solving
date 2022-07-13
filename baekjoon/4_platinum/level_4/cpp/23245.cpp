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
#define MAX_N 100005
#define MAX_VALUE 1000006
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

int n;
vector<pair<int, int>> seq;

int fenwickTree[MAX_VALUE];

int sum_query(int i) {
  int res = 0;
  while (0 < i) {
    res += fenwickTree[i];
    i -= (i & -i);
  }
  return res;
}

int sum_queries(int l, int r) {
  return sum_query(r) - sum_query(l - 1);
}

void update_query(int i) {
  while(i < MAX_VALUE) {
    fenwickTree[i] += 1;
    i += (i & -i);
  }
}

void solve() {
  sort(seq.begin(), seq.end());

  vector<int> tempSum(n);
  queue<int> updateQueue;

  for (int i = 0; i < n; i++) {
    tempSum[i] = sum_queries(0, seq[i].second);
    updateQueue.push(seq[i].second + 1);

    if (i == n - 1) break;
    if (seq[i].first != seq[i + 1].first) {
      while (!updateQueue.empty()) {
        update_query(updateQueue.front());
        updateQueue.pop();
      }
    }
  }

  memset(fenwickTree, 0, sizeof(fenwickTree));
  updateQueue = queue<int>();

  ll sum = 0;

  for (int i = n - 1; i >= 0; i--) {
    sum += (ll)tempSum[i] * sum_queries(seq[i].second + 2, MAX_VALUE - 1);
    updateQueue.push(seq[i].second + 1);

    if (i == 0) break;
    if (seq[i].first != seq[i - 1].first) {
      while (!updateQueue.empty()) {
        update_query(updateQueue.front());
        updateQueue.pop();
      }
    }
  }

  cout << sum;
}

void input() {
  cin >> n;

  vector<int> p;

  for (int i = 0; i < n; i++) {
    int p_i; cin >> p_i;
    p.push_back(p_i);
  }

  for (int i = 0; i < n; i++) {
    int q_i; cin >> q_i;

    seq.push_back(make_pair(p[i], q_i));
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}