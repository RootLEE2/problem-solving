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
#define MAX_N 16
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

int N;
int W[MAX_N][MAX_N];

int VISITED_ALL;

const int startCity = 0;
int dp[MAX_N][1 << MAX_N];

int tsp(int curCity, int visited) {
  if (visited == VISITED_ALL) {
    int toStartDist = W[curCity][startCity];

    if (toStartDist == 0) return INF;
    else return toStartDist;
  }

  int &curCost = dp[curCity][visited];

  if (curCost != -1) return curCost;
  curCost = INF;

  for (int i = 0; i < N; i++) {
    if ((visited & (1 << i)) != 0) continue;
    if (W[curCity][i] == 0) continue;

    int tspValue = tsp(i, visited | (1 << i));
    curCost = min(curCost, W[curCity][i] + tspValue);
  }

  return curCost;
}

void solve() {
  VISITED_ALL = (1 << N) - 1;
  memset(dp, -1, sizeof(dp));
  
  cout << tsp(0, 1);
}

void input() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int W_ij; cin >> W_ij;
      W[i][j] = W_ij;
    }
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}