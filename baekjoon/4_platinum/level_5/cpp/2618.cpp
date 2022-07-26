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
#define MAX_W 1003
#define MAX_LENGTH 102
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD 1000000007
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

struct coor {
  int r, c;
};

int N, W;
coor cases[MAX_W];

int dp[MAX_W][MAX_W];

void find_moving_police_car(int lastOfPoliceCar1, int lastOfPoliceCar2) {
  if (lastOfPoliceCar1 == W || lastOfPoliceCar2 == W) return;

  int nextCase = max(lastOfPoliceCar1, lastOfPoliceCar2) + 1;

  int distIfPoliceCar1 =
    (lastOfPoliceCar1 == 0) ?
    abs(cases[nextCase].r - 1) + abs(cases[nextCase].c - 1) :
    abs(cases[nextCase].r - cases[lastOfPoliceCar1].r) + abs(cases[nextCase].c - cases[lastOfPoliceCar1].c);
  distIfPoliceCar1 += dp[nextCase][lastOfPoliceCar2];

  int distIfPoliceCar2 =
    (lastOfPoliceCar2 == 0) ?
    abs(cases[nextCase].r - N) + abs(cases[nextCase].c - N) :
    abs(cases[nextCase].r - cases[lastOfPoliceCar2].r) + abs(cases[nextCase].c - cases[lastOfPoliceCar2].c);
  distIfPoliceCar2 += dp[lastOfPoliceCar1][nextCase];

  if (distIfPoliceCar1 < distIfPoliceCar2) {
    cout << "1\n";
    find_moving_police_car(nextCase, lastOfPoliceCar2);
  } else {
    cout << "2\n";
    find_moving_police_car(lastOfPoliceCar1, nextCase);
  }
}

int find_min_distance(int lastOfPoliceCar1, int lastOfPoliceCar2) {
  if (lastOfPoliceCar1 == W || lastOfPoliceCar2 == W) return 0;

  int &ret = dp[lastOfPoliceCar1][lastOfPoliceCar2];

  if (ret != -1) return ret;

  int nextCase = max(lastOfPoliceCar1, lastOfPoliceCar2) + 1;

  int distIfPoliceCar1 =
    (lastOfPoliceCar1 == 0) ?
    abs(cases[nextCase].r - 1) + abs(cases[nextCase].c - 1) :
    abs(cases[nextCase].r - cases[lastOfPoliceCar1].r) + abs(cases[nextCase].c - cases[lastOfPoliceCar1].c);
  distIfPoliceCar1 += find_min_distance(nextCase, lastOfPoliceCar2);

  int distIfPoliceCar2 =
    (lastOfPoliceCar2 == 0) ?
    abs(cases[nextCase].r - N) + abs(cases[nextCase].c - N) :
    abs(cases[nextCase].r - cases[lastOfPoliceCar2].r) + abs(cases[nextCase].c - cases[lastOfPoliceCar2].c);
  distIfPoliceCar2 += find_min_distance(lastOfPoliceCar1, nextCase);

  return ret = min(distIfPoliceCar1, distIfPoliceCar2);
}

void solve() {
  memset(dp, -1, sizeof(dp));

  cout << find_min_distance(0, 0) << '\n';

  find_moving_police_car(0, 0);
}

void input() {
  cin >> N >> W;

  for (int i = 1; i <= W; i++) {
    int r_i, c_i; cin >> r_i >> c_i;

    cases[i].r = r_i;
    cases[i].c = c_i;
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}