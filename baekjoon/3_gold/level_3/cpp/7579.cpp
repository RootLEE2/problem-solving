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
#define MAX_N 102
#define MAX_COST 102
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

int N, M;
int m[MAX_N];
int c[MAX_N];
int sumCost;

int dp[MAX_N][MAX_N * MAX_COST];

void knapsack() {
  for (int i = 1; i <= N; i++) {
    for (int cost = 0; cost <= sumCost; cost++) {
      int &i_cost = dp[i][cost];
      if (c[i] <= cost)
        i_cost = max(i_cost, dp[i - 1][cost - c[i]] + m[i]);
      i_cost = max(i_cost, dp[i - 1][cost]);
    }
  }
}

void solve() {
  knapsack();

  for (int cost = 0; cost <= sumCost; cost++) {
    if (M <= dp[N][cost]) {
      cout << cost;
      break;
    }
  }
}

void input() {
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    int m_i; cin >> m_i;
    m[i] = m_i;
  }

  for (int i = 1; i <= N; i++) {
    int c_i; cin >> c_i;
    c[i] = c_i;
    sumCost += c_i;
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}