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
#define MAX_K 1000000000
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

int N, M, K;

ll dp[MAX_N][MAX_N];

void cout_func(char txt, int &cnt) {
  cout << txt;
  cnt--;
}

void make_combination() {
  const int maxNM = max(N, M);

  for (int i = 1; i <= maxNM; i++) {
    dp[i][0] = dp[0][i] = 1;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      if (MAX_K < dp[i][j]) dp[i][j] = MAX_K;
    }
  }
}

void solve() {
  make_combination();

  if (dp[N][M] < K) {
    cout << -1;
    return;
  }

  int NM = N + M;
  int aCnt = N;
  int zCnt = M;

  for (int i = 0; i < NM; i++) {
    if (aCnt == 0) {
      cout_func('z', zCnt);
      continue;
    }
    if (zCnt == 0) {
      cout_func('a', aCnt);
      continue;
    }

    int aSome = dp[aCnt - 1][zCnt];
    int zSome = dp[aCnt][zCnt - 1];

    if (K <= aSome) {
      cout_func('a', aCnt);
    } else {
      cout_func('z', zCnt);
      K -= aSome;
    }
  }
}

void input() {
  cin >> N >> M >> K;
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}